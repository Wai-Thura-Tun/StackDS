#include "stdio.h"
#include "stdlib.h"
#define RangeValue -9595;
typedef struct node {
    int data;
    struct node* next;
}Node, *NodePtr;

typedef struct {
    NodePtr top;
}StackType,*Stack;

Stack initStack(){
    Stack sp = (Stack) malloc(sizeof(StackType));
    sp->top = NULL;
    return sp;
}
int empty(Stack s) {
    return (s->top ==  NULL);
}

int pop(Stack s) {
    if (empty(s)) {
        return RangeValue;
    }
    int hold = s->top->data;
    NodePtr temp = s->top;
    s->top = s->top->next;
    free(temp);
    return hold;
}

void push(Stack s, int n) {
    NodePtr node = (NodePtr) malloc(sizeof(Node));
    node->data = n;
    node->next = s->top;
    s->top = node;
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