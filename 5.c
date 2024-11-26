#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vl;           // Node value
    struct Node* nx;  // Pointer to the next node
} Node;

typedef struct LinkedList {
    Node* hd;  // Head of the list
} LinkedList;

void insert_at_end(LinkedList* ll, int vl) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vl = vl;
    new_node->nx = NULL;

    if (ll->hd == NULL) {
        ll->hd = new_node;
    } else {
        Node* tmp = ll->hd;
        while (tmp->nx != NULL) {
            tmp = tmp->nx;
        }
        tmp->nx = new_node;
    }
}

void insert_at_beginning(LinkedList* ll, int vl) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vl = vl;
    new_node->nx = ll->hd;
    ll->hd = new_node;
}

void insert_after_value(LinkedList* ll, int after_vl, int vl) {
    Node* tmp = ll->hd;
    while (tmp != NULL) {
        if (tmp->vl == after_vl) {
            Node* new_node = (Node*)malloc(sizeof(Node));
            new_node->vl = vl;
            new_node->nx = tmp->nx;
            tmp->nx = new_node;
            return;
        }
        tmp = tmp->nx;
    }
    printf("Value %d not found in the list.\n", after_vl);
}

void delete_value(LinkedList* ll, int vl) {
    Node* tmp = ll->hd;
    Node* prev = NULL;

    if (tmp != NULL && tmp->vl == vl) {
        ll->hd = tmp->nx;
        free(tmp);
        return;
    }

    while (tmp != NULL && tmp->vl != vl) {
        prev = tmp;
        tmp = tmp->nx;
    }

    if (tmp == NULL) {
        printf("Value %d not found in the list.\n", vl);
        return;
    }

    prev->nx = tmp->nx;
    free(tmp);
}

void display(LinkedList* ll) {
    Node* tmp = ll->hd;
    while (tmp != NULL) {
        printf("%d -> ", tmp->vl);
        tmp = tmp->nx;
    }
    printf("None\n");
}

int main() {
    LinkedList ll;
    ll.hd = NULL;

    // Insert values at the end
    insert_at_end(&ll, 10);
    insert_at_end(&ll, 20);
    insert_at_end(&ll, 30);

    // Insert value at the beginning
    insert_at_beginning(&ll, 5);

    // Insert value after a specific value
    insert_after_value(&ll, 20, 25);

    // Display the list
    display(&ll);

    // Delete a value
    delete_value(&ll, 20);

    // Display the list after deletion
    display(&ll);

    return 0;
}
