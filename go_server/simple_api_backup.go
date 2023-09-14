package main

import (
	"cloud.google.com/go/firestore"
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"sync"
	"google.golang.org/api/iterator"
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
var mutex = &sync.Mutex{} // For thread-safety

func init() {
	var err error
	client, err = firestore.NewClient(ctx, "stereoscopictest")
	if err != nil {
		log.Fatalf("Failed to create client: %v", err)
	}
}

func main() {
	http.HandleFunc("/handleUpdate", handleUpdate)
	fmt.Println("Server is listening on port 8080...")
	log.Fatal(http.ListenAndServe(":8080", nil))
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
		if id == "" {
		  http.Error(w, "Missing ID", http.StatusBadRequest)
		  return
		}
	
		mutex.Lock()
		_, err := client.Collection("texts").Doc(id).Delete(ctx)
		mutex.Unlock()
	
		if err != nil {
		  log.Printf("Firestore delete error: %v", err)
		  http.Error(w, "Firestore delete error", http.StatusInternalServerError)
		  return
		}
	
		fmt.Fprintf(w, "Deleted %v", id)
		return
	}


	if r.Method == "POST" {
		fmt.Println("Handling POST request...")
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
		json.NewEncoder(w).Encode(entry)

	} else if r.Method == "GET" {
		fmt.Println("Handling GET request...")
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
