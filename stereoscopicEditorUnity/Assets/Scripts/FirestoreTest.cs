using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Firebase;
using Firebase.Extensions;
using Firebase.Firestore;
using Firebase.Storage;
using System.Threading.Tasks;

public class FirestoreAndStorageTest : MonoBehaviour
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

    void Start()
    {
        Shader.WarmupAllShaders();
        FirebaseApp.CheckAndFixDependenciesAsync().ContinueWithOnMainThread(task =>
        {
            FirebaseApp app = FirebaseApp.DefaultInstance;
            StartCoroutine(LoadSceneConfiguration());
        });
    }

    IEnumerator LoadSceneConfiguration()
    {
        FirebaseStorage storage = FirebaseStorage.DefaultInstance;
        StorageReference jsonRef = storage.GetReferenceFromUrl("gs://xcainventorytracker-83807.appspot.com/YourScene.json");

        // Download JSON
        Task<byte[]> downloadJsonTask = jsonRef.GetBytesAsync(long.MaxValue);
        yield return new WaitUntil(() => downloadJsonTask.IsCompleted);

        if (downloadJsonTask.IsFaulted || downloadJsonTask.IsCanceled)
        {
            Debug.LogError(downloadJsonTask.Exception.ToString());
            yield break;
        }

        byte[] jsonBytes = downloadJsonTask.Result;
        string jsonString = System.Text.Encoding.UTF8.GetString(jsonBytes);

        // Deserialize JSON to SceneInfo object
        SceneInfo sceneInfo = JsonUtility.FromJson<SceneInfo>(jsonString);

        foreach (ObjectInfo objectInfo in sceneInfo.objects)
        {
            yield return StartCoroutine(DownloadAndInstantiatePrefab(objectInfo));
        }
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

        // Assuming the object's name inside the AssetBundle is the same as the AssetBundle name
        GameObject prefab = assetBundle.LoadAsset<GameObject>(objectInfo.assetBundleName);

        // Instantiate the GameObject and set its transform properties
        GameObject instance = Instantiate(prefab, objectInfo.position, Quaternion.Euler(objectInfo.rotation));
        instance.transform.localScale = objectInfo.scale;

        // Reassign the shader to force recompilation and initialization
        Renderer renderer = instance.GetComponent<Renderer>();
        if (renderer != null)
        {
            // Get the original shader name
            string originalShaderName = renderer.material.shader.name;

            // Find the shader by its name and reassign it
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

        assetBundle.Unload(false);
    }
}
