#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Adjust this if needed

typedef struct {
    int arr[MAX_SIZE];
    int fr, rr, sz;
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue *q, int size) {
    q->sz = size;
    q->fr = -1;
    q->rr = -1;
}

// Check if the queue is full
int isFull(CircularQueue *q) {
    return ((q->rr + 1) % q->sz == q->fr);
}

// Check if the queue is empty
int isEmpty(CircularQueue *q) {
    return (q->fr == -1);
}

// Add an element to the queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->fr = 0;
    }
    q->rr = (q->rr + 1) % q->sz;
    q->arr[q->rr] = value;
    printf("Enqueued %d\n", value);
}

// Remove an element from the queue
void dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int value = q->arr[q->fr];
    if (q->fr == q->rr) {
        q->fr = q->rr = -1; // Queue is now empty
    } else {
        q->fr = (q->fr + 1) % q->sz;
    }
    printf("Dequeued %d\n", value);
}

// Display the queue
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->fr;
    printf("Queue elements: ");
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rr) break;
        i = (i + 1) % q->sz;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    int size, numElements, value, choice;

    printf("Enter size of the queue: ");
    scanf("%d", &size);
    
    initQueue(&q, size);

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to enqueue: ");
                scanf("%d", &numElements);
                for (int i = 0; i < numElements; i++) {
                    printf("Enter element %d: ", i + 1);
                    scanf("%d", &value);
                    enqueue(&q, value);
                }
                break;

            case 2:
                printf("Enter the number of elements to dequeue: ");
                scanf("%d", &numElements);
                for (int i = 0; i < numElements; i++) {
                    dequeue(&q);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}