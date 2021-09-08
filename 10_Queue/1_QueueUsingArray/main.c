#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;

    q->Q = (int *) malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q,int x)
{
    if(q->rear == q->size)
        printf("Que is empty\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int *p;
    int x=-1;

    if(q->front == q->rear)
        printf("Queue is empty\n");
    else
    {

        q->front++;

        x = q->Q[q->front];

    }
    return x;
}

void Display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    int x;

    create(&q,5);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);

    x = dequeue(&q);

    Display(q);

    free(q.Q);



    return 0;
}
