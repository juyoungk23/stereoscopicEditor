using UnityEngine;
using TinyGiantStudio.Text;

public class AdjustTextExtrusion : MonoBehaviour
{
    [SerializeField]
    private UnityEngine.UI.Slider extrusionSlider;  // Fully qualified to avoid ambiguity

    // Start is called before the first frame update
    void Start()
    {
        if (extrusionSlider != null)
        {
            extrusionSlider.onValueChanged.AddListener(UpdateExtrusion);
        }
        else
        {
            Debug.LogError("ExtrusionSlider is not set. Please assign it in the Inspector.");
        }
    }

    private void UpdateExtrusion(float value)
    {
        // Use the selectedObject from SelectedObjectTracker
        GameObject selectedObject = SelectedObjectTracker.selectedObject;

        if (selectedObject == null)
        {
            Debug.Log("No object selected. Cannot adjust extrusion.");
            return;
        }

        Modular3DText textObject = selectedObject.GetComponent<Modular3DText>();

        if (textObject == null)
        {
            Debug.Log("Selected object does not have a Modular3DText component. Cannot adjust extrusion.");
            return;
        }

        Vector3 currentFontSize = textObject.FontSize;  // Changed from .Size to .FontSize
        currentFontSize.z = value;  // Update the Z field (extrusion depth) with the slider value
        textObject.FontSize = currentFontSize;  // Update FontSize, which will invoke SetTextDirty() internally
    }

    // Optionally, you can unsubscribe the listener when the object is destroyed
    private void OnDestroy()
    {
        if (extrusionSlider != null)
        {
            extrusionSlider.onValueChanged.RemoveListener(UpdateExtrusion);
        }
    }
}
