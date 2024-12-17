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
	int menu;
	element data ;
	Stack s;
	initStack( &s );
	do{
		printf("1:push, 2:pop, 0:exit : ");
		scanf("%d", &menu);
		switch( menu ){
			case 1 :
				printf("데이터 입력 : ");
				scanf("%d", &data);
				push(&s, data);
				break;
			case 2 :
                data = pop(&s);
                        if (data != 0)
                            printf("pop 데이터 : %d\n", data);
                        break;
            case 0 :
                break;
			default :
				printf("잘못된 입력 입니다. \n");
				break;
		}
	} while( menu );
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
