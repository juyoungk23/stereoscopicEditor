using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections.Generic;
using TinyGiantStudio.Text;

public class FontSwitcher : MonoBehaviour
{
    [SerializeField]
    private TMP_Dropdown fontDropdown;  // Reference to the TextMeshPro dropdown
    [SerializeField]
    private string fontsPath = "MyCustomFonts";  // Relative path inside Resources folder

    private TinyGiantStudio.Text.Font[] fonts;  // Array to store custom fonts

    void Start()
    {
        // Initialize the dropdown options list as empty
        fontDropdown.options = new List<TMP_Dropdown.OptionData>();

        // Load all custom font files from the specified directory inside Resources folder
        fonts = Resources.LoadAll<TinyGiantStudio.Text.Font>(fontsPath);

        // If no fonts are found, log a warning
        if (fonts.Length == 0)
        {
            Debug.LogWarning("No fonts found in directory: " + fontsPath);
        }

        // Attach listener to dropdown value change event
        fontDropdown.onValueChanged.AddListener(OnDropdownValueChanged);

        // Initially disable the dropdown
        fontDropdown.interactable = false;
    }

    void Update()
    {
        // Check if a text object is currently selected
        GameObject selectedObject = SelectedObjectTracker.selectedObject;

        if (selectedObject != null)
        {
            Modular3DText textComponent = selectedObject.GetComponent<Modular3DText>();
            if (textComponent != null)
            {
                // Enable the dropdown
                fontDropdown.interactable = true;

                // Populate dropdown with font names only if it's empty
                if (fontDropdown.options.Count == 0)
                {
                    foreach (var font in fonts)
                    {
                        TMP_Dropdown.OptionData option = new TMP_Dropdown.OptionData(font.name);
                        fontDropdown.options.Add(option);
                    }
                }
                return;
            }
        }

        // If no text object is selected or if the object is null, clear and disable the dropdown
        fontDropdown.options.Clear();
        fontDropdown.captionText.text = "";  // Clear the label
        fontDropdown.interactable = false;  // Disable the dropdown
    }

    // Update the font of the selected object when the dropdown value changes
    // Update the font of the selected object when the dropdown value changes
    public void OnDropdownValueChanged(int index)
    {
        GameObject selectedObject = SelectedObjectTracker.selectedObject;
        if (selectedObject == null)
        {
            Debug.LogWarning("No object selected.");
            return;
        }

        // Obtain the Modular3DText, MeshFilter and MeshRenderer components of the selected object
        Modular3DText modular3DText = selectedObject.GetComponent<Modular3DText>();
        // MeshFilter meshFilter = selectedObject.GetComponent<MeshFilter>();
        MeshRenderer meshRenderer = selectedObject.GetComponent<MeshRenderer>();

        // If the selected object does not have a Modular3DText component, return or print a message
        if (modular3DText == null)
        {
            Debug.LogWarning("The selected object does not have a Modular3DText component.");
            return;
        }

        // Use the font selected in the dropdown
        modular3DText.Font = fonts[index];
        Debug.Log("Switching Font to: " + fonts[index].name);

        // Reattach the MeshFilter and MeshRenderer components
        // You may need to tailor this part according to how these components interact with Modular3DText
        // if (meshFilter != null && meshRenderer != null)
        if (meshRenderer != null)
        {
            // MeshFilter newMeshFilter = selectedObject.AddComponent<MeshFilter>();
            MeshRenderer newMeshRenderer = selectedObject.AddComponent<MeshRenderer>();

            // Copy old settings if necessary
            // newMeshFilter.mesh = meshFilter.mesh;
            newMeshRenderer.materials = meshRenderer.materials;

            // Remove old components
            // Destroy(meshFilter);
            Destroy(meshRenderer);

            // Attach new components
            // selectedObject.GetComponent<MeshFilter>().mesh = newMeshFilter.mesh;
            selectedObject.GetComponent<MeshRenderer>().materials = newMeshRenderer.materials;

            // Remove temporary components
            // Destroy(newMeshFilter);
            Destroy(newMeshRenderer);
        }
        else
        {
            Debug.LogWarning("The selected object does not have MeshFilter and/or MeshRenderer components.");
        }
    }

}
