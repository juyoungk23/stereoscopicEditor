using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Firebase;
using Firebase.Extensions;
using Firebase.Firestore;
using Firebase.Storage;
using System.Threading.Tasks;

public class FirestoreSceneLoader : MonoBehaviour
{
    [System.Serializable]
    public class ObjectInfo
    {
        public string id;
        public string assetBundleName;
        public Vector3 position;
        public Vector3 rotation;
        public Vector3 scale;
    }

    [System.Serializable]
    public class SceneInfo
    {
        public string sceneName;
        public List<ObjectInfo> objects;
    }

    private FirebaseFirestore db;

    void Start()
    {
        Shader.WarmupAllShaders();
        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWithOnMainThread(task =>
        {
            Debug.Log("Firebase initialized");
            FirebaseApp app = FirebaseApp.DefaultInstance;
            db = FirebaseFirestore.DefaultInstance;
            LoadSceneConfigurationFromFirestore();
        });
    }

    void LoadSceneConfigurationFromFirestore()
    {
        DocumentReference docRef = db.Collection("scenes").Document("MySampleScene");

        docRef.GetSnapshotAsync().ContinueWithOnMainThread(task =>
        {
            if (task.IsCompleted)
            {
                DocumentSnapshot snapshot = task.Result;
                if (snapshot.Exists)
                {
                    Debug.Log("Snapshot exists, parsing data...");

                    // Initialize a new SceneInfo object
                    SceneInfo sceneInfo = new SceneInfo();
                    sceneInfo.sceneName = snapshot.GetValue<string>("sceneName");

                    // Initialize the list of ObjectInfo
                    sceneInfo.objects = new List<ObjectInfo>();

                    // Fetch the objects array from Firestore as a list of dictionaries
                    List<Dictionary<string, object>> objectsList = snapshot.GetValue<List<Dictionary<string, object>>>("objects");

                    foreach (var obj in objectsList)
                    {
                        try // Add try-catch to isolate parsing errors
                        {
                            ObjectInfo objectInfo = new ObjectInfo();
                            objectInfo.id = obj["id"].ToString();
                            objectInfo.assetBundleName = obj["assetBundleName"].ToString();

                            // Fetch and assign position, rotation, and scale
                            Dictionary<string, object> position = obj["position"] as Dictionary<string, object>;
                            objectInfo.position = new Vector3(
                                Convert.ToSingle(position["x"]),
                                Convert.ToSingle(position["y"]),
                                Convert.ToSingle(position["z"])
                            );

                            Dictionary<string, object> rotation = obj["rotation"] as Dictionary<string, object>;
                            objectInfo.rotation = new Vector3(
                                Convert.ToSingle(rotation["x"]),
                                Convert.ToSingle(rotation["y"]),
                                Convert.ToSingle(rotation["z"])
                            );

                            Dictionary<string, object> scale = obj["scale"] as Dictionary<string, object>;
                            objectInfo.scale = new Vector3(
                                Convert.ToSingle(scale["x"]),
                                Convert.ToSingle(scale["y"]),
                                Convert.ToSingle(scale["z"])
                            );

                            // Debug the parsed data
                            Debug.Log("Parsed Object ID: " + objectInfo.id);
                            Debug.Log("Parsed Asset Bundle Name: " + objectInfo.assetBundleName);
                            Debug.Log("Parsed Position: " + objectInfo.position);
                            Debug.Log("Parsed Rotation: " + objectInfo.rotation);
                            Debug.Log("Parsed Scale: " + objectInfo.scale);

                            // Add this object info to the list
                            sceneInfo.objects.Add(objectInfo);
                        }
                        catch (Exception e)
                        {
                            Debug.LogError("Error while parsing object: " + e.Message);
                        }
                    }


                    Debug.Log("Successfully parsed data, proceeding to instantiate objects...");

                    // Now proceed with the instantiation
                    foreach (ObjectInfo objectInfo in sceneInfo.objects)
                    {
                        StartCoroutine(DownloadAndInstantiatePrefab(objectInfo));
                    }
                }
                else
                {
                    Debug.LogError("Scene not found");
                }
            }
            else
            {
                Debug.LogError("Retrieve scene failed: " + task.Exception);
            }
        });
    }


    IEnumerator DownloadAndInstantiatePrefab(ObjectInfo objectInfo)
    {
        FirebaseStorage storage = FirebaseStorage.DefaultInstance;
        StorageReference prefabRef = storage.GetReferenceFromUrl($"gs://xcainventorytracker-83807.appspot.com/{objectInfo.assetBundleName}");

        Task<byte[]> downloadTask = prefabRef.GetBytesAsync(long.MaxValue);
        yield return new WaitUntil(() => downloadTask.IsCompleted);

        if (downloadTask.IsFaulted || downloadTask.IsCanceled)
        {
            Debug.LogError(downloadTask.Exception.ToString());
            yield break;
        }

        byte[] fileContents = downloadTask.Result;
        AssetBundleCreateRequest request = AssetBundle.LoadFromMemoryAsync(fileContents);
        yield return request;

        AssetBundle assetBundle = request.assetBundle;
        if (assetBundle == null)
        {
            Debug.LogError("Failed to load AssetBundle.");
            yield break;
        }
        else
        {
            Debug.Log("AssetBundle loaded");
        }

        GameObject prefab = assetBundle.LoadAsset<GameObject>(objectInfo.assetBundleName);

        GameObject instance = Instantiate(prefab, objectInfo.position, Quaternion.Euler(objectInfo.rotation));
        if (instance != null)
        {
            Debug.Log("Object instantiated");
        }

        instance.transform.localScale = objectInfo.scale;

        // Automatically attach the FirestoreObjectUpdater script
        instance.AddComponent<FirestoreObjectUpdater>();

        Renderer renderer = instance.GetComponent<Renderer>();
        if (renderer != null)
        {
            string originalShaderName = renderer.material.shader.name;
            Shader shader = Shader.Find(originalShaderName);
            if (shader != null)
            {
                renderer.material.shader = shader;
            }
            else
            {
                Debug.LogWarning("Shader " + originalShaderName + " not found. Using the material's current shader.");
            }
        }

        Debug.Log("AssetBundle loaded: " + assetBundle);
        Debug.Log("Prefab loaded: " + prefab);
        Debug.Log("GameObject instantiated: " + instance);


        assetBundle.Unload(false);
    }
}
