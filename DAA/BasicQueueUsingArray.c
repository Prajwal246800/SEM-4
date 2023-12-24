#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};
void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(struct Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}
int isFull(struct Queue *q)
{
    return (q->rear == MAX_SIZE - 1);
}
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->items[q->rear] = value;
}
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int dequeuedValue = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return dequeuedValue;
}
int main()
{
    struct Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, 3);
    enqueue(&queue, 5);
    enqueue(&queue, 9);
    printf("Dequeued item: %d\n", dequeue(&queue));
    printf("Dequeued items: ");
    while (!isEmpty(&queue))
    {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");
    return 0;
}