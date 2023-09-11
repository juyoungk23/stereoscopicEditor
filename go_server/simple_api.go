package main

import (
    "encoding/json"
    "fmt"
    "log"
    "net/http"
    "sync"
)

type TextEntry struct {
    ID   int     `json:"id"`
    Text string  `json:"text"`
    X    float64 `json:"x"`
    Y    float64 `json:"y"`
    Depth float64 `json:"depth"`
}

var latestEntries = make(map[int]TextEntry)
var mutex = &sync.Mutex{} // Add this for thread-safety

var latestPos = make(map[int]TextEntry)

func main() {
    http.HandleFunc("/updateText", handleTextUpdate)
    http.HandleFunc("/position", handlePosition) // Add this line
    fmt.Println("Server is listening on port 8080...")
    log.Fatal(http.ListenAndServe(":8080", nil))
}

func handleTextUpdate(w http.ResponseWriter, r *http.Request) {
    // Handle CORS headers
    w.Header().Set("Access-Control-Allow-Origin", "*")
    w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS")
    w.Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")

    fmt.Println("Debug: Received a request with method:", r.Method) // Debug line 1

    if r.Method == "OPTIONS" {
        return
    }
    if r.Method == "POST" {
        fmt.Println("Debug: About to decode payload")
        var pos TextEntry
        err := json.NewDecoder(r.Body).Decode(&pos)
        if err != nil {
                fmt.Println("Debug: Failed to decode JSON: ", err)
                http.Error(w, err.Error(), http.StatusBadRequest)
                return
        }
        mutex.Lock()
        fmt.Printf("Received position X: %f, Y: %f, Depth: %f\n", pos.X, pos.Y, pos.Depth)

        updatedPos := latestPos[pos.ID]
        updatedPos.Depth = pos.Depth  // Update the Depth here
        updatedPos.X = pos.X
        updatedPos.Y = pos.Y
        latestPos[pos.ID] = updatedPos
                                                                  fmt.Println("Updated latestEntries:", latestEntries)
        fmt.Println("Updated latestPos:", latestPos)

        mutex.Unlock()
        json.NewEncoder(w).Encode(pos)

        } else if r.Method == "GET" {
        mutex.Lock()
        entries := make([]TextEntry, 0, len(latestEntries))
        for id, entry := range latestEntries {
            // Here, we update the entry's position from the latestPos map before appending it to the entries slice
            if pos, exists := latestPos[id]; exists {
                entry.X = pos.X
                entry.Y = pos.Y
                entry.Depth = pos.Depth
            }
            entries = append(entries, entry)
        }
        mutex.Unlock()

        fmt.Println("Debug: latestEntries just before sending GET response:", latestEntries) // Debug line
        fmt.Println("Debug: latestPos just before sending GET response:", latestPos) // Debug line

        fmt.Println("Debug: Sending GET response:", entries)
        json.NewEncoder(w).Encode(map[string][]TextEntry{"texts": entries})
    } else {
        http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
    }
}

func handlePosition(w http.ResponseWriter, r *http.Request) {
    // Add these lines to handle CORS
    w.Header().Set("Access-Control-Allow-Origin", "*")
    w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS")
    w.Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")

    if r.Method == "OPTIONS" {
        return
    }

    if r.Method == "POST" {
        fmt.Println("Debug: About to decode payload")
        var pos TextEntry
        err := json.NewDecoder(r.Body).Decode(&pos)
        if err != nil {
            fmt.Println("Debug: Failed to decode JSON: ", err)
            http.Error(w, err.Error(), http.StatusBadRequest)
            return
        }
        mutex.Lock()
        fmt.Printf("Received position X: %f, Y: %f, Depth: %f\n", pos.X, pos.Y, pos.Depth)

        updatedPos := latestPos[pos.ID]
        updatedPos.Depth = pos.Depth
        updatedPos.X = pos.X
        updatedPos.Y = pos.Y
        latestPos[pos.ID] = updatedPos
        // Update latestEntries as well
        if existingEntry, exists := latestEntries[pos.ID]; exists { 
                existingEntry.X = pos.X
                existingEntry.Y = pos.Y
                existingEntry.Depth = pos.Depth
                latestEntries[pos.ID] = existingEntry
        } else {
                // Initialize a new entry if it doesn't exist yet
                latestEntries[pos.ID] = TextEntry{
                        ID:    pos.ID,
                        X:     pos.X,
                        Y:     pos.Y,
                        Depth: pos.Depth,
                        Text:  "", 
                }
        }

        fmt.Println("Updated latestEntries:", latestEntries)
        fmt.Println("Updated latestPos:", latestPos)

        mutex.Unlock()
        json.NewEncoder(w).Encode(pos)
    } else if r.Method == "GET" {
        mutex.Lock()
        positions := make([]TextEntry, 0, len(latestPos))
        for _, pos := range latestPos {
            positions = append(positions, pos)
        }
        mutex.Unlock()
        json.NewEncoder(w).Encode(map[string][]TextEntry{"positions": positions})
    } else {
        http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
    }
}