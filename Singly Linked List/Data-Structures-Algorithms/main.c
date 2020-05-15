#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

struct Node{
    int data;
    struct Node *next;
}*First=NULL, *Second=NULL, *Third=NULL;

void create(int A[], int n){
    struct Node *t, *last;
    First = (struct Node *)malloc(sizeof(struct Node));
    First->data = A[0];
    First->next = NULL;
    last = First;
    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int A[], int n){
    struct Node *t, *last;
    Second = (struct Node *)malloc(sizeof(struct Node));
    Second->data = A[0];
    Second->next = NULL;
    last = Second;
    for(int i=1; i<n; i++){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while (p) {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void recursiveDisplay(struct Node *p){
    if(p){
        printf(" %d ", p->data);
        recursiveDisplay(p->next);
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

int recursiveCounting(struct Node *p){
    if(!p){
        return 0;
    }
    else{
        return recursiveCounting(p->next) + 1;
    }
}

int sumOfAllElements(struct Node *p){
    int sum = 0;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int recursiveSum(struct Node *p){
    if(!p){
        return 0;
    }
    else{
        return recursiveSum(p->next) + p->data;
    }
}

int maxNode(struct Node *p){
    int max = INT_MIN;
    while (p) {
        if(p->data > max){
            max = p->data;
            p = p->next;
        }
    }
    return max;
}

struct Node * linearSearch(struct Node *p, int key){
    while (p) {
        if(p->data == key){
            return p;
        }
        else{
            p = p->next;
        }
    }
    return NULL;
}

void insertion(struct Node *p, int position, int x){
    if(countingNodes(p) < position || position < 0){
        return;
    }
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(position == 0){
        t->next = First;
        First = t;
    }
    else{
        for(int i=0; i<position-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insertLast(struct Node *p, int x){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    struct Node *last = First;
    for (int i=1; i<countingNodes(First); i++) {
        last = last->next;
    }
    if(First == NULL){
        First = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}


void reverse(struct Node *p){
    struct Node *q = NULL,*r = NULL;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    First = q;
}

void recursiveReverse(struct Node *p, struct Node *q){
    if(p){
        recursiveReverse(p->next, p);
        p->next = q;
    }
    else{
        First = q;
    }
}


void concat(struct Node*p, struct Node *q){
    while (p->next) {
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data < q->data){
        Third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        Third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q) {
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p){
        last->next = p;
    }
    if(q){
        last->next = q;
    }
}

int hasLoop(struct Node *first){
    struct Node *q, *r;
    q = r = first;
    do {
        r = r->next;
        q = q->next;
        if(q){
            q = q->next;
        }
    }while (q && r && q!=r);
    if(q == r){
        return 1;
    }
    
    return -1;
}

int middleNode(struct Node *p){
    int count = countingNodes(p);
    for (int i=0; i<count/2; i++) {
        p = p->next;
    }
    
    return p->data;
}

int singleScanMiddleNode(struct Node *p){
    struct Node *q = p;
    while (q) {
        q = q->next;
        if(q){
            q = q->next;
            p = p->next;    // for every 1 move of p, 1 moves of q
        }
    }
    return p->data;
}

int main(){
    int A[] = {6,7,8,9,11};
    int n = sizeof(A)/sizeof(int);
    create(A, n);
//    display(First);
//    struct Node *p = First;
//    recursiveDisplay(p);
//    printf(" %d ", countingNodes(p));
//    printf(" %d ", recursiveCounting(p));
//    printf(" %d ", sumOfAllElements(p));
//    printf(" %d ", recursiveSum(p));
//    printf(" %d ", maxNode(p));
//    printf("Found at %p ", linearSearch(p, 5));
//    insertion(p, 0, 6);
//    insertLast(First, 1);
//    insertLast(First, 2);
//    insertLast(First, 3);
//    insertLast(First, 4);
//    insertLast(First, 5);
//    reverse(First);
//    recursiveReverse(First, NULL);
//    int B[] = {5,10,15,20,25};
//    create2(B, 5);
//    concat(First, Second);
//    merge(First, Second);
////    display(Third);
//    struct Node *t1,*t2;
//    t1 = First->next->next;
//    t2 = First->next->next->next->next;
//    t2->next = t1;
//    printf("%d\n", hasLoop(First));
    
//    printf(" %d ", middleNode(First));
    printf(" %d ", singleScanMiddleNode(First));
//    display(First);
    
    return 0;
}
