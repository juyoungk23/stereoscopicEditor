package websockets

import (
	"encoding/json"
	"log"
	"net/http"
	"sync"

	"github.com/gorilla/websocket"
)

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

// HandleWebSocket manages new WebSocket connections
func HandleWebSocket(w http.ResponseWriter, r *http.Request) {
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

// BroadcastMessage sends a message to all connected WebSocket clients
func BroadcastMessage(messageType int, message []byte) {
	clientsMutex.Lock()
	defer clientsMutex.Unlock()

	for client := range clients {
		if err := client.WriteMessage(messageType, message); err != nil {
			log.Printf("WebSocket error: %v", err)
			client.Close()
			delete(clients, client)
		}
	}
}

// BroadcastJSON sends a JSON-encoded message to all connected WebSocket clients
func BroadcastJSON(v interface{}) {
	message, err := json.Marshal(v)
	if err != nil {
		log.Println("Error marshalling JSON:", err)
		return
	}
	BroadcastMessage(websocket.TextMessage, message)
}
