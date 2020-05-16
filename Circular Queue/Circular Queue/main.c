#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int x){
    if(((q->rear+1)%q->size) == q->front){
        printf("Queue is full");
        return;
    }
    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = x;
}

void dequeue(struct Queue *q){
    if(q->front == q->rear){
        printf("Queue is empty");
        return;
    }
    q->front = (q->front+1)%q->size;
}

void display(struct Queue q){
    int i = q.front+1;
    do {
        printf(" %d ", q.Q[i]);
        i = (i+1)%q.size;
    } while (i != (q.rear+1) % q.size);
}


int main() {
    struct Queue q;
    printf("Enter size of the queuen\n");
    scanf("%d", &q.size);
    q.Q = (int *)malloc(sizeof(int) * q.size);
    q.front = q.rear = -1;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    dequeue(&q);
    display(q);
    return 0;
}
