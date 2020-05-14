#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

struct Node{
    int data;
    struct Node *next;
}*First=NULL;

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

void display(){
    struct Node *p = First;
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

int main(){
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);
    create(A, n);
//    display();
    struct Node *p = First;
//    recursiveDisplay(p);
//    printf(" %d ", countingNodes(p));
//    printf(" %d ", recursiveCounting(p));
//    printf(" %d ", sumOfAllElements(p));
//    printf(" %d ", recursiveSum(p));
//    printf(" %d ", maxNode(p));
    printf("Found at %p ", linearSearch(p, 5));
    return 0;
}
