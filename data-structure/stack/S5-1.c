#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
    int top;
    element data[MAX_STACK_SIZE];
} Stack;

Stack s;

void initStack() {
    s.top = -1;
}

bool isEmpty() {
    return s.top == -1;
}

bool isFull() {
    return s.top == MAX_STACK_SIZE - 1;
}

void push(element item) {
    s.data[++s.top] = item;
}

element pop() {
    if (isFull()) {
        printf("is full\n");
        return 0;
    }
    return s.data[s.top--];
}

element peek() {
    if (isEmpty()) {
        printf("is empty\n");
        return 0;
    }
    return s.data[s.top];
}

int main() {
    initStack();

    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", peek());
    printf("%d\n", pop());

    return 0;
}