package main

import (
	"context"
	"encoding/json"
	"fmt"
	"log"
	"net/http"
	"sync"

	"cloud.google.com/go/firestore"
	"github.com/gorilla/websocket"
	"google.golang.org/api/iterator"
)

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
var client *firestore.Client
var mutex = &sync.Mutex{} // For thread-safety

func InitializeAssetManager() {
	var err error
	client, err = firestore.NewClient(ctx, "stereoscopictest")
	if err != nil {
		log.Fatalf("Failed to create Firestore client: %v", err)
	}
}

func BroadcastAssetInfo(clients map[*websocket.Conn]bool) {
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

func HandleAssetsGET(w http.ResponseWriter, r *http.Request) {
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

func HandleAssetsPOST(w http.ResponseWriter, r *http.Request, clients map[*websocket.Conn]bool) {
	var asset FirestoreAssetInfo
	err := json.NewDecoder(r.Body).Decode(&asset)
	if err != nil {
		fmt.Println("Error decoding JSON:", err)
		http.Error(w, err.Error(), http.StatusBadRequest)
		return
	} else {
		BroadcastAssetInfo(clients)
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

func HandleAssets(w http.ResponseWriter, r *http.Request, clients map[*websocket.Conn]bool) {
	enableCors(&w)

	if r.Method == "GET" {
		HandleAssetsGET(w, r)
	} else if r.Method == "POST" {
		HandleAssetsPOST(w, r, clients)
	} else {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
	}
}

func enableCors(w *http.ResponseWriter) {
	(*w).Header().Set("Access-Control-Allow-Origin", "*")
	(*w).Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS, PUT, DELETE")
	(*w).Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")
}
