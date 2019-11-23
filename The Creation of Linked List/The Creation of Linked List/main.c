//
//  main.c
//  The Creation of Linked List
//
//  Created by Aman Bhardwaj on 11/23/19.
//  Copyright © 2019 Projects. All rights reserved.
//

#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
} *first;

void Create(int A[], int n)
{
    int i;
    struct Node *t;
    struct Node *last;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void RecursiveDisplay(struct Node *p)
{
    if(p)
    {
        printf(" %d ",p->data);
        RecursiveDisplay(p->next);
    }
}


int main()
{
    int A[5] = {1,2,3,4,5};
    Create(A,5);
    //Display(first);
    RecursiveDisplay(first);
    return 0;
    
}
