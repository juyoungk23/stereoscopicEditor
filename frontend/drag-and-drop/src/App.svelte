<script>
  import DepthList from "./DepthList.svelte";
  import { onMount } from "svelte";

  let editingBoxId = -1;
  let boxes = [];
  let isDragging = false;
  let canvasWidth = 800;
  let canvasHeight = 600;
  let depthFactor = 150;

  onMount(() => {
    // Function to update canvas dimensions based on window size
    const updateCanvasSize = () => {
      canvasWidth = window.innerWidth * 0.8; // 80% of window width
      canvasHeight = window.innerHeight * 0.8; // 80% of window height
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
    const scaledX = x / 2;
    const scaledY = -y / 2;
    const response = await fetch("http://35.215.112.100:8080/handleUpdate", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ id, x: scaledX, y: scaledY, depth, text }),
    });
    const data = await response.json();
    console.log("Response from server:", data);
  }

  function createBox(event) {
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

  function handleDepthChange(event) {
    const newBoxes = event.detail;
    newBoxes.forEach((box, index) => {
      box.depth = 0.5 * (index + 1);
      sendData(box.id, box.x, box.y, box.depth);
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

  async function updateText(id, text) {
    const box = boxes.find((b) => b.id === id);
    if (box) {
      sendData(id, box.x, box.y, box.depth, text);
    }
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

  function handleDelete(event) {
    const id = event.detail;
    boxes = boxes.filter((box) => box.id !== id);
    // Perform any other cleanup actions or server calls here.
  }
</script>

<div class="container">
  <DepthList
    {boxes}
    depthFactor={2}
    on:depthchange={handleDepthChange}
    on:edit={handleEdit}
    on:delete={handleDelete}
  />
  <div
    class="canvas"
    style="width: {canvasWidth}px; height: {canvasHeight}px;"
    on:click={createBox}
  >
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
  </div>
</div>

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
    margin: 16px;
    border: 2px solid red;
  }

  .draggable-text {
    position: absolute;
    cursor: grab;
    transform: translate(-50%, -50%);
    /* transition: top 0.1s ease, left 0.1s ease; Smooth movement */
    padding: 4px 8px; /* Padding around text */
    background: white;
    border-radius: 4px; /* Rounded corners for text boxes */
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1); /* Subtle Shadow for text boxes */
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
