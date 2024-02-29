/*
    Consider the following algorithm for finding the distance between the two closest elements in 
    an array of numbers. 
    ALGORITHM MinDistance(A[0..n − 1]) 
        //Input: Array A[0..n − 1] of numbers 
        //Output: Minimum distance between two of its elements 
        dmin ← ∞
        for i ← 0 to n − 1 do 
            for j ←0 to n−1 do
                if i  ̸ =j and |A[i]−A[j]| < dmin 
            d m i n ← | A [ i ] − A [ j ]| 
        return dmin 
*/

#include <stdio.h>
#include <stdlib.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int minDistance(int A[], int n)
{
    int dmin = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int distance = abs(A[i] - A[j]);
            dmin = min(dmin, distance);
        }
    }
    return dmin;
}

int main()
{
    int A[] = {1, 4, 7, 2, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int minDist = minDistance(A, n);
    printf("Minimum distance between two elements: %d\n", minDist);   // answer Should Be 1 since Difference Between 1 and 2 is minimum i.e 1
    return 0;
}
