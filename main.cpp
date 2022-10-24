#include "stdio.h"
#include "stdlib.h"
#define RangeValue -9595
#define STACK 10
typedef struct {
    int top;
    int sp[STACK];
}StackType,*Stack;

Stack initStack(){
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp->top = -1;
    return sp;
}
int empty(Stack s) {
    return (s->top == -1);
}

int pop(Stack s) {
    if (empty(s)) {
        return RangeValue;
    }
    int hold = s->sp[s->top];
    --s->top;
    return hold;
}

void push(Stack s, int n) {
    if (s->top > STACK - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    ++s->top;
    s->sp[s->top] = n;
}
int main() {
    Stack initStack();
    int empty(Stack);
    void push(Stack,int);
    int pop(Stack);
    int n = 0;
    Stack s = initStack();
    printf("Please enter a number or if you wanna exit press 0");
    scanf("%d",&n);
    while( n != 0) {
        push(s, n);
        scanf("%d", &n);
    }
    printf("Data printing last in first out");
    while(!empty(s)) {
        printf("%d", pop(s));
        printf("\n");
    }
    return 0;
}