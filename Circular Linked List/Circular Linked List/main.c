#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node *next;
}*Head=NULL;

void create(int A[], int n){
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = NULL;
    last = Head;
    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;   // just to support the arg that if one node, it should point on itself;
        last->next = t;
        last = t;
    }
    last->next = Head;
}

void display(struct Node *p){
    do{
        printf(" %d ", p->data);
        p = p->next;
    }while (p!=Head);
}

void recursiveDisplay(struct Node *p){
    static int flag = 0;
    if(p!=Head || flag==0){
        flag = 1;
        printf(" %d ", p->data);
        display(p->next);
    }
    flag = 0; // just restoring the defaults
}

int countingNodes(struct Node *p){
    int count = 0;
    do{
        count++;
        p = p->next;
    }while (p!=Head);
    return count;
}

void insert(struct Node *p, int position, int x){
    if(position < 0 || position > countingNodes(p)){
        return;
    }
    
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(position == 0){
        t->next = Head;
        while (p->next != Head) {
            p = p->next;
        }
        p->next = t;
        Head = t;
    }
    else{
        for(int i=1; i<position; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void delete(struct Node *p, int position){
    
    if(position < 0 || position > countingNodes(p)){
        return;
    }

    if(position == 0){
        while (p->next != Head) {
            p = p->next;
        }
        p->next = Head->next;
        free(Head);
        Head = p->next;
    }
    
    else{
        struct Node *q=NULL;
        for(int i=1; i<=position; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
    }
}

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);
    create(A, n);
//    recursiveDisplay(Head);
    insert(Head, 0, 6);
    insert(Head, 3, 7);
    display(Head);
    delete(Head, 3);
    printf("\n");
    display(Head);
    return 0;
}
