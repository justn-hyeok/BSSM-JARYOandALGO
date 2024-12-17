#include <stdio.h>
#include <stdlib.h>
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

int main(){
	Stack s;
    char str[20];

    initStack(&s);

    printf("문자열 입력 : ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++){
        push(&s, str[i]);
    }

    printf("거꾸로 출력 : ");
    while (!isEmpty(&s)){
        printf("%c", pop(&s));
    }
    puts("");

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
