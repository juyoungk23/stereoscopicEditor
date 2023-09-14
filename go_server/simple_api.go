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

var ctx = context.Background()
var firestoreClient *firestore.Client
var pubsubClient *pubsub.Client
var topic *pubsub.Topic
var mutex = &sync.Mutex{} // For thread-safety

func init() {
	var err error
	firestoreClient, err = firestore.NewClient(ctx, "stereoscopictest")
	if err != nil {
		log.Fatalf("Failed to create Firestore client: %v", err)
	}

	pubsubClient, err = pubsub.NewClient(ctx, "stereoscopictest")
	if err != nil {
		log.Fatalf("Failed to create Pub/Sub client: %v", err)
	}

	topic = pubsubClient.Topic("unity-topic")
}

func main() {
	http.HandleFunc("/handleTexts", handleTexts)
	http.HandleFunc("/handleAssets", handleAssets)
	http.HandleFunc("/ws", handleWebSocket)
	http.HandleFunc("/Load3DAsset", Load3DAsset)
	fmt.Println("Server is listening on port 8080...")
	log.Fatal(http.ListenAndServe(":8080", nil))
}

func enableCors(w *http.ResponseWriter) {
	(*w).Header().Set("Access-Control-Allow-Origin", "*")
	(*w).Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
	(*w).Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")
}

// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------- TEXTS ---------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------

func handleTextsGET(w http.ResponseWriter, r *http.Request) {
	var entries []TextEntry
	iter := firestoreClient.Collection("texts").Documents(ctx)
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
}

func handleTextsPOST(w http.ResponseWriter, r *http.Request) {
	var entry TextEntry
	err := json.NewDecoder(r.Body).Decode(&entry)
	if err != nil {
		fmt.Println("Error decoding JSON:", err)
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	}

	mutex.Lock()
	_, err = firestoreClient.Collection("texts").Doc(fmt.Sprint(entry.ID)).Set(ctx, entry)
	mutex.Unlock()
	if err != nil {
		fmt.Println("Firestore write error:", err)
		http.Error(w, "Firestore write error: "+err.Error(), http.StatusInternalServerError)
		return
	}
	// fmt.Println("Successfully written to Firestore")

	// Broadcast update to all WebSocket clients
	broadcastTextUpdates()
	publishTextUpdate("New update in Firestore")
	json.NewEncoder(w).Encode(entry)

}

func handleTextsDELETE(w http.ResponseWriter, r *http.Request) {
	id := r.URL.Query().Get("id")
	// fmt.Println("Received ID to delete:", id)

	if id == "" {
		fmt.Println("Received empty ID for deletion.")
		http.Error(w, "Missing ID", http.StatusBadRequest)
		return
	}

	mutex.Lock()
	_, err := firestoreClient.Collection("texts").Doc(id).Delete(ctx)
	mutex.Unlock()

	if err != nil {
		fmt.Println("Delete failed with error:", err)
	} else {
		// fmt.Println("Delete succeeded for ID:", id)
	}

	// Broadcast update to all WebSocket clients
	broadcastTextUpdates()

	// fmt.Println("Successfully deleted from Firestore")
	publishTextUpdate("Entry deleted in Firestore")
	return
}

// Function to handle text updates
func handleTexts(w http.ResponseWriter, r *http.Request) {
	enableCors(&w)

	if r.Method == "GET" {
		handleTextsGET(w, r)
	} else if r.Method == "POST" {
		handleTextsPOST(w, r)
	} else if r.Method == "DELETE" {
		handleTextsDELETE(w, r)
	} else {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func publishTextUpdate(message string) {
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

// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------- ASSETS ---------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------

func broadcastAssetInfo() {
	var asset FirestoreAssetInfo
	doc, err := firestoreClient.Collection("assets").Doc("singleAsset").Get(ctx)
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

	for wsClient := range websocketClients {
		if err := wsClient.WriteMessage(websocket.TextMessage, assetData); err != nil {
			log.Printf("WebSocket error: %v", err)
			wsClient.Close()
			delete(websocketClients, wsClient)
		}
	}
}

// Function to handle GET requests for assets
func handleAssetsGET(w http.ResponseWriter, r *http.Request) {
	var assets []FirestoreAssetInfo
	iter := firestoreClient.Collection("assets").Documents(ctx)
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
	_, err = firestoreClient.Collection("assets").Doc(asset.ID).Set(ctx, asset)
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

func Load3DAsset(w http.ResponseWriter, r *http.Request) {
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

	// Assume "wsClients" is your list of WebSocket clients
	for wsClient := range websocketClients {
		if err := wsClient.WriteMessage(websocket.TextMessage, assetData); err != nil {
			log.Printf("WebSocket error: %v", err)
			wsClient.Close()
			delete(websocketClients, wsClient)
		}
	}
}

// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------ WEBSOCKETS -------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------

var upgrader = websocket.Upgrader{
	ReadBufferSize:  1024,
	WriteBufferSize: 1024,
	CheckOrigin: func(r *http.Request) bool {
		return true // allow all connections by default
	},
}

// Active WebSocket connections
var websocketClients = make(map[*websocket.Conn]bool)

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
	websocketClients[conn] = true
	clientsMutex.Unlock()

	err = conn.WriteMessage(websocket.TextMessage, []byte("Welcome to the WebSocket server"))
	if err != nil {
		log.Println("Write error:", err)
		return
	}

	// Load all entries from Firestore and send them
	var entries []TextEntry
	iter := firestoreClient.Collection("texts").Documents(ctx)
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
		delete(websocketClients, conn)
		clientsMutex.Unlock()
	}()

	for {
		_, _, err := conn.ReadMessage()
		if err != nil {
			return
		}
	}
}

func broadcastTextUpdates() {
	// Fetch and send updated data to all WebSocket clients
	var entries []TextEntry
	iter := firestoreClient.Collection("texts").Documents(ctx)
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

	for wsClient := range websocketClients {
		if err := wsClient.WriteMessage(websocket.TextMessage, updateData); err != nil {
			log.Printf("WebSocket error: %v", err)
			wsClient.Close()
			delete(websocketClients, wsClient)
		}
	}
}
