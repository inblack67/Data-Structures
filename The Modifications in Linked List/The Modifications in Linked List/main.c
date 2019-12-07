//
//  main.c
//  The Modifications in Linked List
//
//  Created by Aman Bhardwaj on 11/24/19.
//  Copyright © 2019 Projects. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;          // self referential structures
} *first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t;
    struct Node *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void createSecond(int A[], int n)
{
    int i;
    struct Node *t;
    struct Node *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void display(struct Node *p)
{
    while(p)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void recursiveDisplay(struct Node *p)
{
    if(p)
    {
        printf(" %d ", p->data);
        display(p->next);
    }
        
}

int countingNodes(struct Node *p)
{
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int recursiveCount(struct Node *p)
{
    if(!p)
        return 0;
    return recursiveCount(p->next)+1;
}

int sumOfAllElements(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int recursivesumOfAllElements(struct Node *p)
{
    if(!p)
        return 0;
    return recursivesumOfAllElements(p->next)+p->data;
}

int maximumNode(struct Node *p)
{
    int max = 0;
    
    while(p)
    {
        if(p->data>max)
            max = p->data;
        p = p->next;
    }
    return max;
}

struct Node * linearSearch(struct Node *p, int key)
{
    while(p)
    {
        if(p->data==key)
            return p;
        p = p->next;
    }
    return NULL;
}

struct Node *recursiveLinearSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(p->data==key)
        return p;
    return recursiveLinearSearch(p->next,key);
}

struct Node * improvedLinearSearch(struct Node *p, int key)
{
    struct Node *q=NULL;
    
    while(p)
    {
        if(key==p->data)
        {
            q->next = p;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
    return p;
}

void insertion(struct Node *p, int x, int position)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(position<0 || position>countingNodes(first))
        return;
    if(position==1)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for(int i=1; i<position-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    
}

void insertLast(struct Node *p, int x)
{
    struct Node *last=first;
    for(int i=1; i<countingNodes(first);i++)
    {
        last = last->next;
    }
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next = NULL;
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void insertLastSecond(struct Node *p, int x)
{
    struct Node *last=second;
    for(int i=1; i<countingNodes(second);i++)
    {
        last = last->next;
    }
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next = NULL;
    if(second==NULL)
    {
        second=t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void sortedListInsertion(struct Node *p, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next = NULL;
    if(first==NULL)
    {
        t->next = first;
        first = t;
    }
    
    struct Node *q = NULL;
    while(p && p->data<x)
    {
        q=p;
        p = p->next;
    }
    t->next = q->next;
    q->next = t;
    
}

int delete(struct Node *p, int position)
{
    struct Node *q=NULL;
    int x;
    if(position==1)
    {
        x = p->data;
        first = p->next;
        free(p);
        return x;
    }
    for(int i=1; i<position && p; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
}

int isSorted(struct Node *p)
{
    int x = INT32_MIN;
    while(p)
    {
        if(p->data<x)
            return -1;
        x = p->data;            // p->data > x
        p = p->next;
    }
    return 1;
}

void removeDuplicates(struct Node *p)
{
    struct Node *q = p->next;               // q is not the tail anymore, it's one step ahead of p
    while(q)
    {
        if(p->data!=q->data)
        {
            p=q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

void reverseByAuxArray(struct Node *p)
{
    int A[countingNodes(first)];
    int i=0;
    while(p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while(p)
    {
        p->data = A[i];
        i--;
        p = p->next;
    }
}

void reverse(struct Node *p)        // by sliding pointers
{
    struct Node *q = NULL;
    struct Node *r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void recursiveReverse(struct Node *p,struct Node *q)
{
    if(p)
    {
        recursiveReverse(p->next, p);
        p->next = q;
    }
    else
        first=q;
}

void concat(struct Node *p, struct Node *q)
{
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

void merging(struct Node *p, struct Node *q)
{
    struct Node *last=NULL;
    
    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    
    else          // p->data > q->data
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    
    while(p && q)
    {
        if(p->data<q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else         // p->data > q->data
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    
    if(p)        // filling out the remaining elements
        last->next = p;
    if(q)
        last->next = q;
    
}

int isLoop(struct Node *f)
{
    struct Node *p=NULL,*q=NULL;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        if(q)
            q = q->next;
        
    }while(p && q && p!=q);

    if(p==q)
        return 1;
    else
        return -1;
}

int main()
{

    insertLast(first, 10);
    insertLast(first, 20);
    insertLast(first, 30);
    insertLast(first, 40);
    insertLast(first, 50);
    
//    insertLastSecond(second, 5);
//    insertLastSecond(second, 154);
//    insertLastSecond(second, 255);
//    insertLastSecond(second, 356);
//    insertLastSecond(second, 457);
    
    // let's form a loop
    struct Node *t1,*t2;
    
    t1 = first->next->next;
    t2 = first->next->next->next->next;     // t2 points to last
    t2->next = t1;        // loop formed, 50 to 30
    printf(" %d ",isLoop(first));

//    merging(first, second);
    
    //display(first);
  
    //concat(first, second);
    
    //display(first);
    //printf("\n");
//    removeDuplicates(first);
//    display(first);
    //reverseByAuxArray(first);
//    reverse(first);
    //recursiveReverse(first, NULL);
    
    
//    sortedListInsertion(first, 56);
//    sortedListInsertion(first, 6);
//    sortedListInsertion(first, 47);
//    sortedListInsertion(first, 33);

    
//    printf("\n");
//    printf("Sorted or not? %d ",isSorted(first));
   //delete(first, 8);
//    delete(first, 8);
//    delete(first, 7);
//    delete(first, 6);
//

//    display(first);
//    printf("\nYour key found at %p \n",improvedLinearSearch(first, 4));
//    display(first);         // 4 moved to front
//    printf("\nYour key found at %p \n",improvedLinearSearch(first, 4));
//    display(first);
    //printf("Your key found at %p ",recursiveLinearSearch(first, 4));
    //printf("Your key found at %p ",linearSearch(first, 4));
    //-printf("Maximum node is -> %d ", maximumNode(first));
    //printf("Sum of all elements -> %d ",recursivesumOfAllElements(first));
    //printf("Sum of all elements -> %d ",sumOfAllElements(first));
    //printf("No. of Nodes -> %d ",recursiveCount(first));
    //printf("No. of Nodes -> %d ",countingNodes(first));
    //display(first);
    //recursiveDisplay(first);
    
    return 0;
}
