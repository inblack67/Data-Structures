//
//  main.c
//  Multiple Linkedlists
//
//  Created by Aman Bhardwaj on 11/26/19.
//  Copyright © 2019 Projects. All rights reserved.
//

#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first,*second;


void Display(struct Node *p)
{
    while(p)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

void FirstSortedInsertion(struct Node *p, int x)
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

void SecondSortedInsertion(struct Node *p, int x)
{
    struct Node *tail = NULL;
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(second==NULL)
        second = t;
    else
    {
    while(p && p->data<x)
    {
        tail = p;
        p = p->next;
    }
    if(p==second)
    {
        t->next = second;
        second = t;
    }
    else
    {
    t->next = tail->next;
    tail->next = t;
    }
    }
}



void Concat(struct Node *p ,struct Node *q)
{
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}

void Merge(struct Node *p, struct Node *q)
{
    
}

int main()
{
    FirstSortedInsertion(first, 1);
    FirstSortedInsertion(first, 2);
    SecondSortedInsertion(second, 5);

    
    SecondSortedInsertion(second, 3);
    SecondSortedInsertion(second, 4);
    //SecondSortedInsertion(second, 5);

    
    Concat(first, second);
    Display(first);

    return 0;
}















/*
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
 */
