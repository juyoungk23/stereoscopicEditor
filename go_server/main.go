// main.go

package main

import (
	// ... other imports
	"net/http"

	"./assets"
	"./websockets"
)

func main() {
	http.HandleFunc("/load3DAsset", assets.Load3DAsset)
	http.HandleFunc("/ws", websockets.HandleWebSocket)
	// ... rest of the code
}
