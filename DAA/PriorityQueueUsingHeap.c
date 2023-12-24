#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
struct PriorityQueue
{
    int arr[MAX_SIZE];
    int size;
};
int getParentIndex(int index)
{
    return (index - 1) / 2;
}
int getLeftChildIndex(int index)
{
    return (2 * index) + 1;
}
int getRightChildIndex(int index)
{
    return (2 * index) + 2;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(struct PriorityQueue *pq, int index)
{
    int parentIndex = getParentIndex(index);
    while (index > 0 && pq->arr[parentIndex] > pq->arr[index])
    {
        swap(&pq->arr[parentIndex], &pq->arr[index]);
        index = parentIndex;
        parentIndex = getParentIndex(index);
    }
}
void enqueue(struct PriorityQueue *pq, int value)
{
    if (pq->size >= MAX_SIZE)
    {
        printf("Priority Queue is full.\n");
        return;
    }
    pq->arr[pq->size] = value;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}
void heapifyDown(struct PriorityQueue *pq, int index)
{
    int smallest = index;
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);
    if (left < pq->size && pq->arr[left] < pq->arr[smallest])
    {
        smallest = left;
    }
    if (right < pq->size && pq->arr[right] < pq->arr[smallest])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        swap(&pq->arr[index], &pq->arr[smallest]);
        heapifyDown(pq, smallest);
    }
}
int dequeue(struct PriorityQueue *pq)
{
    if (pq->size <= 0)
    {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    int removed = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return removed;
}
void display(struct PriorityQueue *pq)
{
    printf("Priority Queue: ");
    for (int i = 0; i < pq->size; i++)
    {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct PriorityQueue pq;
    pq.size = 0;
    enqueue(&pq, 30);
    enqueue(&pq, 10);
    enqueue(&pq, 20);
    enqueue(&pq, 5);
    display(&pq);
    printf("Dequeued item: %d\n", dequeue(&pq));
    display(&pq);
    return 0;
}