package main

import (
	"cloud.google.com/go/firestore"
	"cloud.google.com/go/pubsub"
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"sync"
	"google.golang.org/api/iterator"
	"github.com/gorilla/websocket"
)

type TextEntry struct {
	ID    int     `json:"id"`
	Text  string  `json:"text"`
	X     float64 `json:"x"`
	Y     float64 `json:"y"`
	Depth float64 `json:"depth"`
}

var ctx = context.Background()
var client *firestore.Client
var pubsubClient *pubsub.Client
var topic *pubsub.Topic
var mutex = &sync.Mutex{} // For thread-safety

func init() {
	var err error
	client, err = firestore.NewClient(ctx, "stereoscopictest")
	if err != nil {
		log.Fatalf("Failed to create Firestore client: %v", err)
	}

	pubsubClient, err = pubsub.NewClient(ctx, "stereoscopictest")
	if err != nil {
		log.Fatalf("Failed to create Pub/Sub client: %v", err)
	}

	topic = pubsubClient.Topic("unity-topic")
}

var upgrader = websocket.Upgrader{
    ReadBufferSize:  1024,
    WriteBufferSize: 1024,
    CheckOrigin: func(r *http.Request) bool {
        return true // allow all connections by default
    },
}

// Active WebSocket connections
var clients = make(map[*websocket.Conn]bool)

// Mutex to protect the clients map
var clientsMutex = &sync.Mutex{}

func handleWebSocket(w http.ResponseWriter, r *http.Request) {
    conn, err := upgrader.Upgrade(w, r, nil)
    if err != nil {
        log.Println(err)
        return
    }
    defer conn.Close()

    // Register the new client
    clientsMutex.Lock()
    clients[conn] = true
    clientsMutex.Unlock()

    err = conn.WriteMessage(websocket.TextMessage, []byte("Welcome to the WebSocket server"))
    if err != nil {
        log.Println("Write error:", err)
        return
    }

	// Load all entries from Firestore and send them
    var entries []TextEntry
    iter := client.Collection("texts").Documents(ctx)
    for {
        doc, err := iter.Next()
        if err == iterator.Done {
            break
        }
        if err != nil {
            log.Println("Firestore read error:", err)
            return
        }

        var entry TextEntry
        doc.DataTo(&entry)
        entries = append(entries, entry)
    }
    
    initialData, err := json.Marshal(map[string]interface{}{"entries": entries})

    if err != nil {
        log.Println("Error marshalling initial data:", err)
        return
    }
    
    conn.WriteMessage(websocket.TextMessage, initialData)
    

    // Unregister client when the function returns
    defer func() {
        clientsMutex.Lock()
        delete(clients, conn)
        clientsMutex.Unlock()
    }()

    for {
        _, _, err := conn.ReadMessage()
        if err != nil {
            return
        }
    }
}

func broadcastUpdate() {
    // Fetch and send updated data to all WebSocket clients
    var entries []TextEntry
    iter := client.Collection("texts").Documents(ctx)
    for {
        doc, err := iter.Next()
        if err == iterator.Done {
            break
        }
        if err != nil {
            log.Println("Firestore read error:", err)
            return
        }

        var entry TextEntry
        doc.DataTo(&entry)
        entries = append(entries, entry)
    }
    
    updateData, err := json.Marshal(map[string]interface{}{"entries": entries})

    if err != nil {
        log.Println("Error marshalling update data:", err)
        return
    }

    for client := range clients {
        if err := client.WriteMessage(websocket.TextMessage, updateData); err != nil {
            log.Printf("WebSocket error: %v", err)
            client.Close()
            delete(clients, client)
        }
    }
}



func main() {
	http.HandleFunc("/handleUpdate", handleUpdate)
	http.HandleFunc("/ws", handleWebSocket)
	fmt.Println("Server is listening on port 8080...")
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func publishUpdate(message string) {
	result := topic.Publish(ctx, &pubsub.Message{
		Data: []byte(message),
	})
	
	id, err := result.Get(ctx)
	if err != nil {
		fmt.Println("Failed to publish: ", err)
		return
	}
	fmt.Println("Published message with ID:", id)
}

func handleUpdate(w http.ResponseWriter, r *http.Request) {
	fmt.Println("Handling request...")
	w.Header().Set("Access-Control-Allow-Origin", "*")
	w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE")
	w.Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")

	if r.Method == "OPTIONS" {
		return
	}

	if r.Method == "DELETE" {
		id := r.URL.Query().Get("id")
		fmt.Println("Received ID to delete:", id)
	
		if id == "" {
			fmt.Println("Received empty ID for deletion.")
			http.Error(w, "Missing ID", http.StatusBadRequest)
			return
		}
	
		mutex.Lock()
		_, err := client.Collection("texts").Doc(id).Delete(ctx)
		mutex.Unlock()
	
		if err != nil {
			fmt.Println("Delete failed with error:", err)
		} else {
			fmt.Println("Delete succeeded for ID:", id)
		}
	
		// Broadcast update to all WebSocket clients
		broadcastUpdate()
	
		fmt.Println("Successfully deleted from Firestore")
		publishUpdate("Entry deleted in Firestore")
		return
	}
	

	if r.Method == "POST" {
		var entry TextEntry
		err := json.NewDecoder(r.Body).Decode(&entry)
		if err != nil {
			fmt.Println("Error decoding JSON:", err)
			http.Error(w, err.Error(), http.StatusBadRequest)
			return
		}

		mutex.Lock()
		_, err = client.Collection("texts").Doc(fmt.Sprint(entry.ID)).Set(ctx, entry)
		mutex.Unlock()
		if err != nil {
			fmt.Println("Firestore write error:", err)
			http.Error(w, "Firestore write error: "+err.Error(), http.StatusInternalServerError)
			return
		}
		fmt.Println("Successfully written to Firestore")
		
		// Broadcast update to all WebSocket clients
		broadcastUpdate()
		publishUpdate("New update in Firestore")
		json.NewEncoder(w).Encode(entry)

	} else if r.Method == "GET" {
		var entries []TextEntry
		iter := client.Collection("texts").Documents(ctx)
		for {
			doc, err := iter.Next()
			if err == iterator.Done {
				break
			}
			if err != nil {
				fmt.Println("Firestore read error:", err)
				http.Error(w, "Firestore read error", http.StatusInternalServerError)
				return
			}

			var entry TextEntry
			doc.DataTo(&entry)
			entries = append(entries, entry)
		}
		fmt.Println("Successfully read from Firestore")
		json.NewEncoder(w).Encode(map[string][]TextEntry{"entries": entries})
	} else {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}
