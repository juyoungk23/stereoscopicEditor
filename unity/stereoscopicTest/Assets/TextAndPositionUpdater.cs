using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;
using TMPro;  // Import TextMeshPro Namespace

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
    public List<TextEntry> entries;  // Make sure this field name matches the JSON field name ("entries" instead of "texts")
}

public class TextAndPositionUpdater : MonoBehaviour
{
    public GameObject textPrefab;
    public Transform canvasTransform; // Reference to Canvas transform
    private Dictionary<int, GameObject> textObjects = new Dictionary<int, GameObject>();
    private string url = "http://35.215.112.100:8080/handleUpdate"; // Replaced with your new Go server URL ("/handleUpdate")

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
            Debug.Log("Raw response: " + receivedText);  // Log raw response for debugging

            if (www.result != UnityWebRequest.Result.Success)
            {
                Debug.Log("Error: " + www.error + ", Status Code: " + www.responseCode);
            }
            else
            {
                TextResponse response = JsonUtility.FromJson<TextResponse>(receivedText);

                if (response.entries == null || response.entries.Count == 0)
                {
                    Debug.Log("No texts received from server.");
                }
                else
                {
                    foreach (var entry in response.entries)
                    {
                        GameObject textObj;
                        if (!textObjects.TryGetValue(entry.id, out textObj))
                        {
                            textObj = Instantiate(textPrefab, canvasTransform); // Instantiate as child of Canvas
                            textObjects[entry.id] = textObj;
                        }

                        // Update Position and Depth
                        textObj.GetComponent<RectTransform>().anchoredPosition3D = new Vector3(entry.x, entry.y, entry.depth); // Use RectTransform for UI elements

                        // Update Text
                        TextMeshProUGUI textComponent = textObj.GetComponent<TextMeshProUGUI>();  // Changed to TextMeshProUGUI
                        if (textComponent != null)
                        {
                            textComponent.text = entry.text;
                        }
                    }
                }
            }

            yield return new WaitForSeconds(1);
        }
    }
}
