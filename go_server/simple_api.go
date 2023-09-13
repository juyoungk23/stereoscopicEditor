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

func handleWebSocket(w http.ResponseWriter, r *http.Request) {
    conn, err := upgrader.Upgrade(w, r, nil)
    if err != nil {
        log.Println(err)
        return
    }
    defer conn.Close()

    for {
        messageType, p, err := conn.ReadMessage()
        if err != nil {
            return
        }
        if err := conn.WriteMessage(messageType, p); err != nil {
            return
        }
    }
}

func main() {
	http.HandleFunc("/handleUpdate", handleUpdate)
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
		// Existing DELETE code...
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
