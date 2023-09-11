using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class TextManager : MonoBehaviour
{
    public GameObject textPrefab;  // Prefab for Unity's built-in Text
    private Dictionary<int, Text> texts = new Dictionary<int, Text>();

    // Update or create a text object
    public void UpdateText(int id, string newText, Vector3 newPosition)
    {
        Text textComponent;
        if (!texts.TryGetValue(id, out textComponent))
        {
            // Create new text object
            GameObject newTextObject = Instantiate(textPrefab, newPosition, Quaternion.identity);
            textComponent = newTextObject.GetComponent<Text>();
            texts[id] = textComponent;
        }

        // Update text and position
        textComponent.text = newText;
        textComponent.transform.position = newPosition;
    }
}
