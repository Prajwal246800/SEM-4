#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
struct Queue
{
    int items[MAX_SIZE];
    int front;
    int rear;
};
struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
bool isEmpty(struct Queue* queue)
{
    return queue->rear == -1;
}
void enqueue(struct Queue* queue, int value)
{
    if (queue->rear == MAX_SIZE - 1)
        printf("Queue is full!\n");
    else
    {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}
int dequeue(struct Queue* queue)
{
    int item;
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    else
    {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        return item;
    }
}
void BFS(int adjMatrix[][MAX_SIZE], int vertices, int startVertex)
{
    struct Queue* queue = createQueue();
    bool visited[MAX_SIZE];
    int i, currentVertex;
    for (i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }
    visited[startVertex] = true;
    enqueue(queue, startVertex);
    printf("Breadth First Search starting from vertex %d: ", startVertex);
    while (!isEmpty(queue))
    {
        currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        for (i = 0; i < vertices; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                enqueue(queue, i);
            }
        }
    }
}
int main()
{
    int vertices, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int adjMatrix[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    BFS(adjMatrix, vertices, startVertex);
    return 0;
}