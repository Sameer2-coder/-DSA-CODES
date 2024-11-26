#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h> // For strlen()

#define MAX 100

struct Stack {
    char data[MAX];
    int top;
};

struct Stack createStack() {
    struct Stack stack;
    stack.top = -1;
    return stack;
}

int isEmpty(struct Stack stack) {
    return stack.top == -1;
}

int isFull(struct Stack stack) {
    return stack.top == MAX - 1;
}

void push(struct Stack* st, char value) {
    if (isFull(*st)) {
        printf("Stack overflow! Cannot push %c\n", value);
        exit(1);
    }
    st->data[++(st->top)] = value;
}

char pop(struct Stack* st) {
    if (isEmpty(*st)) {
        printf("Stack underflow! Cannot pop\n");
        exit(1);
    }
    return st->data[(st->top)--];
}

char peek(struct Stack st) {
    if (isEmpty(st)) {
        return '\0';
    }
    return st.data[st.top];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

void infixToPostfix(char* inf, char* pst) {
    struct Stack st = createStack();
    int i = 0, j = 0;
    char op;

    while (inf[i] != '\0') {
        if (isalnum(inf[i])) {
            pst[j++] = inf[i];
        } else if (isOperator(inf[i])) {
            while (!isEmpty(st) && precedence(peek(st)) >= precedence(inf[i])) {
                pst[j++] = pop(&st);
            }
            push(&st, inf[i]);
        } else if (inf[i] == '(') {
            push(&st, inf[i]);
        } else if (inf[i] == ')') {
            while (!isEmpty(st) && peek(st) != '(') {
                pst[j++] = pop(&st);
            }
            if (!isEmpty(st) && peek(st) == '(') {
                pop(&st);
            }
        }
        i++;
    }

    while (!isEmpty(st)) {
        pst[j++] = pop(&st);
    }
    pst[j] = '\0';
}

int main() {
    char inf[MAX];
    char pst[MAX];
    int choice;

    do {
        printf("Enter an infix expression: ");
        fgets(inf, sizeof(inf), stdin);

        size_t len = strlen(inf);
        if (len > 0 && inf[len - 1] == '\n') {
            inf[len - 1] = '\0';
        }

        infixToPostfix(inf, pst);
        printf("Postfix expression: %s\n", pst);

        printf("Do you want to enter another infix expression?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        getchar(); // Consume newline left in the input buffer by scanf
    } while (choice == 1);

    printf("Exiting the program.\n");
    return 0;
}
