using UnityEngine;

public class LightControl : MonoBehaviour
{
    public GameObject sphereObject;  // Assign your Sphere GameObject here
    public Light directionalLight;   // Assign your Directional Light here

    private Quaternion initialSphereRotation;
    private Quaternion initialLightRotation;

    void Start()
    {
        // Save the initial rotations for both the sphere and the light
        initialSphereRotation = sphereObject.transform.rotation;
        initialLightRotation = directionalLight.transform.rotation;
    }

    void Update()
    {
        // Get the current rotation of the sphere object
        Quaternion currentSphereRotation = sphereObject.transform.rotation;

        // Calculate the relative rotation from the initial rotation to the current rotation
        Quaternion relativeRotation = Quaternion.Inverse(initialSphereRotation) * currentSphereRotation;

        // Apply the relative rotation to the directional light
        Quaternion newLightRotation = initialLightRotation * relativeRotation;

        // Update the directional light's rotation
        directionalLight.transform.rotation = newLightRotation;
    }
}
