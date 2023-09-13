using UnityEngine;
using UnityEngine.Networking;
using System.Collections;

public class AssetLoader : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(LoadAsset("https://storage.googleapis.com/stereoscopic-test-3d-assets/AssetBundles/myobject_bundle"));
    }

    IEnumerator LoadAsset(string uri)
    {
        using (UnityWebRequest uwr = UnityWebRequestAssetBundle.GetAssetBundle(uri))
        {
            yield return uwr.SendWebRequest();

            if (uwr.result != UnityWebRequest.Result.Success)
            {
                Debug.Log("Failed to download asset: " + uwr.error);
            }
            else
            {
                AssetBundle bundle = DownloadHandlerAssetBundle.GetContent(uwr);
                GameObject loadedAsset = bundle.LoadAsset<GameObject>("abstract_object(75).fbx"); // replace "YourAssetName" with the name of the asset in Unity
                Instantiate(loadedAsset, new Vector3(0, 0, 10), Quaternion.identity);
            }
        }
    }
}
