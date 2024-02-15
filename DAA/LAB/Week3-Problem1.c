#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printPermutation(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void johnsonTrotter(int *arr, int *dir, int n)
{
    int *dirChange = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        dirChange[i] = -1;
    }
    printPermutation(arr, n);
    int mobile, mobileIndex;
    while (1)
    {
        mobile = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 && dir[i] == -1) || (i == n - 1 && dir[i] == 1))
            {
                dir[i] = 0; 
            }
            if (i + dir[i] >= 0 && i + dir[i] < n && arr[i] > arr[i + dir[i]] && arr[i] > mobile)
            {
                mobile = arr[i];
                mobileIndex = i;
            }
        }
        if (mobile == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mobile)
            {
                dirChange[arr[i] - 1] = dir[i];
            }
        }
        swap(&arr[mobileIndex], &arr[mobileIndex + dir[mobileIndex]]);
        swap(&dir[mobileIndex], &dir[mobileIndex + dir[mobileIndex]]);
        printPermutation(arr, n);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mobile)
            {
                dir[i] = -dir[i];
            }
        }
    }
    free(dirChange);
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int *dir = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dir[i]);
    }
    johnsonTrotter(arr, dir, n);
    free(arr);
    free(dir);
    return 0;
}
