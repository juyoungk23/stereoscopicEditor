using UnityEngine;

public class SetupCameras : MonoBehaviour
{
    public float eyeSeparation = 0.064f;  // Approximate distance between human eyes in meters
    public Camera leftEye;
    public Camera rightEye;

    // Start is called before the first frame update
    void Start()
    {
        // Set the position of each camera
        leftEye.transform.localPosition = new Vector3(-eyeSeparation / 2, 0, -10);
        rightEye.transform.localPosition = new Vector3(eyeSeparation / 2, 0, -10);
    }
}
