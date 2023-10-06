using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using TMPro;

public class AddObjectFromDropdown : MonoBehaviour
{
    public SceneLoader sceneLoader;  // Reference to your SceneLoader script
    public Button addObjectButton;  // Reference to your UI Button for adding an object
    public TMP_Dropdown objectDropdown;  // Reference to your TMP_Dropdown for object types
    public TMP_InputField inputField;  // Reference to your TMP_InputField for text objects

    void Start()
    {
        // Attach the OnClick behavior for the button
        addObjectButton.onClick.AddListener(OnAddObjectButtonClick);
    }

    void Update()
    {
        // Check the selected option and enable/disable input field
        string selectedOption = objectDropdown.options[objectDropdown.value].text;
        if (selectedOption == "Text")
        {
            inputField.interactable = true;
        }
        else
        {
            inputField.interactable = false;
        }
    }

    public void OnAddObjectButtonClick()
    {
        string selectedOption = objectDropdown.options[objectDropdown.value].text;
        Debug.Log("Selected option: " + selectedOption);

        ObjectData objectData = new ObjectData
        {
            id = "new" + selectedOption,
            assetBundleName = selectedOption.ToLower(),
            objectType = selectedOption,
            position = new Vector3Data { x = 0, y = 1, z = 0 },
            rotation = new Vector3Data { x = 0, y = 0, z = 0 },
            scale = new Vector3Data { x = 1, y = 1, z = 1 }
        };

        string assetBundleUrl = SceneLoader.assetBundleBasePath + objectData.assetBundleName;

        if (selectedOption == "Text")
        {
            string newTextContent = inputField.text;  // Get text from input field

            if (string.IsNullOrEmpty(newTextContent))
            {
                Debug.LogWarning("Input field is empty. Not adding text object.");
                return;
            }
            StartCoroutine(sceneLoader.DownloadAndInstantiateObject(objectData, assetBundleUrl, newTextContent));  // Pass the new text content
        }
        else
        {
            StartCoroutine(sceneLoader.DownloadAndInstantiateObject(objectData, assetBundleUrl));
        }
    }
}
