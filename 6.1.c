#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct Node {
    int vl;           // Node value
    struct Node* nx;  // Pointer to the next node
} Node;

// Define the stack structure
typedef struct Stack {
    Node* tp;  // Top of the stack
} Stack;

// Push operation for stack
void push(Stack* st, int vl) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vl = vl;
    new_node->nx = st->tp;
    st->tp = new_node;
}

// Pop operation for stack
int pop(Stack* st) {
    if (st->tp == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* tmp = st->tp;
    int vl = tmp->vl;
    st->tp = st->tp->nx;
    free(tmp);
    return vl;
}

// Display stack elements
void display_stack(Stack* st) {
    Node* tmp = st->tp;
    if (tmp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->vl);
        tmp = tmp->nx;
    }
    printf("None\n");
}

// Undo the last operation (either push or pop)
void undo(Stack* st, Stack* undoStack) {
    if (undoStack->tp == NULL) {
        printf("Nothing to undo.\n");
        return;
    }

    int last_action = pop(undoStack);

    if (last_action > 0) {
        // Undo a push operation
        printf("Undoing last push: %d\n", pop(st));
    } else if (last_action < 0) {
        // Undo a pop operation
        int popped_value = -last_action;
        printf("Undoing last pop: Pushing back %d\n", popped_value);
        push(st, popped_value);
    }
}

int main() {
    Stack st;        // Main stack
    Stack undoStack; // Stack to keep track of operations for undo
    st.tp = NULL;
    undoStack.tp = NULL;

    int choice, value, num_values, i;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Undo last operation\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Ask user how many values they want to push
                printf("How many values do you want to push? ");
                scanf("%d", &num_values);

                for (i = 0; i < num_values; i++) {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&st, value);
                    push(&undoStack, value);  // Store the push action for undo
                }
                break;
            case 2:
                value = pop(&st);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                    push(&undoStack, -value);  // Store the pop action for undo (store as negative)
                }
                break;
            case 3:
                display_stack(&st);
                break;
            case 4:
                undo(&st, &undoStack);  // Undo the last operation
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
