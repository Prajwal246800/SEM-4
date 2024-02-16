/*
    Algorithm SequentialSearch(A[0..n-1], K)
    // Searches for a given value in a given array by sequential search
    // Input: An array A[0..n-1] and a search key K
    // Output: Returns the index of the first element of A that matches K or –1 if there are no matching elements

    1. Set i to 0 // Initialize index i to start from the beginning of the array
    2. while i < n and A[i] ≠ K do // Iterate through the array until either the end is reached or a match is found
    3.     Increment i by 1 // Move to the next element in the array
    4. if i < n then // Check if a match is found before reaching the end of the array
    5.     return i // Return the index of the first element that matches K
    6. else // If no match is found
    7.     return -1 // Return -1 to indicate that the key is not found in the array
*/
#include<stdio.h>
int sequentialSearch(int array[], int k)
{
    if
}
int main()
{

}

/*
#include<stdio.h>
int sequentialSearch(int array[], int n , int key)
{
    int i = 0;
    while(i < n)
    {
        if(array[i] == key) return i;
        i++;
    }
    return -1;
}.
int main()
{
    int array[] = {3,1,10,4,7,9,6,2,8,5};
    int n = 10;
    int key = 0;
    printf("Enter Key to search : ");
    scanf("%d", &key);
    int ans = sequentialSearch(array, n, key);
    ans != -1 ? printf("The Key Element Found At Position : %d\n", ans) : printf("The Key Element Not Found");
}
*/