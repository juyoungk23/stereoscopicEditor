<script>
  import Add3DAssets from "./Add3DAssets.svelte";
  import DepthList from "./DepthList.svelte";
  import { onMount } from "svelte";

  let editingBoxId = -1;
  let boxes = [];
  let assets = [];
  let isDragging = false;
  let canvasWidth = 1200;
  let canvasHeight = 1000;
  let depthFactor = 100;

  onMount(() => {
    const fetchBoxes = async () => {
      try {
        const response = await fetch("http://35.215.89.200:8080/handleTexts");
        const data = await response.json();
        boxes = data.entries.map((box) => ({
          ...box,
          x: box.x * 1.5,
          y: -box.y * 1.5,
        }));
        console.log("Fetched and scaled boxes from server:", boxes);
        console.log("Fetched boxes from server:", boxes);
      } catch (error) {
        console.error("Error fetching boxes:", error);
      }
    };

    fetchBoxes();

    const fetchAssets = async () => {
      try {
        const response = await fetch("http://35.215.89.200:8080/handleAssets");
        const data = await response.json();
        assets = data.entries; // Assuming 'entries' is the field that contains the asset array
        console.log("Fetched assets from server:", assets);
      } catch (error) {
        console.error("Error fetching assets:", error);
      }
    };

    fetchAssets();

    // Function to update canvas dimensions based on window size
    const updateCanvasSize = () => {
      canvasWidth = window.innerWidth * 0.7; // 80% of window width
      canvasHeight = window.innerHeight * 0.7; // 80% of window height
    };

    // Initially set canvas dimensions
    // updateCanvasSize();

    // Update canvas dimensions whenever the window is resized
    window.addEventListener("resize", updateCanvasSize);

    return () => {
      // Cleanup: remove event listener when component is destroyed
      window.removeEventListener("resize", updateCanvasSize);
    };
  });

  async function sendData(id, x, y, depth, text) {
    const scaledX = x / 1.5;
    const scaledY = -y / 1.5;
    const response = await fetch("http://35.215.89.200:8080/handleUpdate", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ id, x: scaledX, y: scaledY, depth, text }),
    });
    const data = await response.json();
    // console.log("Response from server:", data);
  }

  async function createBox(event) {
    if (isDragging) {
      isDragging = false;
      return;
    }

    const canvasRect = event.currentTarget.getBoundingClientRect();
    console.log(canvasRect);
    const x = event.clientX - canvasRect.left - canvasWidth / 2;
    const y = event.clientY - canvasRect.top - canvasHeight / 2;

    const id = boxes.length;
    const depth = depthFactor * (boxes.length + 1); // or any other logic for depth
    boxes = [...boxes, { id, x, y, depth, text: "New Text" }];

    sendData(id, x, y, depth, "New Text");
    console.log("boxes:", boxes);

    console.log("clientX:", event.clientX, "clientY:", event.clientY);
    console.log("canvasRect:", canvasRect.left, canvasRect.top);
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

  function handleDepthChange(event) {
    const newBoxes = event.detail;
    newBoxes.forEach((box, index) => {
      box.depth = 0.5 * (index + 1);
      sendData(box.id, box.x, box.y, box.depth, box.text);
    });
  }

  function handleMouseDown(id, event) {
    isDragging = true;
    let box = boxes.find((b) => b.id === id);
    if (!box) return;

    let startX = event.clientX;
    let startY = event.clientY;

    function handleMouseMove(event) {
      let dx = event.clientX - startX;
      let dy = event.clientY - startY;

      let index = boxes.findIndex((b) => b.id === id);
      if (index === -1) return;

      let updatedBox = {
        ...boxes[index],
        x: boxes[index].x + dx,
        y: boxes[index].y + dy,
        depth: boxes[index].depth,
      };

      boxes = [...boxes.slice(0, index), updatedBox, ...boxes.slice(index + 1)];

      sendData(
        id,
        updatedBox.x,
        updatedBox.y,
        updatedBox.depth,
        boxes[index].text
      );
      startX = event.clientX;
      startY = event.clientY;
    }

    function handleMouseUp() {
      window.removeEventListener("mousemove", handleMouseMove);
      window.removeEventListener("mouseup", handleMouseUp);
    }

    window.addEventListener("mousemove", handleMouseMove);
    window.addEventListener("mouseup", handleMouseUp);
  }

  function handleEdit(event) {
    const id = event.detail;
    editingBoxId = id;
  }

  function confirmEdit(id) {
    const box = boxes.find((b) => b.id === id);
    if (box) {
      sendData(id, box.x, box.y, box.depth, box.text);
    }
    editingBoxId = -1;
  }

  function cancelEdit() {
    editingBoxId = -1;
  }

  async function deleteData(event) {
    const id = event.detail;
    boxes = boxes.filter((box) => box.id !== id);

    console.log("Sending delete request for ID:", id);

    const response = await fetch(
      `http://35.215.89.200:8080/handleUpdate?id=${id}`,
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
</script>

<DepthList
  {boxes}
  {depthFactor}
  on:depthchange={handleDepthChange}
  on:edit={handleEdit}
  on:delete={deleteData}
/>

<!-- <div class="container"> -->
<div
  class="canvas"
  style="width: {canvasWidth}px; height: {canvasHeight}px;"
  on:click={createBox}
>
  {#if boxes}
    {#each boxes as box (box.id)}
      <div
        class="draggable-text"
        style="left: calc(50% + {box.x}px); top: calc(50% + {box.y}px);"
        on:mousedown={(e) => handleMouseDown(box.id, e)}
      >
        {box.text}
        {#if editingBoxId === box.id}
          <div class="edit-form">
            <input type="text" bind:value={box.text} />
            <button on:click={() => confirmEdit(box.id)}>Confirm</button>
          </div>
        {/if}
      </div>
    {/each}
  {:else}
    <!-- Handle the case where there are no boxes -->
    <p>No boxes to display.</p>
  {/if}

  {#each assets as asset (asset.id)}
    <!-- Render each asset based on its details -->
    <!-- e.g., if you're using Three.js: -->
    <!-- <ThreeJSComponent asset={asset} /> -->
  {/each}
</div>

<!-- </div> -->

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
    position: relative;
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

  .edit-form {
    position: absolute;
    top: 100%;
    left: 0;
    background-color: #fff;
    border: 1px solid #ccc;
    padding: 8px;
  }
</style>
