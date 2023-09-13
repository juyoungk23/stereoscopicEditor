package main

import (
    "encoding/json"
    "fmt"
    "log"
    "net/http"
    "sync"
)

type TextEntry struct {
    ID    int     `json:"id"`
    Text  string  `json:"text"`
    X     float64 `json:"x"`
    Y     float64 `json:"y"`
    Depth float64 `json:"depth"`
}

var latestEntries = make(map[int]TextEntry)
var mutex = &sync.Mutex{} // Add this for thread-safety

func main() {
    http.HandleFunc("/handleUpdate", handleUpdate) // Renamed endpoint
    fmt.Println("Server is listening on port 8080...")
    log.Fatal(http.ListenAndServe(":8080", nil))
}

func handleUpdate(w http.ResponseWriter, r *http.Request) {
    // Handle CORS headers
    w.Header().Set("Access-Control-Allow-Origin", "*")
    w.Header().Set("Access-Control-Allow-Methods", "POST, GET, OPTIONS")
    w.Header().Set("Access-Control-Allow-Headers", "Accept, Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization")

    if r.Method == "OPTIONS" {
        return
    }

    if r.Method == "POST" {
        var entry TextEntry
        err := json.NewDecoder(r.Body).Decode(&entry)
        if err != nil {
            fmt.Println("Debug: Failed to decode JSON: ", err)  // Debug line
            http.Error(w, err.Error(), http.StatusBadRequest)
            return
        }

        fmt.Printf("Debug: Received POST data: %+v\n", entry)  // Debug line

        mutex.Lock()
        // Update or Initialize a new entry
        existingEntry, exists := latestEntries[entry.ID]
        if exists {
            existingEntry.X = entry.X
            existingEntry.Y = entry.Y
            existingEntry.Depth = entry.Depth
            existingEntry.Text = entry.Text  // Update the Text field here
        } else {
            existingEntry = TextEntry{
                ID:    entry.ID,
                X:     entry.X,
                Y:     entry.Y,
                Depth: entry.Depth,
                Text:  entry.Text,  // Initialize the Text field here
            }
        }
        latestEntries[entry.ID] = existingEntry
        fmt.Printf("Debug: Updated latestEntries: %+v\n", latestEntries)
        mutex.Unlock()

        json.NewEncoder(w).Encode(existingEntry)
    } else if r.Method == "GET" {
        mutex.Lock()
        entries := make([]TextEntry, 0, len(latestEntries))
        for _, entry := range latestEntries {
            entries = append(entries, entry)
        }
        fmt.Printf("Debug: Sending GET response: %+v\n", entries)  // Debug line
        mutex.Unlock()
        json.NewEncoder(w).Encode(map[string][]TextEntry{"entries": entries})
    } else {
        http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
    }
}