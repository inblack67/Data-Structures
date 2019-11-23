//
//  main.c
//  The Creation of Linked List
//
//  Created by Aman Bhardwaj on 11/23/19.
//  Copyright © 2019 Projects. All rights reserved.
//

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

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

int Count(struct Node *p)
{
    int count = 0;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int RecursiveCount(struct Node *p)
{
    if(p)
        return RecursiveCount(p->next)+1;
    return 0;
}

int SumofElements(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int RecursvieSumOfElements(struct Node *p)
{
    if(p)
        return RecursvieSumOfElements(p->next)+p->data;
    return 0;
}

int Max(struct Node *p)
{
    int max = INT_MIN;
    while(p)
    {
        if(max<p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RecursiveMax(struct Node *p)
{
    int x = 0;
    if(p==NULL)
        return INT_MIN;
    else
    {
        x = RecursiveMax(p->next);    // Calling fn again and storing it's result in var x
        return x>p->data?x:p->data;   // if result(x) is > p->data return x else return p->data
    }
}

int Min(struct Node *p)
{
    int min = INT_MAX;
    while(p)
    {
        if(min>p->data)
            min = p->data;
        p = p->next;
    }
    return min;
}

int RecursiveMin(struct Node *p)
{
    int x = 0;
    if(p==NULL)
        return INT_MIN;
    else
    {
        x = RecursiveMax(p->next);    // Calling fn again and storing it's result in var x
        return x<p->data?x:p->data;   // if result(x) is > p->data return x else return p->data
    }
}

struct Node * LinearSearch(struct Node *p, int key)
{
    while(p)
    {
        if(p->data==key)
            return p;
        p = p->next;
    }
    
    return NULL;
}

struct Node * RecursiveLinearSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    else
        return RecursiveLinearSearch(p->next, key);
}

struct Node * ImprovedLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p)
    {
        if(key==p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
        
    }
    return NULL;
}


int main()
{
    int A[5] = {1,2,3,4,5};
    Create(A,5);
    //Display(first);
    //RecursiveDisplay(first);
    //printf(" Number of Nodes -> %d ", Count(first));
    //printf(" Number of Nodes -> %d ", RecursiveCount(first));
    //printf(" Sum of Elements in the LL -> %d \n",SumofElements(first));
    //printf(" Sum of Elements in the LL -> %d \n",RecursvieSumOfElements(first));
    //printf(" Max Element in the LL -> %d \n",Max(first));
    //printf(" Max Element in the LL -> %d \n",RecursiveMax(first));
    //printf(" Min Element in the LL -> %d \n",Min(first));
    //printf(" Min Element in the LL -> %d \n",RecursiveMin(first));
    //printf(" %d Found at -> %p in the LL \n",4, LinearSearch(first,4));
    //printf(" %d Found at -> %p in the LL \n",4, RecursiveLinearSearch(first, 4));
    printf(" %d Found at -> %p in the LL \n",4, ImprovedLinearSearch(first, 4));
    Display(first);
    
    return 0;
    
}
