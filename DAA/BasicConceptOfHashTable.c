#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node
{
    int key;
    int value;
    struct Node *next;
};
struct HashTable
{
    struct Node *arr[SIZE];
};
struct Node *createNode(int key, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
int hashFunction(int key)
{
    return key % SIZE;
}
void insert(struct HashTable *hashTable, int key, int value)
{
    int index = hashFunction(key);
    struct Node *newNode = createNode(key, value);
    if (hashTable->arr[index] == NULL)
    {
        hashTable->arr[index] = newNode;
    }
    else
    {
        struct Node *temp = hashTable->arr[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(struct HashTable *hashTable)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Bucket %d: ", i);
        struct Node *temp = hashTable->arr[i];
        while (temp != NULL)
        {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    struct HashTable hashTable;
    for (int i = 0; i < SIZE; i++)
    {
        hashTable.arr[i] = NULL;
    }
    insert(&hashTable, 10, 20);
    insert(&hashTable, 25, 35);
    insert(&hashTable, 50, 60);
    insert(&hashTable, 40, 80);
    display(&hashTable);
    return 0;
}