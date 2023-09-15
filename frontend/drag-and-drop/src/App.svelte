<script>
  import { onMount } from "svelte";
  import DepthList from "./DepthList.svelte";
  import Add3DAssets from "./Add3DAssets.svelte";

  let texts = [];
  let assets = [];
  let editingTextId = -1;
  let depthFactor = 100;
  let scaleFactor = 1.5;
  let isDragging = false;
  let canvasWidth = 1200;
  let canvasHeight = 1000;
  let elements = [
    ...texts.map((t) => ({ ...t, type: "text" })),
    ...assets.map((a) => ({ ...a, type: "asset" })),
  ];

  onMount(() => {
    const fetchData = async (url) => {
      try {
        const response = await fetch(url);
        const data = await response.json();
        return data;
      } catch (error) {
        console.error("Error fetching data:", error);
      }
    };

    // fetch texts and assets from server
    fetchData("http://35.215.89.200:8080/handleTexts") // fetch texts
      .then((data) => {
        texts = data.entries.map((text) => ({
          ...text,
          x: text.x * 1.5,
          y: -text.y * 1.5,
        }));
        console.log("Fetched and scaled boxes from server:", texts);
        console.log("Fetched boxes from server:", texts);
      })
      .then(() => {
        fetchData("http://35.215.89.200:8080/handleAssets") // fetch assets
          .then((data) => {
            assets = data.assets;
            console.log("ON MOUNT ASSETS:", assets);

            // scale the x, y , z positions similar to the texts object
            assets = assets.map((asset) => ({
              ...asset,
              assetPosition: {
                x: asset.assetPosition.x * 1.5,
                y: -asset.assetPosition.y * 1.5,
                z: asset.assetPosition.z * 1.5,
              },
            }));

            console.log("Fetched assets from server:", assets);

            // for each asset, print its ID
            assets.forEach((asset) => {
              console.log("Asset ID:", asset.id);
              console.log(
                "Asset Position = {X: ",
                asset.assetPosition.x,
                " Y: ",
                asset.assetPosition.y,
                " Z: ",
                asset.assetPosition.z,
                "}"
              );
            });

            elements = [
              ...texts.map((t) => ({ ...t, type: "text" })),
              ...assets.map((a) => ({ ...a, type: "asset" })),
            ];

            console.log("Elements:", elements);
          });
      });

    // Function to update canvas dimensions based on window size

    const updateCanvasSize = () => {
      canvasWidth = window.innerWidth * 0.7; // 80% of window width
      canvasHeight = window.innerHeight * 0.7; // 80% of window height
    };

    // Initially set canvas dimensions
    updateCanvasSize();

    // Update canvas dimensions whenever the window is resized
    window.addEventListener("resize", updateCanvasSize);

    return () => {
      // Cleanup: remove event listener when component is destroyed
      window.removeEventListener("resize", updateCanvasSize);
    };
  });

  async function sendData(type, data) {
    console.log("sending data type: ", type);

    switch (type) {
      case "text":
        data.x = data.x / scaleFactor;
        data.y = -data.y / scaleFactor;

        const response = await fetch("http://35.215.89.200:8080/handleTexts", {
          method: "POST",
          headers: {
            "Content-Type": "application/json",
          },
          body: JSON.stringify(data),
        });
        const responseDataText = await response.json();
        console.log("Response from server:", responseDataText);
        break;
      case "asset":
        const assetToUpdate = {
          id: data.id,
          assetPosition: {
            x: data.x / 20,
            y: -data.y / 10,
            z: 100,
            // Add Z if needed
          },
          // Add any other properties you need to send
        };

        const response2 = await fetch(
          "http://35.215.89.200:8080/handleAssets",
          {
            method: "POST",
            headers: {
              "Content-Type": "application/json",
            },
            body: JSON.stringify(assetToUpdate),
          }
        );

        const responseDataAsset = await response2.json();
        console.log("Response from server:", responseDataAsset);

        break;
      default:
        console.log("Invalid data type");

        break;
    }
  }

  async function createText(event) {
    if (isDragging) {
      isDragging = false;
      return;
    }

    const canvasRect = event.currentTarget.getBoundingClientRect();
    console.log(canvasRect);
    const x = event.clientX - canvasRect.left - canvasWidth / 2;
    const y = event.clientY - canvasRect.top - canvasHeight / 2;

    const id = texts.length;
    const depth = depthFactor * (texts.length + 1); // or any other logic for depth
    texts = [...texts, { id, x, y, depth, text: "New Text" }];

    sendData("text", { id, x, y, depth, text: "New Text" });
    console.log("texts:", texts);
    console.log("clientX:", event.clientX, "clientY:", event.clientY);
    console.log("canvasRect:", canvasRect.left, canvasRect.top);
  }

  function handleDepthChange(event) {
    const newElements = event.detail;
    newElements.forEach((element, index) => {
      element.depth = 0.5 * (index + 1);
      if (element.type === "text") {
        sendData("text", {
          id: element.id,
          x: element.x,
          y: element.y,
          depth: element.depth,
          text: element.text,
        });
      } else if (element.type === "asset") {
        // Your code to update asset
      }
    });
  }

  // generic handleMouseDown to account for data type (asset or text)
  function handleMouseDown(type, id, event) {
    isDragging = true;
    console.log("HANDLE MOUSE DOWN WITH ID: ", id);
    let object;
    if (type == "text") {
      object = texts.find((b) => b.id === id);
      console.log("Text found");
    }
    if (type == "asset") {
      object = assets.find((a) => a.id === id);
      console.log(object);
      console.log("Asset found");
    }

    if (!object) return;

    let startX = event.clientX;
    let startY = event.clientY;

    function handleMouseMove(event) {
      console.log("Mouse Moved");
      let dx = event.clientX - startX;
      let dy = event.clientY - startY;

      let index;

      let updatedData;
      if (type == "text") {
        index = texts.findIndex((t) => t.id === id);
        if (index === -1) return;
        updatedData = {
          ...texts[index],
          x: texts[index].x + dx,
          y: texts[index].y + dy,
          depth: texts[index].depth,
        };
      }

      if (type == "asset") {
        index = assets.findIndex((a) => a.id === id);
        console.log("Index:", index);
        if (index === -1) return;
        updatedData = {
          ...assets[index],
          assetPosition: {
            x: assets[index].assetPosition.x + dx,
            y: assets[index].assetPosition.y + dy,
            z: assets[index].assetPosition.z, // Assuming Z doesn't change
          },
        };
      }

      //update elements with updatedData
      if (type == "text") {
        texts = [
          ...texts.slice(0, index),
          updatedData,
          ...texts.slice(index + 1),
        ];
      }
      if (type == "asset") {
        assets = [
          ...assets.slice(0, index),
          updatedData,
          ...assets.slice(index + 1),
        ];
      }

      startX = event.clientX;
      startY = event.clientY;
    }

    function handleMouseUp() {
      // Send data to the server only when the drag operation is completed
      let object;
      console.log("HANDLE MOUSE UP:", type);

      if (type == "text") {
        object = texts.find((b) => b.id === id);
        if (object) {
          sendData("text", {
            id,
            x: object.x,
            y: object.y,
            depth: object.depth,
            text: object.text,
          });
        }
      }

      if (type == "asset") {
        object = assets.find((a) => a.id === id);
        if (object) {
          sendData("asset", {
            id,
            x: object.assetPosition.x,
            y: object.assetPosition.y,
          });
        }
      }
      window.removeEventListener("mousemove", handleMouseMove);
      window.removeEventListener("mouseup", handleMouseUp);
    }

    window.addEventListener("mousemove", handleMouseMove);
    window.addEventListener("mouseup", handleMouseUp);
  }

  function handleEdit(event) {
    const id = event.detail;
    editingTextId = id;
  }

  async function deleteData(event) {
    const id = event.detail;
    texts = texts.filter((text) => text.id !== id);

    console.log("Sending delete request for ID:", id);

    const response = await fetch(
      `http://35.215.89.200:8080/handleTexts?id=${id}`,
      {
        method: "DELETE",
      }
    );
    if (response.ok) {
      console.log(`Deleted entry with ID: ${id}`);
    } else {
      console.log("Failed to delete entry");
    }
  }
  function confirmEdit(id) {
    const text = texts.find((b) => b.id === id);
    if (text) {
      sendData("text", {
        id,
        x: text.x,
        y: text.y,
        depth: text.depth,
        text: text.text,
      });
    }
    editingTextId = -1;
  }

  function cancelEdit() {
    editingTextId = -1;
  }

  async function addAsset(asset) {
    const response = await fetch("http://35.215.89.200:8080/handleAssets", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(asset),
    });
    const data = await response.json();
    console.log("Response from server:", data);
  }
</script>

<DepthList
  {texts}
  {depthFactor}
  {elements}
  on:depthchange={handleDepthChange}
  on:edit={handleEdit}
  on:delete={deleteData}
/>

<div
  class="canvas"
  style="width: {canvasWidth}px; height: {canvasHeight}px;"
  on:click={createText}
>
  {#if texts}
    {#each texts as text (text.id)}
      <div
        class="draggable-text"
        style="left: calc(50% + {text.x}px); top: calc(50% + {text.y}px);"
        on:mousedown={(e) => handleMouseDown("text", text.id, e)}
      >
        {text.text}
        {#if editingTextId === text.id}
          <div class="edit-form">
            <input type="text" bind:value={text.text} />
            <button on:click={() => confirmEdit(text.id)}>Confirm</button>
          </div>
        {/if}
      </div>
    {/each}
  {:else}
    <!-- Handle the case where there are no boxes -->
    <p>No boxes to display.</p>
  {/if}

  {#if assets}
    {#each assets as asset (asset.id)}
      <p
        class="draggable-asset"
        style="left: calc(50% + {asset.assetPosition
          .x}px); top: calc(50% + {asset.assetPosition
          .y}px); position: absolute;"
        on:mousedown={(e) => handleMouseDown("asset", asset.id, e)}
      >
        ASSET: {asset.ID}, NAME: {asset.assetName}
      </p>
    {/each}
  {:else}
    <!-- Handle the case where there are no assets -->
    <p>No assets to display.</p>
  {/if}
</div>

<Add3DAssets />

<style>
  .container {
    display: flex;
    flex-direction: row;
  }

  .canvas {
    width: 100%;
    height: 100%;
    border-radius: 12px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    background: linear-gradient(135deg, #f3eff5, #faf3e0);
    position: relative; /* this is important to position the canvas elements like texts and assets */
    overflow: hidden;
    margin-left: 250px;
  }

  .draggable-text {
    position: absolute;
    cursor: grab;
    transform: translate(-50%, -50%);
    padding: 4px 8px;
    background: white;
    border-radius: 4px;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  }
  .draggable-asset {
    position: absolute;
    cursor: grab;
    transform: translate(-50%, -50%);
    padding: 4px 8px;
    background: white;
    border-radius: 4px;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  }

  .edit-form {
    position: absolute;
    top: 100%;
    left: 0;
    background-color: #fff;
    border: 1px solid #ccc;
    padding: 8px;
  }
</style>
