//
//  main.cpp
//  LinkedListCpp
//
//  Created by Aman Bhardwaj on 12/7/19.
//  Copyright © 2019 Projects. All rights reserved.
//
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
    Node *first;
public:
    LinkedList(){first = nullptr;}
    LinkedList(int A[], int n);
    ~LinkedList();
    
    void display();
    
    void insert(int index, int x);
    
    int deleteSomething(int index);
    
    int length();
    
};

LinkedList::LinkedList(int A[], int n)
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

LinkedList::~LinkedList()
{
    Node *p = first;
    while(first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::display()

{
    Node *p = first;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int LinkedList::length()
{
    Node *p = first;
    int len=0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::insert(int index, int x)       // inserting from the last
{
    Node *last=first;
    for(int i=1; i<length();i++)
    {
        last = last->next;
    }
    Node *t = (Node *)malloc(sizeof(Node));
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

int LinkedList::deleteSomething(int index)
{
    Node *q=NULL,*p=first;
    int x;
    if(index==1)
    {
        x = p->data;
        first = p->next;
        delete(p);
        return x;
    }
    for(int i=1; i<index && p; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete(p);
    return x;
}

int main()
{
    LinkedList ll;
    ll.insert(1, 10);
    ll.insert(2, 20);
    ll.insert(3, 30);
    ll.insert(4, 40);
    ll.insert(5, 50);
    
    cout<<" deleted -> "<<ll.deleteSomething(4)<<endl;
    cout<<" length-> "<<ll.length()<<endl;

    ll.display();
    
    return 0;
}
