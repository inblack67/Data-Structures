#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q)
{
  printf("Enter the size of the queue");
  scanf("%d", &q->size);
  q->Q = (int *)malloc(q->size*(sizeof(struct Queue)));
  q->front = q->rear = -1;
}

void enqueue(struct Queue *q, int x)
{
  if(q->rear == q->size-1)
  {
    printf("Queue Overflow");
    return;
  }

  else
  {
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct Queue *q)
{
  int x = -1;
  if(q->rear == q->front)
  {
    printf("Queue Underflow");
  }
  else
  {
    q->front++;
    x = q->Q[q->front];
  }
  return x;
}

void display(struct Queue q)
{
  for(int i=q.front+1; i<=q.rear; i++)
  {
    printf(" %d ", q.Q[i]);
  }
}


int main()
{
  struct Queue q;
  create(&q);
  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);
  enqueue(&q, 6);
  dequeue(&q);
  display(q);

  return 0;
}