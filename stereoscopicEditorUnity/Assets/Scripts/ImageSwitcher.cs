using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ImageSwitcher : MonoBehaviour
{
    [SerializeField]
    private Button switchImageButton;  // Reference to your UI Button for switching the image
    [SerializeField]
    private Image targetImage;  // Reference to your UI Image component

    private int currentIndex = 0;
    private Sprite[] sprites;  // Array to store sprites

    void Start()
    {
        // Attach listener to button's OnClick event
        switchImageButton.onClick.AddListener(SwitchImage);

        // Load all sprites from the specified directory inside Resources folder
        sprites = Resources.LoadAll<Sprite>("Images");

        // If no sprites are found, log a warning
        if (sprites.Length == 0)
        {
            Debug.LogWarning("No sprites found in directory: Images");
            return;
        }
        else
        {
            Debug.Log("Loaded " + sprites.Length + " sprites.");
        }

        // Initialize the UI Image component with the first sprite
        targetImage.sprite = sprites[0];
        targetImage.preserveAspect = true;  // Preserve the aspect ratio

        if (targetImage.sprite == null)
        {
            Debug.LogWarning("Failed to set initial sprite.");
        }
        else
        {
            Debug.Log("Initial sprite set successfully.");
        }
    }

    // Call this function when the button is clicked
    public void SwitchImage()
    {
        // Increment the index and loop around if it exceeds the array length
        currentIndex++;
        if (currentIndex >= sprites.Length)
        {
            currentIndex = 0;
        }

        // Change the sprite of the UI Image component
        targetImage.sprite = sprites[currentIndex];
        targetImage.preserveAspect = true;  // Preserve the aspect ratio

        if (targetImage.sprite == null)
        {
            Debug.LogWarning("Failed to switch sprite.");
        }
        else
        {
            Debug.Log("Switching to sprite " + currentIndex);
        }
    }
}
