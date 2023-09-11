<script>
// @ts-nocheck
import { onMount } from 'svelte';
  import { createEventDispatcher } from 'svelte';
  const dispatch = createEventDispatcher();

  export let boxes = [];
  let activeItem = null;
  let closestItem = null;

  onMount(() => {
    const list = document.getElementById('draggable-list');
    
    list.addEventListener('dragover', (e) => {
      e.preventDefault();
      activeItem = document.querySelector('.active');
      closestItem = getClosest(e.clientY, activeItem);
    });

    list.addEventListener('dragend', () => {
      if (closestItem && activeItem) {
        const closestItemIndex = [...list.children].indexOf(closestItem);
        const activeItemIndex = boxes.findIndex(box => box.id === +activeItem.dataset.id);
        [boxes[closestItemIndex], boxes[activeItemIndex]] = [boxes[activeItemIndex], boxes[closestItemIndex]];
        activeItem = null;
        closestItem = null;
        dispatch('depthchange', boxes); // Notify parent component about the depth change
      }
    });
  });


  function getClosest(y, excludeElement) {
    return Array.from(document.querySelectorAll('.draggable-list-item'))
      .filter(item => item !== excludeElement)
      .reduce((closest, child) => {
        const box = child.getBoundingClientRect();
        const offset = y - box.top - box.height / 2;
        if (offset < 0 && offset > closest.offset) {
          return { offset: offset, element: child };
        } else {
          return closest;
        }
      }, { offset: Number.NEGATIVE_INFINITY }).element;
  }
</script>

<!-- ... (rest of your code) ... -->


<aside>
  <ul id="draggable-list">
    {#each boxes as box, index (box.id)}
      <li
        class="draggable-list-item"
        draggable="true"
        data-id={box.id}
        on:dragstart={(e) => e.target.classList.add('active')}
        on:dragend={(e) => e.target.classList.remove('active')}
      >
        <div class="card">
          {index + 1}. {box.text} (Depth: {0.5 * (index + 1)} meters)
        </div>
      </li>
    {/each}
  </ul>
</aside>

<style>
  aside {
    left: 0;
    top: 0;
    width: 200px;
    height: 100%;
    background-color: #f1f1f1;
    overflow-y: auto;
    padding: 15px;
    box-shadow: 2px 0px 5px rgba(0, 0, 0, 0.1);
  }
  .card {
    padding: 10px;
    border: 1px solid #ccc;
    border-radius: 5px;
    background-color: #fff;
  }
  .draggable-list-item {
    margin-bottom: 12px;
  }
  .active {
    opacity: 0.5;
  }
</style>
