using WebSocketSharp;
using UnityEngine;

public class WebSocketController : MonoBehaviour
{
    private WebSocket ws;

    void Start()
    {
        ws = new WebSocket("ws://35.215.89.200:8080/ws");

        ws.OnMessage += (sender, e) =>
        {
            Debug.Log("Received: " + e.Data);
            // Here you can handle the received message to update Unity objects
        };

        ws.Connect();
    }

    void OnDestroy()
    {
        ws.Close();
    }
}
