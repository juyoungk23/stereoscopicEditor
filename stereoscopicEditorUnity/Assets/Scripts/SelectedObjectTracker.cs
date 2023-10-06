using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;

public class SelectedObjectTracker : MonoBehaviour
{
    public static GameObject selectedObject;  // Static reference, accessible from other scripts
    public TMP_Text displayText;  // Reference to your TextMeshPro text component

    // Update is called once per frame
    void Update()
    {
        // Check for a mouse click
        if (Input.GetMouseButtonDown(0))
        {
            // Create a ray from the Mouse click position
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);

            // To store the hit object information
            RaycastHit hit;

            // Check if the ray hits any collider
            if (Physics.Raycast(ray, out hit))
            {
                // Check if the hit object is not a UI element
                if (!EventSystem.current.IsPointerOverGameObject())
                {
                    // Set the selectedObject
                    selectedObject = hit.collider.gameObject;
                    displayText.text = selectedObject.name;
                    Debug.Log(selectedObject.name);
                }
            }
            else
            {
                // If nothing is hit and the click is not on a UI element, set selectedObject to null
                if (!EventSystem.current.IsPointerOverGameObject())
                {
                    selectedObject = null;
                    displayText.text = "No Object Selected";
                    Debug.Log("No object selected");
                }
            }
        }
    }
}
