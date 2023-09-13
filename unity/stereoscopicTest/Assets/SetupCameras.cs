using UnityEngine;

public class SetupCameras : MonoBehaviour
{
    public float eyeSeparation = 0.064f;  // Initial separation
    public float adjustmentStep = 0.01f;  // Step size for adjustments
    public Camera leftEye;
    public Camera rightEye;

    void Start()
    {
        // Set initial positions
        UpdateEyePositions();
    }

    void Update()
    {
        // For demonstration, let's say you press 'U' to increase separation and 'D' to decrease
        if (Input.GetKeyDown(KeyCode.U))
        {
            eyeSeparation += adjustmentStep;
            UpdateEyePositions();
        }
        else if (Input.GetKeyDown(KeyCode.D))
        {
            eyeSeparation -= adjustmentStep;
            UpdateEyePositions();
        }
    }

    void UpdateEyePositions()
    {
        // Update the position of each camera based on new eyeSeparation
        leftEye.transform.localPosition = new Vector3(-eyeSeparation / 2, 0, -1);
        rightEye.transform.localPosition = new Vector3(eyeSeparation / 2, 0, -1);
    }
}
