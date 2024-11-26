#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int data[MAX];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->data[++(stack->top)] = value;
    printf("%d pushed to stack\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    }
    return stack->data[stack->top];
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));

    printf("%d popped from stack\n", pop(&stack));

    display(&stack);

    getch();
    return 0;
}
