<script>
  // @ts-nocheck

  import { onMount } from "svelte";
  import { createEventDispatcher } from "svelte";

  const dispatch = createEventDispatcher();

  export let boxes = [];
  export let depthFactor = 0;

  let activeItem = null;
  let closestItem = null;

  onMount(() => {
    const list = document.getElementById("draggable-list");

    list.addEventListener("dragover", (e) => {
      e.preventDefault();
      activeItem = document.querySelector(".active");
      closestItem = getClosest(e.clientY, activeItem);
    });

    list.addEventListener("dragend", () => {
      if (closestItem && activeItem) {
        const closestItemIndex = [...list.children].indexOf(closestItem);
        const activeItemIndex = boxes.findIndex(
          (box) => box.id === +activeItem.dataset.id
        );

        [boxes[closestItemIndex], boxes[activeItemIndex]] = [
          boxes[activeItemIndex],
          boxes[closestItemIndex],
        ];
        activeItem = null;
        closestItem = null;

        dispatch("depthchange", boxes); // Notify parent component about the depth change
      }
    });
  });

  function getClosest(y, excludeElement) {
    return Array.from(document.querySelectorAll(".draggable-list-item"))
      .filter((item) => item !== excludeElement)
      .reduce(
        (closest, child) => {
          const box = child.getBoundingClientRect();
          const offset = y - box.top - box.height / 2;
          if (offset < 0 && offset > closest.offset) {
            return { offset: offset, element: child };
          } else {
            return closest;
          }
        },
        { offset: Number.NEGATIVE_INFINITY }
      ).element;
  }
</script>

<aside>
  <ul id="draggable-list">
    {#each boxes as box, index (box.id)}
      <li
        class="draggable-list-item"
        draggable="true"
        data-id={box.id}
        on:dragstart={(e) => e.target.classList.add("active")}
        on:dragend={(e) => e.target.classList.remove("active")}
      >
        <div class="card">
          {box.text} (Depth: {depthFactor * (index + 1)} meters)
          <div class="buttons">
            <button on:click={() => dispatch("edit", box.id)}>Edit</button>
            <button on:click={() => dispatch("delete", box.id)}>Delete</button>
          </div>
        </div>
      </li>
    {/each}
  </ul>
</aside>

<style>
  aside {
    position: absolute;
    left: 0;
    top: 0;
    width: 400px;
    height: 100vh;
    background: linear-gradient(to bottom, #333, #555);
    overflow-y: auto;
    padding: 15px;
    box-shadow: 2px 0px 5px rgba(0, 0, 0, 0.1);
  }

  ul#draggable-list {
    list-style: none;
  }

  .buttons {
    display: flex;
    justify-content: space-evenly;
    margin-top: 10px;
  }
  .card {
    padding: 20px;
    border: 1px solid #ccc;
    border-radius: 25px;
    background-color: #fff;
    transition: all 0.3s ease;
    width: 100%;
    margin-bottom: 10px;
  }

  .draggable-list-item {
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;

    /* border: 1px solid red;
    border-radius: 20px; */
    padding: 10px; /* Added padding */
  }

  .active {
    opacity: 0.5;
  }
</style>
