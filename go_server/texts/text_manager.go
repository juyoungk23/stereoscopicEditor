package texts

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"sync"

	"cloud.google.com/go/firestore"
	"github.com/yourusername/yourproject/websockets" // Replace with the actual import path
	"google.golang.org/api/iterator"
)

var ctx = context.Background()
var client *firestore.Client
var mutex = &sync.Mutex{} // For thread-safety

type TextEntry struct {
	ID    int     `json:"id"`
	Text  string  `json:"text"`
	X     float64 `json:"x"`
	Y     float64 `json:"y"`
	Depth float64 `json:"depth"`
}

func enableCors(w *http.ResponseWriter) {
	(*w).Header().Set("Access-Control-Allow-Origin", "*")
	(*w).Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
	(*w).Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")
}

// HandleTexts manages text-related HTTP requests
func HandleTexts(w http.ResponseWriter, r *http.Request) {
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

func handleTextsGET(w http.ResponseWriter, r *http.Request) {
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
	_, err = client.Collection("texts").Doc(fmt.Sprint(entry.ID)).Set(ctx, entry)
	mutex.Unlock()
	if err != nil {
		fmt.Println("Firestore write error:", err)
		http.Error(w, "Firestore write error: "+err.Error(), http.StatusInternalServerError)
		return
	}

	// Broadcast update to all WebSocket clients
	BroadcastUpdate()
	json.NewEncoder(w).Encode(entry)
}

func handleTextsDELETE(w http.ResponseWriter, r *http.Request) {
	id := r.URL.Query().Get("id")

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
		http.Error(w, "Firestore delete error: "+err.Error(), http.StatusInternalServerError)
		return
	}

	// Broadcast update to all WebSocket clients
	BroadcastUpdate()
}

// Initialize Firestore client for the texts package
func InitFirestoreClient(firestoreClient *firestore.Client) {
	client = firestoreClient
}

// BroadcastUpdate fetches and sends updated data to all WebSocket clients
func BroadcastUpdate() {
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

	websockets.BroadcastMessage(websocket.TextMessage, updateData)
}
