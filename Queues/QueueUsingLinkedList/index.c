#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));

  if (t == NULL)
  {
    printf("Queue is full");
  }

  else
  {
    t->data = x;
    t->next = NULL;

    if (front == NULL)
    {

      front = t;
      rear = t;
    }

    else
    {
      rear->next = t;
      rear = t;
    }
  }
}

int dequeue()
{
  int x = -1;
  struct Node *p;

  if (front == NULL)
  {
    printf("Queue is empty");
  }

  else
  {
    p = front;
    front = front->next;
    x = p->data;
    free(p);
  }

  return x;
}

void display()
{
  struct Node *p;
  p = front;
  while (p)
  {
    printf(" %d ", p->data);
    p = p->next;
  }
}

int main()
{
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);

  dequeue();
  dequeue();
  dequeue();

  display();

  return 0;
}