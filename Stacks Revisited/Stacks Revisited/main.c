#include "stdio.h"
#include "stdlib.h"

struct Stack{
    int data;
    struct Stack *next;
}*Top=NULL;


void push(struct Stack *st, int x){
    struct Stack *t = (struct Stack *)malloc(sizeof(struct Stack));
    if(!t){
        printf("Stack Overflow");
        return;
    }
//    only head insertion as LIFO
    t->data = x;
    t->next = Top;
    Top = t;
}

void pop(struct Stack *st){
    if(!Top){
        printf("Stack Underflow");
        return;
    }
    Top = st->next;
    free(st);
}

void display(struct Stack *p){
    while (p) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

int main(){
    push(Top, 1);
    push(Top, 2);
    push(Top, 3);
    push(Top, 4);
    push(Top, 5);
    pop(Top);
    display(Top);
    return 0;
}
