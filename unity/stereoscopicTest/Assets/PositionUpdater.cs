using UnityEngine;
using UnityEngine.Networking;
using System.Collections;
using System.Collections.Generic;

[System.Serializable]
public class Position
{
    public int id;
    public float x;
    public float y;
}

[System.Serializable]
public class Positions
{
    public List<Position> positions;
}

public class PositionUpdater : MonoBehaviour
{
    public GameObject textObject;
    private string url = "http://34.94.214.126:8080/position";
    public GameObject textPrefab;  // Prefab for Unity's built-in Text
private Dictionary<int, GameObject> textObjects = new Dictionary<int, GameObject>();


    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(GetTextPosition());
    }

    IEnumerator GetTextPosition()
{
    while (true)
    {
        UnityWebRequest www = UnityWebRequest.Get(url);
        yield return www.SendWebRequest();

        if (www.result != UnityWebRequest.Result.Success)
        {
            Debug.Log(www.error);
        }
        else
        {
            Debug.Log("Raw response: " + www.downloadHandler.text);

            Positions posList = JsonUtility.FromJson<Positions>(www.downloadHandler.text);

            foreach (var pos in posList.positions)
            {
                // Create or update text object positions here
                // Assume textObjects is a Dictionary<int, GameObject>
                GameObject textObj;
                if (!textObjects.TryGetValue(pos.id, out textObj))
                {
                    textObj = Instantiate(textPrefab);
                    textObjects[pos.id] = textObj;
                }
                textObj.transform.position = new Vector3(pos.x, pos.y, textObj.transform.position.z);
            }
        }
        yield return new WaitForSeconds(1);
    }
}
}
