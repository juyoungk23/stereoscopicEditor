using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;
using TMPro;

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
    private string url = "http://35.215.89.200:8080/handleUpdate";

    void Start()
    {
        StartCoroutine(GetLatestTextAndPosition());
    }

    IEnumerator GetLatestTextAndPosition()
    {
        while (true)
        {
            UnityWebRequest www = UnityWebRequest.Get(url);
            yield return www.SendWebRequest();
            string receivedText = www.downloadHandler.text;

            if (www.result != UnityWebRequest.Result.Success)
            {
                Debug.Log("Error: " + www.error);
            }
            else
            {
                TextResponse response = JsonUtility.FromJson<TextResponse>(receivedText);

                // List to keep track of processed IDs
                List<int> processedIds = new List<int>();

                if (response.entries != null && response.entries.Count > 0)
                {
                    foreach (var entry in response.entries)
                    {
                        GameObject textObj;
                        if (!textObjects.TryGetValue(entry.id, out textObj))
                        {
                            textObj = Instantiate(textPrefab, canvasTransform);
                            textObjects[entry.id] = textObj;
                        }

                        textObj.GetComponent<RectTransform>().anchoredPosition3D = new Vector3(entry.x, entry.y, entry.depth);
                        TextMeshProUGUI textComponent = textObj.GetComponent<TextMeshProUGUI>();
                        if (textComponent != null)
                        {
                            textComponent.text = entry.text;
                        }

                        // Add ID to processed IDs list
                        processedIds.Add(entry.id);
                    }
                }

                // Delete GameObjects that are not in the processed list
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

            yield return new WaitForSeconds(1);
        }
    }
}
