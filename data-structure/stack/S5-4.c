#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef int element;

typedef struct {
    int top;
    element data[STACK_SIZE];
} Stack;

void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int checkBrackets(char expr[]);

int main(){
    Stack s;
    char expr[STACK_SIZE];

    initStack(&s);

    scanf("%s", expr);

    printf("괄호포함 수식 입력 : ");
    if (checkBrackets(expr)){
        printf("성공\n");
    } else {
        printf("실패\n");
    }

    return 0;
}

void initStack( Stack *s ){
    s->top = -1;
}

int isFull( Stack *s ){
    return s->top == STACK_SIZE - 1;
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

int checkBrackets(char expr[]) {
    Stack s;
    initStack(&s);
    char ch, open_ch;

    for (int i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                push(&s, ch);
                break;
            case ')':
            case '}':
            case ']':
                if (isEmpty(&s)) return 0;
                open_ch = pop(&s);
                if ((open_ch == '(' && ch != ')') || 
                    (open_ch == '{' && ch != '}') || 
                    (open_ch == '[' && ch != ']')) {
                    return 0;
                }
                break;
        }
    }
    if (!isEmpty(&s)) return 0;
    return 1;
}