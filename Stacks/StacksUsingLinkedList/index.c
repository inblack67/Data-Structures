#include <stdio.h>
#include <stdlib.h>

struct Node
{
int data;
struct Node *next;
}*Top = NULL;


void push(int x)
{
struct Node *t;
t = (struct Node*)malloc(sizeof(struct Node));

if(t == NULL)   // node is not created
{
printf("Stack Overflow \n");
}
else
{
t->data = x;
t->next = Top;
Top = t;
}
}

void display()
{
struct Node *p;
p = Top;
while(p)
{
printf(" %d ", p->data);
p = p->next;
}
}

int pop()
{
int x = -1;

struct Node *p;

if(Top == NULL)
{
printf("Stack Underflow");
}

else
{
p = Top;
Top = Top->next;
x = p->data;
free(p);
}

return x;
}

int main()
{
struct Node *st;
push(10);
push(20);
push(30);
push(40);
push(50);

display();

printf(" \n popped %d \n",pop());
printf(" \n popped %d \n",pop());
printf(" \n popped %d \n",pop());
printf(" \n popped %d \n",pop());
printf(" \n popped %d \n",pop());
printf(" \n popped %d \n",pop());

return 0;
}