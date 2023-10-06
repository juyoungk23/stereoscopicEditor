using UnityEngine;

public class ObjectDragger : MonoBehaviour
{
    private GameObject selectedObject;
    private Vector3 offset;
    private Camera mainCamera;

    // For resizing
    private Vector3 scaleChange;
    private Vector3 lastMousePosition;

    // For rotating
    private float rotationSpeed = 2000.0f;  // Reduced for finer control

    void Start()
    {
        // Cache the main camera
        mainCamera = Camera.main;
    }

    void Update()
    {
        // Handle mouse down
        if (Input.GetMouseButtonDown(0))
        {
            RaycastHit hit;
            Ray ray = mainCamera.ScreenPointToRay(Input.mousePosition);

            // Check if the ray hits a GameObject with a Collider (any type)
            if (Physics.Raycast(ray, out hit))
            {
                selectedObject = hit.collider.gameObject;

                // Calculate the offset between the mouse position and the GameObject position
                offset = selectedObject.transform.position - hit.point;

                // Save the last mouse position for resizing
                lastMousePosition = Input.mousePosition;
            }
        }

        // Handle mouse up
        if (Input.GetMouseButtonUp(0))
        {
            // Release the selected GameObject
            selectedObject = null;
        }

        // Handle mouse drag
        if (selectedObject != null)
        {
            RaycastHit hit;
            Ray ray = mainCamera.ScreenPointToRay(Input.mousePosition);

            // Cast a ray from the camera to the mouse position
            if (Physics.Raycast(ray, out hit))
            {
                // If Alt is held down, resize the object
                if (Input.GetKey(KeyCode.LeftAlt) || Input.GetKey(KeyCode.RightAlt))
                {
                    Vector3 mouseDelta = Input.mousePosition - lastMousePosition;
                    scaleChange = new Vector3(mouseDelta.y * 0.01f, mouseDelta.y * 0.01f, mouseDelta.y * 0.01f);
                    selectedObject.transform.localScale += scaleChange;

                    // Update last mouse position
                    lastMousePosition = Input.mousePosition;
                }
                // If Ctrl is held down, rotate the object
                else if (Input.GetKey(KeyCode.LeftControl) || Input.GetKey(KeyCode.RightControl))
                {
                    float rotationAmountX = Input.GetAxis("Mouse X") * rotationSpeed * Time.deltaTime;
                    float rotationAmountY = Input.GetAxis("Mouse Y") * rotationSpeed * Time.deltaTime;
                    selectedObject.transform.Rotate(Vector3.up * -rotationAmountX, Space.World);
                    selectedObject.transform.Rotate(Vector3.right * -rotationAmountY, Space.World);
                }
                // Else, move the object
                else
                {
                    selectedObject.transform.position = hit.point + offset;
                }
            }
        }
    }
}
