#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node *prev, *next;
}*First=NULL;

void create(int A[], int n){
    First = (struct Node *)malloc(sizeof(struct Node));
    First->data = A[0];
    First->next = NULL;
    First->prev = NULL;
    struct Node *last = First;
    for (int i=1; i<n; i++) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int countingNodes(struct Node *p){
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

void insertion(struct Node *p, int position, int x){
    if (position < 0 || position > countingNodes(p)) {
        return;
    }
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(position == 0){
        t->next = First;
        t->prev = NULL;
        First->prev = t;
        First = t;
    }
    else{
        for (int i=1; i<position; i++) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next = t;
    }
}

void deletion(struct Node *p, int position){
    if (position < 0 || position > countingNodes(p)) {
        return;
    }
    if(position == 0){
        First = p->next;
        First->prev = NULL;
        free(p);
    }
    else{
        for (int i=1; i<position; i++) {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->next;
        }
        free(p);
    }
}

void reverse(struct Node *p){
    struct Node *temp;
    while (p) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;    // as links are already changed;
        if(p && !p->next){
            First = p;
        }
    }
}

void display(struct Node *p){
    while (p) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);
    create(A, n);
//    insertion(First, 0, 6);
//    insertion(First, 6, 7);
//    deletion(First, 5);
    reverse(First);
    display(First);
    
    return 0;
}
