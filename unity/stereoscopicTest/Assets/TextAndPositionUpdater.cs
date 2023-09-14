using System.Collections.Generic;
using UnityEngine;
using TMPro;
using WebSocketSharp;
using System.Collections.Concurrent;
using UnityEngine.Networking;
using System.Collections;

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

[System.Serializable]
public class AssetInfo
{
    public string gcsLink;
    public string assetName;
    public AssetPosition assetPosition;
}

[System.Serializable]
public class AssetPosition
{
    public float x;
    public float y;
    public float z;
}



public class TextAndPositionUpdater : MonoBehaviour
{
    public GameObject textPrefab;
    public Transform canvasTransform;
    private Dictionary<int, GameObject> textObjects = new Dictionary<int, GameObject>();
    private WebSocket ws;
    private ConcurrentQueue<TextResponse> textMessageQueue = new ConcurrentQueue<TextResponse>();
    private ConcurrentQueue<AssetInfo> assetMessageQueue = new ConcurrentQueue<AssetInfo>();

    void Start()
    {
        ws = new WebSocket("ws://35.215.89.200:8080/ws");

        ws.OnOpen += (sender, e) =>
        {
            Debug.Log("WebSocket connection opened");
        };

        ws.OnError += (sender, e) =>
        {
            Debug.LogError("WebSocket Error: " + e.Message);
        };

        ws.OnClose += (sender, e) =>
        {
            Debug.Log("WebSocket connection closed");
        };

        ws.OnMessage += (sender, e) =>
        {
            //Debug.Log("Received: " + e.Data);
            try
            {
                TextResponse textResponse = JsonUtility.FromJson<TextResponse>(e.Data);
                if (textResponse != null && textResponse.entries != null)
                {
                    //Debug.Log("Enqueuing text message with " + textResponse.entries.Count + " entries.");
                    textMessageQueue.Enqueue(textResponse);
                }

                AssetInfo assetInfo = JsonUtility.FromJson<AssetInfo>(e.Data);
                if (assetInfo != null && !string.IsNullOrEmpty(assetInfo.gcsLink))
                {
                    //Debug.Log("Enqueuing asset message with GCS link: " + assetInfo.gcsLink + assetInfo.assetName);
                    assetMessageQueue.Enqueue(assetInfo);
                }
            }
            catch (System.Exception ex)
            {
                Debug.LogError("Error parsing WebSocket message: " + ex.Message);
            }
        };

        ws.Connect();
    }

    void Update()
    {
        // Process text messages in the main thread
        while (textMessageQueue.TryDequeue(out TextResponse textResponse))
        {
            //Debug.Log("Dequeuing text message for UI update.");
            UpdateTextUI(textResponse);
        }

        // Process asset messages in the main thread
        while (assetMessageQueue.TryDequeue(out AssetInfo assetInfo))
        {
            //Debug.Log("Dequeuing asset message for asset loading.");
            Vector3 position = new Vector3(assetInfo.assetPosition.x, assetInfo.assetPosition.y, assetInfo.assetPosition.z);
            //Debug.Log("Asset will be instantiated at position: " + position); // Log for debugging
            StartCoroutine(LoadAsset(assetInfo.gcsLink, assetInfo.assetName, position));
        }
    }

    void UpdateTextUI(TextResponse response)
    {
        //Debug.Log("Updating UI with " + response.entries.Count + " entries.");
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

            //Debug.Log("Processed entry with ID: " + entry.id);

            processedIds.Add(entry.id);
        }

        // Delete GameObjects not in the processed list
        List<int> keys = new List<int>(textObjects.Keys);
        foreach (int key in keys)
        {
            if (!processedIds.Contains(key))
            {
                //Debug.Log("Deleting entry with ID: " + key);
                Destroy(textObjects[key]);
                textObjects.Remove(key);
            }
        }
    }

    IEnumerator LoadAsset(string uri, string assetName, Vector3 position)
    {
        using (UnityWebRequest uwr = UnityWebRequestAssetBundle.GetAssetBundle(uri))
        {
            yield return uwr.SendWebRequest();

            if (uwr.result != UnityWebRequest.Result.Success)
            {
                Debug.LogError("Failed to download asset: " + uwr.error);
            }
            else
            {
                AssetBundle bundle = DownloadHandlerAssetBundle.GetContent(uwr);
                GameObject loadedAsset = bundle.LoadAsset<GameObject>(assetName);
                Instantiate(loadedAsset, position, Quaternion.identity);
            }
        }
    }

}
