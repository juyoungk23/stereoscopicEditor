using UnityEngine;
using UnityEngine.UI;

public class DeleteObjectButton : MonoBehaviour
{
    [Header("Components")]
    [SerializeField] private Button deleteButton;

    private void Start()
    {
        // Attach the DeleteSelectedObject method to the button's onClick event
        deleteButton.onClick.AddListener(DeleteSelectedObject);
    }

    private void DeleteSelectedObject()
    {
        // Check if there is a selected object
        GameObject selectedObject = SelectedObjectTracker.selectedObject;
        if (selectedObject != null)
        {
            // Delete the selected object
            Destroy(selectedObject);
        }
    }
}
