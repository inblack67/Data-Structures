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
  q->front = q->rear = 0;   // its circular.
}

void enqueue(struct Queue *q, int x)
{
  if((q->rear+1)%q->size == q->front)
  {
    printf("Queue Overflow");
  }
  
  else
  {
    q->rear = (q->rear + 1)%q->size;
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
    q->front = (q->front + 1)%q->size;
    x = q->Q[q->front];
  }
  return x;
}

void display(struct Queue q)
{
  int i = q.front+1;
  do
  {
    printf(" %d ", q.Q[i]);
    i = (i+1)%q.size;
  } while (i != (q.rear + 1)%q.size);
  
}


int main()
{
  struct Queue q;
  create(&q);

  enqueue(&q,1);
  enqueue(&q,2);
  enqueue(&q,3);
  enqueue(&q,4);
  enqueue(&q,5);

  // FIFO
  printf("\n dequeue is here \n");
  dequeue(&q);
  dequeue(&q);

  display(q);

  return 0;
}