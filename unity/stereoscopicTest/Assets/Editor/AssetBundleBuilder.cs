using UnityEngine;
using UnityEditor;
using System.IO;

public class AssetBundleBuilder : MonoBehaviour
{
    [MenuItem("Assets/Build Standardized Asset Bundles")]
    static void BuildAllAssetBundles()
    {
        string rawAssetsPath = "Assets/Raw3DAssets";
        string standardizedPrefabsPath = "Assets/StandardizedPrefabs";

        if (!Directory.Exists(standardizedPrefabsPath))
        {
            Directory.CreateDirectory(standardizedPrefabsPath);
        }

        foreach (string filePath in Directory.GetFiles(rawAssetsPath))
        {
            if (filePath.EndsWith(".fbx") || filePath.EndsWith(".obj"))
            {
                string assetName = Path.GetFileNameWithoutExtension(filePath);
                GameObject rawAsset = AssetDatabase.LoadAssetAtPath<GameObject>(filePath);
                GameObject standardizedAsset = new GameObject(assetName + "_Standardized");

                GameObject clone = Instantiate(rawAsset);
                clone.transform.SetParent(standardizedAsset.transform);

                Bounds combinedBounds = new Bounds();
                Renderer[] renderers = clone.GetComponentsInChildren<Renderer>();

                foreach (Renderer renderer in renderers)
                {
                    combinedBounds.Encapsulate(renderer.bounds);
                }

                // Standardize size to fit within a 1x1x1 cube
                float maxSize = Mathf.Max(combinedBounds.size.x, combinedBounds.size.y, combinedBounds.size.z);
                float scaleFactor = 1.0f / maxSize;
                standardizedAsset.transform.localScale = new Vector3(scaleFactor, scaleFactor, scaleFactor);

                Vector3 offset = combinedBounds.center;
                clone.transform.localPosition = -offset;

                standardizedAsset.transform.rotation = Quaternion.identity;

                string prefabPath = standardizedPrefabsPath + "/" + assetName + "_Standardized.prefab";
                if (File.Exists(prefabPath))
                {
                    AssetDatabase.DeleteAsset(prefabPath);
                }

                GameObject prefab = PrefabUtility.SaveAsPrefabAsset(standardizedAsset, prefabPath);
                DestroyImmediate(standardizedAsset);

                AssetImporter.GetAtPath(AssetDatabase.GetAssetPath(prefab)).SetAssetBundleNameAndVariant(assetName.ToLower(), "");
            }
        }

        BuildPipeline.BuildAssetBundles("Assets/AssetBundles", BuildAssetBundleOptions.None, BuildTarget.StandaloneWindows);
    }
}
