#include <stdio.h>
#include <stdlib.h>

// Node structure for Binary Search Tree
struct Node {
    int val;              // Value of the node
    struct Node* lft;     // Pointer to the left child
    struct Node* rgt;     // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->lft = newNode->rgt = NULL;
    return newNode;
}

// Function to insert a new node into the BST (iterative approach)
struct Node* insert(struct Node* root, int val) {
    struct Node* newNode = createNode(val);

    if (root == NULL) {
        return newNode; // Tree is empty, new node becomes root
    }

    struct Node* cur = root;
    struct Node* prev = NULL;

    // Traverse the tree to find the right position for the new node
    while (cur != NULL) {
        prev = cur;
        if (val < cur->val) {
            cur = cur->lft;  // Move to the left subtree
        } else {
            cur = cur->rgt;  // Move to the right subtree
        }
    }

    // Insert the new node at the correct position
    if (val < prev->val) {
        prev->lft = newNode;  // Insert as left child
    } else {
        prev->rgt = newNode;  // Insert as right child
    }

    return root;
}

// Function for in-order traversal of the BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->lft);         // Visit left subtree
        printf("%d ", root->val);   // Print root value
        inOrder(root->rgt);         // Visit right subtree
    }
}

// Function to display the tree
void display(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
    } else {
        printf("In-order traversal: ");
        inOrder(root);              // Call in-order traversal to display the tree
        printf("\n");
    }
}

int main() {
    struct Node* root = NULL;
    int choice, n, val, i;

    do {
        printf("\nMenu:\n");
        printf("1. Insert multiple values\n");
        printf("2. Display tree (In-order traversal)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many values do you want to insert? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter value %d: ", i + 1);
                    scanf("%d", &val);
                    root = insert(root, val);
                }
                break;
            case 2:
                display(root);  // Call display function
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
