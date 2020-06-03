#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int data;
    struct Queue *next;
}*Front=NULL,*Rear=NULL;

void enqueue(int x){
    struct Queue *t = (struct Queue *)malloc(sizeof(struct Queue));
    if(t == NULL){
        printf("Queue is full");
        return;
    }
    t->data = x;
    t->next = NULL;
    if(Front == NULL){
        Front = Rear = t;
    }
    else{
        Rear->next = t;
        Rear = t;
    }
}

void dequeue(){
    if(Front == NULL){
        printf("Queue is empty");
        return;
    }
    struct Queue *q = Front;
    Front = Front->next;
    free(q);
}

void display(struct Queue *q){
    while (q) {
        printf(" %d ", q->data);
        q = q->next;
    }
}


int main() {
    
//    enqueue(1);
//    enqueue(2);
//    enqueue(3);
//    enqueue(4);
//    enqueue(5);
//    dequeue();
//    dequeue();
//    dequeue();
//    display(Front);
    char str[] = "gate";
    printf("%c\n", str[0]);
    return 0;
}











// =================    QUEUE USING ARRAY   ===============


//#include <stdio.h>
//#include <stdlib.h>
//
//struct Queue{
//    int size;
//    int front;
//    int rear;
//    int *Q;
//};
//
//void enqueue(struct Queue *q, int x){
//    if(q->rear == q->size - 1){
//        printf("Queue is full");
//        return;
//    }
//    q->rear++;
//    q->Q[q->rear] = x;
//}
//
//void dequeue(struct Queue *q){
//    if(q->front == q->rear){
//        printf("Queue is empty");
//        return;
//    }
//    q->front++;
//}
//
//void display(struct Queue q){
//    for (int i=q.front+1; i <= q.rear; i++) {
//        printf(" %d ", q.Q[i]);
//    }
//}
//
//
//int main() {
//    struct Queue q;
//    printf("Enter size of the queuen\n");
//    scanf("%d", &q.size);
//    q.Q = (int *)malloc(sizeof(int) * q.size);
//    q.front = q.rear = -1;
//    enqueue(&q, 1);
//    enqueue(&q, 2);
//    enqueue(&q, 3);
//    enqueue(&q, 4);
//    enqueue(&q, 5);
//    dequeue(&q);
//    display(q);
//    return 0;
//}
