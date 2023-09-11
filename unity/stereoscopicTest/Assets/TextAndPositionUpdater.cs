using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System.Collections;
using UnityEngine.UI;

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
    public List<TextEntry> texts;  // Make sure this field name matches the JSON field name
}

public class TextAndPositionUpdater : MonoBehaviour
{
    public GameObject textPrefab;
    private Dictionary<int, GameObject> textObjects = new Dictionary<int, GameObject>();
    private string url = "http://34.94.214.126:8080/updateText"; // Replace with your Go server URL

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
                Debug.Log(www.error);
            }
            else
            {
                TextResponse response = JsonUtility.FromJson<TextResponse>(receivedText);

                if (response.texts == null || response.texts.Count == 0)
                {
                    Debug.Log("No texts received from server.");
                }
                else
                {
                    foreach (var entry in response.texts)
                    {
                        GameObject textObj;
                        if (!textObjects.TryGetValue(entry.id, out textObj))
                        {
                            textObj = Instantiate(textPrefab);
                            textObjects[entry.id] = textObj;
                        }

                        // Update Position and Depth
                        textObj.transform.position = new Vector3(entry.x, entry.y, entry.depth);

                        // Update Text
                        Text textComponent = textObj.GetComponent<Text>();
                        if (textComponent != null)
                        {
                            textComponent.text = entry.text;
                        }

                        Debug.Log("TextEntry content: " + entry.depth);
                        // Debug.Log("Depth: " + entry.depth);
                    }
                }
            }

            yield return new WaitForSeconds(1);
        }
    }
}
