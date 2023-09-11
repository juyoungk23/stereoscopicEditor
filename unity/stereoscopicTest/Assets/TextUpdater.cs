// using System.Collections.Generic; // Add this for Dictionary
// using UnityEngine;
// using UnityEngine.Networking;
// using System.Collections;
// using UnityEngine.UI;

// [System.Serializable]
// public class TextResponse
// {
//     public List<TextEntry> texts;  // List of TextEntry
// }

// [System.Serializable]
// public class TextEntry
// {
//     public int id;
//     public string text;
// }

// public class TextUpdater : MonoBehaviour
// {
//     public GameObject textPrefab;  // Add this line

//     public Dictionary<int, Text> textComponents = new Dictionary<int, Text>();

//     // Create a function to register a text component by id
//     public void RegisterTextComponent(int id, Text textComponent)
//     {
//         textComponents[id] = textComponent;
//     }

//     void Start()
//     {
//         StartCoroutine(GetLatestText());
//     }


// IEnumerator GetLatestText()
// {
//     while (true)
//     {
//         UnityWebRequest www = UnityWebRequest.Get("http://34.94.214.126:8080/updateText");
//         yield return www.SendWebRequest();

//         if (www.result != UnityWebRequest.Result.Success)
//         {
//             Debug.Log(www.error);
//         }
//         else
//         {
//             string receivedText = www.downloadHandler.text;
//             TextResponse response = JsonUtility.FromJson<TextResponse>(receivedText);
//             foreach (var entry in response.texts)
//             {
//                 Text textComponent;
//                 if (!textComponents.TryGetValue(entry.id, out textComponent))
//                 {
//                     // Create new text component
//                     GameObject newTextObject = Instantiate(textPrefab);
//                     textComponent = newTextObject.GetComponent<Text>();
//                     textComponents[entry.id] = textComponent;
//                 }
//                 // Update the text
//                 textComponent.text = entry.text;
//             }
//         }
//         yield return new WaitForSeconds(1);
//     }
// }


// }
