using UnityEngine;
using Firebase.Firestore;
using System.Collections.Generic;

public class FirestoreObjectUpdater : MonoBehaviour
{
    private FirebaseFirestore db;
    private DocumentReference sceneDocRef;
    public string objectId;  // Add this line at the top of your FirestoreObjectUpdater script


    private Vector3 lastPosition;
    private Quaternion lastRotation;
    private Vector3 lastScale;

    void Start()
    {
        db = FirebaseFirestore.DefaultInstance;
        sceneDocRef = db.Collection("scenes").Document("MySampleScene");
        Debug.Log("Started FirestoreObjectUpdater for object: " + gameObject.name);

        lastPosition = transform.position;
        lastRotation = transform.rotation;
        lastScale = transform.localScale;
    }

    void Update()
    {
        if (HasTransformChanged())
        {
            Debug.Log("Transform changed for object: " + gameObject.name);
            UpdateFirestore();
        }
    }

    bool HasTransformChanged()
    {
        return transform.position != lastPosition || transform.rotation != lastRotation || transform.localScale != lastScale;
    }

    void UpdateFirestore()
    {
        // Create nested dictionaries for position, rotation, and scale
        Dictionary<string, object> positionData = new Dictionary<string, object>
    {
        {"x", transform.position.x},
        {"y", transform.position.y},
        {"z", transform.position.z}
    };

        Dictionary<string, object> rotationData = new Dictionary<string, object>
    {
        {"x", transform.rotation.eulerAngles.x},
        {"y", transform.rotation.eulerAngles.y},
        {"z", transform.rotation.eulerAngles.z}
    };

        Dictionary<string, object> scaleData = new Dictionary<string, object>
    {
        {"x", transform.localScale.x},
        {"y", transform.localScale.y},
        {"z", transform.localScale.z}
    };

        // Create a map to hold the updates for this specific object
        Dictionary<string, object> updateData = new Dictionary<string, object>
    {
        {"position", positionData},
        {"rotation", rotationData},
        {"scale", scaleData},
        {"id", objectId}
    };

        DocumentReference docRef = db.Collection("scenes").Document("MySampleScene");

        // Use Firestore array update methods to target the specific object in the array by its ID
        docRef.UpdateAsync($"objects.{objectId}", updateData).ContinueWith(task =>
        {
            if (task.IsCompleted)
            {
                // Update the last transform states
                lastPosition = transform.position;
                lastRotation = transform.rotation;
                lastScale = transform.localScale;
            }
            else
            {
                Debug.LogError("Failed to update object: " + task.Exception);
            }
        });
    }


}
