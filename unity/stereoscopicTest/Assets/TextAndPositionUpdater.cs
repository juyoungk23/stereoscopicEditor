using System.Collections.Generic;
using UnityEngine;
using TMPro;
using WebSocketSharp;
using System.Collections.Concurrent;

[System.Serializable]
public class TextEntry
{
    public int id;
    public string text;
    public float x;
    public float y;
    public float depth;
}

[System.Serializable]
public class TextResponse
{
    public List<TextEntry> entries;
}

public class TextAndPositionUpdater : MonoBehaviour
{
    public GameObject textPrefab;
    public Transform canvasTransform;
    private Dictionary<int, GameObject> textObjects = new Dictionary<int, GameObject>();
    private WebSocket ws;
    private ConcurrentQueue<TextResponse> messageQueue = new ConcurrentQueue<TextResponse>();

    void Start()
    {
        ws = new WebSocket("ws://35.215.89.200:8080/ws");

        ws.OnOpen += (sender, e) => { };
        ws.OnError += (sender, e) => { };
        ws.OnClose += (sender, e) => { };

        ws.OnMessage += (sender, e) =>
        {
            TextResponse response = JsonUtility.FromJson<TextResponse>(e.Data);
            if (response != null && response.entries != null)
            {
                messageQueue.Enqueue(response);
            }
        };

        ws.Connect();
    }

    void Update()
    {
        // Process messages in the main thread
        while (messageQueue.TryDequeue(out TextResponse response))
        {
            UpdateUI(response);
        }
    }

    void UpdateUI(TextResponse response)
    {
        List<int> processedIds = new List<int>();

        foreach (var entry in response.entries)
        {
            GameObject textObj;
            if (!textObjects.TryGetValue(entry.id, out textObj))
            {
                textObj = Instantiate(textPrefab, canvasTransform);
                textObjects[entry.id] = textObj;
            }

            RectTransform rectTransform = textObj.GetComponent<RectTransform>();
            rectTransform.anchoredPosition3D = new Vector3(entry.x, entry.y, entry.depth);

            TextMeshProUGUI textComponent = textObj.GetComponent<TextMeshProUGUI>();
            textComponent.text = entry.text;

            processedIds.Add(entry.id);
        }

        // Delete GameObjects not in the processed list
        List<int> keys = new List<int>(textObjects.Keys);
        foreach (int key in keys)
        {
            if (!processedIds.Contains(key))
            {
                Destroy(textObjects[key]);
                textObjects.Remove(key);
            }
        }
    }
}
