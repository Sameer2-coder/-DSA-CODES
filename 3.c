#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

Queue createQueue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int isEmpty(Queue q) {
    return q.front == -1;
}

int isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue *q, int val) {
    if (isFull(*q)) {
        printf("Queue is full! Cannot enqueue %d\n", val);
        return;
    }
    if (isEmpty(*q)) {
        q->front = 0;
    }
    q->data[++(q->rear)] = val;
    printf("%d enqueued to queue\n", val);
}

int dequeue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1; // Return a sentinel value to indicate error
    }
    int val = q->data[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1; // Queue is empty after dequeue
    } else {
        q->front++;
    }
    return val;
}

void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.data[i]);
    }
    printf("\n");
}

int main() {
    Queue q = createQueue();
    int choice, val;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if (val != -1) {
                    printf("%d dequeued from queue\n", val);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
