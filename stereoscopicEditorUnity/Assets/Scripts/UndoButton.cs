using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UndoButton : MonoBehaviour
{
    [Header("Components")]
    [SerializeField] private Button undoButton;

    private Stack<Action> undoStack = new Stack<Action>();

    public enum ActionType // Make this public
    {
        Add,
        Delete
    }

    private void Start()
    {
        // Attach the Undo method to the button's onClick event
        undoButton.onClick.AddListener(Undo);
    }

    private void Undo()
    {
        if (undoStack.Count > 0)
        {
            Action lastAction = undoStack.Pop();
            lastAction.Undo();
        }
    }

    public void AddToUndoStack(GameObject obj, ActionType actionType)
    {
        undoStack.Push(new Action(obj, actionType));
    }

    private class Action
    {
        private GameObject gameObject;
        private ActionType actionType;

        public Action(GameObject gameObject, ActionType actionType)
        {
            this.gameObject = gameObject;
            this.actionType = actionType;
        }

        public void Undo()
        {
            switch (actionType)
            {
                case ActionType.Add:
                    Destroy(gameObject);
                    break;
                case ActionType.Delete:
                    gameObject.SetActive(true);
                    break;
            }
        }
    }
}
