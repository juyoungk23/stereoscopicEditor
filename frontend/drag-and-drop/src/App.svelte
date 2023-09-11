<script>
  import DepthList from "./DepthList.svelte";
  import { createEventDispatcher } from 'svelte';
  const dispatch = createEventDispatcher();

  let boxes = [];
  let isDragging = false;
  let canvasWidth = 800;
  let canvasHeight = 600;

  async function sendData(id, x, y, depth) {
    const scaledX = x / 50;
    const scaledY = -y / 50;
    const response = await fetch("http://34.94.214.126:8080/position", {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({ id, x: scaledX, y: scaledY, depth }),
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
  const x = event.clientX - canvasRect.left - (canvasWidth / 2);
  const y = event.clientY - canvasRect.top - (canvasHeight / 2);

  const id = boxes.length;

  const depth = 0.5 * (boxes.length + 1); // or any other logic for depth
  boxes = [...boxes, { id, x, y, depth, text: "New Text" }];

  sendData(id, x, y, depth);
  console.log("boxes:", boxes);
}


async function sendDepthData(id, depth) {
    const response = await fetch("http://34.94.214.126:8080/depth", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ id, depth }),
    });
    const data = await response.json();
    console.log("Depth Response from server:", data);
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

      let updatedBox = { ...boxes[index], x: boxes[index].x + dx, y: boxes[index].y + dy, depth: boxes[index].depth };

      boxes = [
        ...boxes.slice(0, index),
        updatedBox,
        ...boxes.slice(index + 1),
      ];

      sendData(id, updatedBox.x, updatedBox.y, updatedBox.depth);
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
    const response = await fetch("http://34.94.214.126:8080/updateText", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({ id, text }),
    });
    const data = await response.json();
    console.log("Response from server:", data);
  }
</script>

<style>
  .container {
  display: flex;
}

  .canvas {
    width: 800px;
    height: 600px;
    border: 2px solid black;
    position: relative;
    overflow: hidden;
    flex-grow: 1;
  }
  .draggable-text {
    position: absolute;
    cursor: grab;
    transform: translate(-50%, -50%);
  }
</style>


<div class="container">
  <DepthList {boxes} on:depthchange={handleDepthChange} />
  <div class="canvas" on:click={createBox}>
    {#each boxes as box (box.id)}
    <div class="draggable-text"
    style="left: calc(50% + {box.x}px); top: calc(50% + {box.y}px);"
    on:mousedown={(e) => handleMouseDown(box.id, e)}>
  {box.text}
  </div>
  
    {/each}
  </div>
</div>



{#each boxes as box (box.id)}
  <input type="text" bind:value={box.text} on:input={() => updateText(box.id, box.text)} />
{/each}
