package main

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"sync"

	"cloud.google.com/go/firestore"
	"cloud.google.com/go/pubsub"
	"github.com/gorilla/websocket"
	"google.golang.org/api/iterator"
)

type TextEntry struct {
	ID    int     `json:"id"`
	Text  string  `json:"text"`
	X     float64 `json:"x"`
	Y     float64 `json:"y"`
	Depth float64 `json:"depth"`
}

type AssetInfo struct {
	GcsLink       string `json:"gcsLink"`
	AssetName     string `json:"assetName"`
	AssetPosition struct {
		X float64 `json:"x"`
		Y float64 `json:"y"`
		Z float64 `json:"z"`
	} `json:"assetPosition"`
}

var ctx = context.Background()
var client *firestore.Client
var pubsubClient *pubsub.Client
var topic *pubsub.Topic
var mutex = &sync.Mutex{} // For thread-safety

// Add this new struct for storing AssetInfo in Firestore
type FirestoreAssetInfo struct {
	ID            string `firestore:"id,omitempty"`
	GcsLink       string `firestore:"gcsLink,omitempty"`
	AssetName     string `firestore:"assetName,omitempty"`
	AssetPosition struct {
		X float64 `firestore:"x,omitempty"`
		Y float64 `firestore:"y,omitempty"`
		Z float64 `firestore:"z,omitempty"`
	} `firestore:"assetPosition,omitempty"`
}

func broadcastAssetInfo() {
	var asset FirestoreAssetInfo
	doc, err := client.Collection("assets").Doc("singleAsset").Get(ctx)
	if err != nil {
		log.Println("Firestore read error:", err)
		return
	}
	doc.DataTo(&asset)
	assetData, err := json.Marshal(asset)
	if err != nil {
		log.Println("Error marshalling asset data:", err)
		return
	}

	for client := range clients {
		if err := client.WriteMessage(websocket.TextMessage, assetData); err != nil {
			log.Printf("WebSocket error: %v", err)
			client.Close()
			delete(clients, client)
		}
	}
}

// Function to handle GET requests for assets
func handleAssetsGET(w http.ResponseWriter, r *http.Request) {
	var assets []FirestoreAssetInfo
	iter := client.Collection("assets").Documents(ctx)
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

		var asset FirestoreAssetInfo
		doc.DataTo(&asset)
		assets = append(assets, asset)
	}
	json.NewEncoder(w).Encode(map[string][]FirestoreAssetInfo{"assets": assets})
}

// Function to handle POST requests for assets
func handleAssetsPOST(w http.ResponseWriter, r *http.Request) {
	var asset FirestoreAssetInfo
	err := json.NewDecoder(r.Body).Decode(&asset)
	if err != nil {
		fmt.Println("Error decoding JSON:", err)
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	} else {
		broadcastAssetInfo() // <-- Add this line
	}

	mutex.Lock()
	_, err = client.Collection("assets").Doc(asset.ID).Set(ctx, asset)
	mutex.Unlock()

	if err != nil {
		fmt.Println("Firestore write error:", err)
		http.Error(w, "Firestore write error: "+err.Error(), http.StatusInternalServerError)
		return
	}

	json.NewEncoder(w).Encode(asset)
}

// Function to handle assets
func handleAssets(w http.ResponseWriter, r *http.Request) {
	enableCors(&w)

	if r.Method == "GET" {
		handleAssetsGET(w, r)
	} else if r.Method == "POST" {
		handleAssetsPOST(w, r)
	} else {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

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
	http.HandleFunc("/handleAssets", handleAssets)
	http.HandleFunc("/ws", handleWebSocket)
	http.HandleFunc("/load3DAsset", load3DAsset)
	fmt.Println("Server is listening on port 8080...")
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func publishUpdate(message string) {
	result := topic.Publish(ctx, &pubsub.Message{
		Data: []byte(message),
	})

	// id, err := result.Get(ctx)
	_, err := result.Get(ctx)
	if err != nil {
		fmt.Println("Failed to publish: ", err)
		return
	}
	// fmt.Println("Published message with ID:", id)
}

func handleUpdate(w http.ResponseWriter, r *http.Request) {
	// fmt.Println("Handling request...")
	w.Header().Set("Access-Control-Allow-Origin", "*")
	w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE")
	w.Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")

	if r.Method == "OPTIONS" {
		return
	}

	if r.Method == "DELETE" {
		id := r.URL.Query().Get("id")
		// fmt.Println("Received ID to delete:", id)

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
			// fmt.Println("Delete succeeded for ID:", id)
		}

		// Broadcast update to all WebSocket clients
		broadcastUpdate()

		// fmt.Println("Successfully deleted from Firestore")
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
		// fmt.Println("Successfully written to Firestore")

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
		// fmt.Println("Successfully read from Firestore")
		json.NewEncoder(w).Encode(map[string][]TextEntry{"entries": entries})
	} else {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func enableCors(w *http.ResponseWriter) {
	(*w).Header().Set("Access-Control-Allow-Origin", "*")
	(*w).Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
	(*w).Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")
}

func load3DAsset(w http.ResponseWriter, r *http.Request) {
	enableCors(&w)
	if r.Method == "OPTIONS" {
		w.WriteHeader(http.StatusOK)
		return
	}
	var assetInfo AssetInfo
	err := json.NewDecoder(r.Body).Decode(&assetInfo)
	if err != nil {
		log.Println("Error decoding JSON:", err)
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	log.Println("Received asset info:", assetInfo)

	// Forward this information to Unity via WebSocket
	assetData, err := json.Marshal(assetInfo)
	if err != nil {
		log.Println("Error marshalling asset data:", err)
		return
	}

	log.Println("Sending asset info to WebSocket:", string(assetData))

	// Assume "clients" is your list of WebSocket clients
	for client := range clients {
		if err := client.WriteMessage(websocket.TextMessage, assetData); err != nil {
			log.Printf("WebSocket error: %v", err)
			client.Close()
			delete(clients, client)
		}
	}
}
