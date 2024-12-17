#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
    int top;
    element data[MAX_STACK_SIZE];
} Stack;

void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );
element peek( Stack *s );

int main() {
    char expr[MAX_STACK_SIZE];
    Stack s;
    int i = 0;
    int val1, val2;
    int result;

    initStack(&s);

    fgets(expr, MAX_STACK_SIZE, stdin);

    for (i = 0; i < strlen(expr); i++) {
        if (expr[i] == ' ')
            continue;

        if (expr[i] >= '0' && expr[i] <= '9') {
            push(&s, expr[i] - '0');
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            val2 = pop(&s);
            val1 = pop(&s);

            switch (expr[i]) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    push(&s, val1 / val2);
                    break;
            }
        }
    }

    result = peek(&s);
    printf("%d", result);

    return 0;
}

void initStack( Stack *s ){
    s->top = -1;
}

int isFull( Stack *s ){
    return s->top == MAX_STACK_SIZE - 1;
}

int isEmpty( Stack *s ){
    return s->top == -1;
}

void push( Stack *s, element data ){
    if( isFull(s) ){
        printf("stack is full \n");
        return;
    }
    s->data[++(s->top)] = data;
}

element pop( Stack *s ){
    if( isEmpty(s) ){
        printf("stack is empty \n");
        return 0;
    }
    return s->data[(s->top)--];
}

element peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return 0;
}