<script>
  import { onMount } from 'svelte';
  
  let canvas;
  let ctx;
  let isDragging = false;
  let currentTextBox = null;
  let textBoxes = [];
  let showInput = false;
  let inputText = '';
  let inputX = 0;
  let inputY = 0;
  let dragStart = null;
  let inputElement;

  onMount(() => {
    ctx = canvas.getContext("2d");
    ctx.font = "16px Arial";
    drawCanvas();

    // Listen for click events on the window to close the input field
    window.addEventListener('mousedown', (event) => {
      if (showInput && !inputElement.contains(event.target)) {
        updateText();
      }
    });
  });

  function drawCanvas() {
    if (!ctx) return;

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    textBoxes.forEach(({ x, y, text }) => {
      ctx.fillText(text, x, y);
    });
  }

  function handleMouseDown(event) {
    if (!ctx) return;

    const rect = canvas.getBoundingClientRect();
    const x = event.clientX - rect.left;
    const y = event.clientY - rect.top;

    dragStart = { x, y };

    currentTextBox = textBoxes.find(({ x: tx, y: ty }) => {
      const textMetrics = ctx.measureText("New Text");
      return x >= tx && x <= tx + textMetrics.width && y >= ty - 12 && y <= ty;
    });
  }

  function handleMouseMove(event) {
    if (!dragStart) return;

    const rect = canvas.getBoundingClientRect();
    const x = event.clientX - rect.left;
    const y = event.clientY - rect.top;

    if (currentTextBox && (Math.abs(dragStart.x - x) > 5 || Math.abs(dragStart.y - y) > 5)) {
      isDragging = true;
      showInput = false;
      currentTextBox.x = x;
      currentTextBox.y = y;
      drawCanvas();
    }
  }

  function handleMouseUp(event) {
    if (!isDragging && currentTextBox) {
      showInput = true;
      inputText = currentTextBox.text;
      inputX = currentTextBox.x;
      inputY = currentTextBox.y - 12;
    } else if (!currentTextBox) {
      const rect = canvas.getBoundingClientRect();
      const x = event.clientX - rect.left;
      const y = event.clientY - rect.top;
      const newTextBox = { x, y, text: "New Text" };
      textBoxes.push(newTextBox);
      drawCanvas();
    }

    isDragging = false;
    dragStart = null;
  }

  function updateText() {
    if (currentTextBox) {
      currentTextBox.text = inputText;
    }
    drawCanvas();
    showInput = false;
  }
</script>

<!-- Styles -->
<style>
  #canvas {
    border: 2px solid black;
  }
  .text-input {
    position: absolute;
    display: none;
  }
  .text-input.active {
    display: block;
  }
</style>

<!-- HTML -->
<div style="position:relative;">
  <canvas
    bind:this={canvas}
    id="canvas"
    width="800"
    height="600"
    on:mousedown={handleMouseDown}
    on:mousemove={handleMouseMove}
    on:mouseup={handleMouseUp}
  />
  <input 
    bind:this={inputElement}
    class="text-input {showInput ? 'active' : ''}" 
    style="left: {inputX}px; top: {inputY}px;" 
    bind:value={inputText}
    on:keydown={(e) => { if (e.key === 'Enter') updateText(); }}
  />
</div>
