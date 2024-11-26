#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          // Node data
    struct Node* next; // Pointer to the next node
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
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to find the last node
                temp = temp->next;
            }
            temp->next = newNode; // Update last node's next to new node
            newNode->next = head; // New node points to head
            head = newNode;       // Update head to the new node
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
    } else {
        Node* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link last node to new node
        newNode->next = head; // New node points to head
    }
}

// Function to delete a specific node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head, *prev = NULL;

    // Check if the node to be deleted is the head
    if (head->data == value) {
        if (head->next == head) { // Only one node in the list
            free(head);
            head = NULL;
            return;
        } else {
            // Find the last node
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next; // Update last node's next to second node
            Node* toDelete = head;
            head = head->next; // Update head to next node
            free(toDelete); // Free old head
            return;
        }
    }

    // Traverse the list to find the node to delete
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    // Node not found
    if (temp == head) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    // Node found
    prev->next = temp->next; // Link previous node to the next node
    free(temp); // Free the node
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
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
