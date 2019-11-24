//
//  main.c
//  The Modifications in Linked List
//
//  Created by Aman Bhardwaj on 11/24/19.
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


void Display(struct Node *p)
{
    while(p)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void Insert(struct Node *p, int position, int x)
{
    struct Node *t,*y;
    if(position<0 || position > Count(first))
        return;
    
    if(position==0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = first;
        first = t;
    }
    
    else
    {
        y = first;
        for(int i=0; i<position-1; i++)
        {
            y = y->next;
        }
        
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->next = y->next;
            y->next = t;
        
    }
    
}

void InsertLast(struct Node *p, int x)
{
    struct Node *last = first;
    for(int i=1;i<Count(first); i++)
    {
        last = last->next;
    }

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(first==NULL)
    {
        first = t;
        last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void SortedInsertion(struct Node *p, int x)
{
    struct Node *tail = NULL;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(first==NULL)
        first = t;
    else
    {
    while(p && p->data<x)
    {
        tail = p;
        p = p->next;
    }
    if(p==first)
    {
        t->next = first;
        first = t;
    }
    else
    {
    t->next = tail->next;
    tail->next = t;
    }
    }
}

void MySortedInsertion(struct Node *p, int x)
{
    //struct Node *head = first;
    struct Node *tail = NULL;
    
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first==NULL)
    {
        first = t;
    }
    else
    {
        for(int i=0; i<Count(first);i++)
        {
            if(p->data<x)
            {
                tail = p;
                p = p->next;
            }
        }
        
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = tail->next;
            tail->next = t;
        }
    }
}

int Deletion(struct Node *p, int position)
{
    struct Node *tail = NULL;
    int x = -1;
    
    if(position<1 || position>Count(first))
        return -1;
    
    if(position==1)
    {
        tail = first;
        first = first->next;
        x = first->data;
        //p = NULL;
        free(tail);
        return x;
    }
    
    else
    {
        for(int i=0; i<position-1; i++)
        {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
    
}

int IsSorted(struct Node *p)
{
    int x = INT_MIN;
    while(p)
    {
        if(p->data<x)
            return -1;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void RemoveDuplicates(struct Node *p)       // must be sorted first
{
    struct Node *q = p->next;    // one node head of p
    
    while(q)
    {
        if(p->data!=q->data)
        {
            p = q;
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

void Reverse(struct Node *p)    // auxiliary array creation
{
    int i=0;
    int A[Count(first)];
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

void ReverseWithSlidingPointers(struct Node *p)         // without creating auxiliary array
{
    struct Node *tail1 = NULL;
    struct Node *tail2 = NULL;
    while(p)
    {
        tail2 = tail1;
        tail1 = p;
        p = p->next;
        tail1->next = tail2;
    }
    
    first = tail1;

}


void RecursiveReverse(struct Node *q,struct Node *p)
{
    if(p)
    {
        RecursiveReverse(p,p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{   // We don't need the creation and the creator(Chuck) anymore.Dot.
    
    MySortedInsertion(first, 1);
    MySortedInsertion(first, 1);
    MySortedInsertion(first, 2);
    MySortedInsertion(first, 2);
    MySortedInsertion(first, 3);
    MySortedInsertion(first, 4);
    MySortedInsertion(first, 2);
    MySortedInsertion(first, 5);
//
    RemoveDuplicates(first);
//    Display(first);
    
//    Reverse(first);
//    ReverseWithSlidingPointers(first);

    RecursiveReverse(NULL, first);
    Display(first);
    
    
//    Insert(first, 0, 1);
//    Insert(first, 1, 2);
//    Insert(first, 2, 3);
//    Insert(first, 3, 4);
//    Insert(first, 4, 2);

    //printf(" \nThe result of IsSorted is -> %d ",IsSorted(first));
    
//    printf(" \n ");
//
//    Deletion(first, 0);
//    Deletion(first, 5);
//    Display(first);

//    Sorted(first, 78);
//    Sorted(first, 43);
    
    return 0;
    
}


