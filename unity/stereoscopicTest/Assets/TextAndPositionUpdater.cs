using System.Collections.Generic;
using UnityEngine;
using TMPro;
using WebSocketSharp;
using System.Collections.Concurrent;
using UnityEngine.Networking;
using System.Collections;

[System.Serializable]
public class CombinedResponse
{
    public List<TextEntry> texts;
    public List<AssetInfo> assets;
}

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
    public List<TextEntry> texts;
}

[System.Serializable]
public class AssetInfo
{
    public int id;
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

    private Dictionary<int, GameObject> assetObjects = new Dictionary<int, GameObject>();

    private Dictionary<string, AssetBundle> loadedAssetBundles = new Dictionary<string, AssetBundle>();

    private ConcurrentQueue<CombinedResponse> combinedMessageQueue = new ConcurrentQueue<CombinedResponse>();
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
            try
            {
                CombinedResponse combinedResponse = JsonUtility.FromJson<CombinedResponse>(e.Data);
                if (combinedResponse != null)
                {
                    Debug.Log("Enqueuing combined message.");
                    combinedMessageQueue.Enqueue(combinedResponse);
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
        while (combinedMessageQueue.TryDequeue(out CombinedResponse combinedResponse))
        {
            Debug.Log("Dequeued combined response: " + JsonUtility.ToJson(combinedResponse));
            UpdateTextUI(new TextResponse { texts = combinedResponse.texts });

            // Update assets
            UpdateAssets(combinedResponse.assets);
        }


    }

    void UpdateTextUI(TextResponse response)
    {
        Debug.Log("Received Text Response: " + JsonUtility.ToJson(response));

        List<int> processedIds = new List<int>();

        foreach (var entry in response.texts)
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

            Debug.Log("Processed entry with ID: " + entry.id);

            processedIds.Add(entry.id);
        }


        Debug.Log("Processed IDs: " + string.Join(", ", processedIds));

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

        Debug.Log("Remaining Text Objects: " + textObjects.Count);
    }
    void UpdateAssets(List<AssetInfo> assets)
    {
        List<int> processedIds = new List<int>();

        foreach (AssetInfo assetInfo in assets)
        {
            Vector3 position = new Vector3(assetInfo.assetPosition.x, assetInfo.assetPosition.y, assetInfo.assetPosition.z);

            GameObject assetObj;
            if (!assetObjects.TryGetValue(assetInfo.id, out assetObj))
            {
                // If asset object not found, load it
                StartCoroutine(LoadAsset(assetInfo.gcsLink, assetInfo.assetName, position, assetInfo.id));
            }
            else
            {
                // Update position if already loaded
                assetObj.transform.position = position;
            }

            processedIds.Add(assetInfo.id);
        }

        // Delete GameObjects not in the processed list
        List<int> keys = new List<int>(assetObjects.Keys);
        foreach (int key in keys)
        {
            if (!processedIds.Contains(key))
            {
                Destroy(assetObjects[key]);
                assetObjects.Remove(key);
            }
        }
    }

    IEnumerator LoadAsset(string uri, string assetName, Vector3 position, int id)
    {
        Debug.Log("Attempting to load asset from: " + uri);

        if (loadedAssetBundles.ContainsKey(uri))
        {
            Debug.Log("Asset already loaded from: " + uri);
            AssetBundle bundle = loadedAssetBundles[uri];
            GameObject loadedAsset = bundle.LoadAsset<GameObject>(assetName);
            Instantiate(loadedAsset, position, Quaternion.identity);
            yield break;
        }

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
                loadedAssetBundles[uri] = bundle;
                GameObject loadedAsset = bundle.LoadAsset<GameObject>(assetName);
                GameObject instantiatedAsset = Instantiate(loadedAsset, position, Quaternion.identity);

                // Add to assetObjects dictionary
                assetObjects[id] = instantiatedAsset;
            }
        }
    }
}
