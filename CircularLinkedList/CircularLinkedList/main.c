//
//  main.c
//  CircularLinkedList
//
//  Created by Aman Bhardwaj on 12/7/19.
//  Copyright © 2019 Projects. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n)
{
    int i;
    struct Node *t,*last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    
    for(i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;

    }
}

void display(struct Node *h)
{
    do
    {
        printf(" %d ", h->data);
        h = h->next;
        
    }while(h!=Head);
}

void recursiveDisplay(struct Node *h)
{
    static int flag = 0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf(" %d ",h->data);
        recursiveDisplay(h->next);
    }
    flag=0;
}

int length(struct Node *h)
{
    int count=0;
    do
    {
        count++;
        h = h->next;
        
    }while(h!=Head);
    return count;
}

void insert(struct Node *h, int position, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if(position<0 || position>length(Head))
        return;
        
    if(position==0)
    {
        if(Head==NULL)      // empty circular ll -> head is null
        {
            Head = t;
            Head->next = Head;
        }
        else        // before head insertion
        {
            h = Head;
            while(h->next!=Head)
                h = h->next;
            h->next = t;
            t->next = Head;
        }
    }
    
    else
    {
        for(int i=0; i<position-1;i++)
        {
            h = h->next;
        }
        t->next = h->next;
        h->next = t;
    }
}

int deletion(struct Node *h, int position)
{
    int x;
    struct Node *p,*q;
    
    if(position<=0 || position > length(Head))
        return -1;
    
    if(position==1)
    {
        p = Head;
        while(p!=Head)
        {
            p = p->next;
        }
        x = Head->data;
        if(p==Head)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        p = Head;
        for(int i=0; i<position-2 ;i++)
        {
            p = p->next;
        }
        q = p->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A, 5);
    printf(" \n ");
    //insert(Head, 0, 17);
    printf(" %d got deleted ",deletion(Head,1));
    recursiveDisplay(Head);
    //printf(" %d ",length(Head));
    //display(Head);
    
    return 0;
}
