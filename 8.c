#include <stdio.h>
#include <stdlib.h>

// Structure for a node in Circular Doubly Linked List
typedef struct Node {
    int data;              // Node data
    struct Node* next;     // Pointer to the next node
    struct Node* prev;     // Pointer to the previous node
} Node;

Node* head = NULL; // Initialize head to NULL

// Function to insert multiple nodes at the beginning
void insertAtBeginning(int count) {
    for (int i = 0; i < count; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = newNode; // Point to itself
            newNode->prev = newNode; // Point to itself
        } else {
            Node* last = head->prev; // Get the last node
            newNode->next = head;     // New node points to head
            newNode->prev = last;     // New node points to last
            head->prev = newNode;     // Last node points to new node
            last->next = newNode;     // New node becomes the new last node
            head = newNode;           // Update head to the new node
        }
    }
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode; // Point to itself
        newNode->prev = newNode; // Point to itself
    } else {
        Node* last = head->prev; // Get the last node
        newNode->next = head;     // New node points to head
        newNode->prev = last;     // New node points to last
        last->next = newNode;     // Last node points to new node
        head->prev = newNode;     // Head's previous points to new node
    }
}

// Function to delete a specific node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    
    // Traverse to find the node to delete
    do {
        if (temp->data == value) {
            // Node found
            if (temp->next == head && temp->prev == head) { // Only one node in the list
                free(temp);
                head = NULL;
                return;
            } else {
                temp->prev->next = temp->next; // Link previous node to next node
                temp->next->prev = temp->prev; // Link next node to previous node
                if (temp == head) { // Update head if necessary
                    head = temp->next;
                }
                free(temp); // Free the node
                return;
            }
        }
        temp = temp->next;
    } while (temp != head);

    // Node not found
    printf("Node with value %d not found.\n", value);
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n"); // Indicate that it loops back to head
}

// Main function
int main() {
    int choice, value, count;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Specific Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many values do you want to insert at the beginning? ");
                scanf("%d", &count);
                insertAtBeginning(count);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value of the node to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
