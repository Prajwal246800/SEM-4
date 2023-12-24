#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
struct Stack
{
    int items[MAX_SIZE];
    int top;
};
struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
bool isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, int value)
{
    if (stack->top == MAX_SIZE - 1)
        printf("Stack is full!\n");
    else
    {
        stack->top++;
        stack->items[stack->top] = value;
    }
}
int pop(struct Stack* stack)
{
    int item;
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    else
    {
        item = stack->items[stack->top];
        stack->top--;
        return item;
    }
}
void DFS(int adjMatrix[][MAX_SIZE], int vertices, int startVertex)
{
    struct Stack* stack = createStack();
    bool visited[MAX_SIZE];
    int i, currentVertex;
    for (i = 0; i < vertices; i++)
    {
        visited[i] = false;
    }
    push(stack, startVertex);
    visited[startVertex] = true;
    printf("Depth First Search starting from vertex %d: ", startVertex);
    while (!isEmpty(stack))
    {
        currentVertex = pop(stack);
        printf("%d ", currentVertex);
        for (i = 0; i < vertices; i++)
        {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                push(stack, i);
                visited[i] = true;
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
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    DFS(adjMatrix, vertices, startVertex);
    return 0;
}