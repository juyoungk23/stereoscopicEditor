// Place this script in Assets/Editor
// Usage: Right click on a folder in the Project window and select "Convert Textures to Sprites"
// This will convert all PNG and JPG files in the folder to Sprites and set their Texture Type to Sprite (2D and UI)

#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using System.IO;

public class TextureToSpriteConverter
{
    [MenuItem("Assets/Convert Textures to Sprites")]
    public static void ConvertTexturesToSprites()
    {
        // Get the path of the selected folder or asset
        string path = AssetDatabase.GetAssetPath(Selection.activeObject);

        // If it's a directory, proceed with conversion
        if (Directory.Exists(path))
        {
            string[] fileEntries = Directory.GetFiles(path);
            foreach (string fileName in fileEntries)
            {
                string extension = Path.GetExtension(fileName);
                if (extension == ".png" || extension == ".jpg")
                {
                    string assetPath = fileName.Replace(Application.dataPath, "Assets");
                    TextureImporter textureImporter = AssetImporter.GetAtPath(assetPath) as TextureImporter;

                    if (textureImporter != null)
                    {
                        textureImporter.textureType = TextureImporterType.Sprite;
                        textureImporter.spriteImportMode = SpriteImportMode.Single;
                        AssetDatabase.ImportAsset(assetPath, ImportAssetOptions.ForceUpdate);
                        Debug.Log("Converted: " + assetPath);
                    }
                }
            }
        }
        else
        {
            Debug.LogWarning("Please select a folder.");
        }
    }
}
#endif
