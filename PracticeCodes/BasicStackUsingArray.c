#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Stack
{
    int items[MAX_SIZE];
    int top;
};
void initializeStack(struct Stack* stack)
{
    stack->top = -1;
}
bool isFull(struct Stack* stack)
{
    return stack->top == MAX_SIZE - 1;
}
bool isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void push(struct Stack* stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
        return;
    }
    stack->items[++stack->top] = value;
    printf("%d pushed to stack.\n", value);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int main()
{
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Remaining elements in the stack:\n");
    while (!isEmpty(&stack))
    {
        printf("%d\n", pop(&stack));
    }
    return 0;
}