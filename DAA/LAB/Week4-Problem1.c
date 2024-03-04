/*
    An adventurer has landed upon a hidden treasure in an ancient city of Babilonia.
    The code to unlock the treasure is sequence of numbers that has been rotated.
    Your task is to write a C program to check if a specific target number that the adventurer has in his mind,
    is present or not in this twisted array of code using the concept of binary search.
    The code array was originally sorted in non-decreasing order but has been rotated now.
    Complete the function ‘searchForNumber’ that takes the rotated array of distinct integers of size N,
    and target number T. If the target number is found in the array,
    the program should return the sum of mid elements identified till the number was found else it should return -1.
    Input Format
        1st line - length of code_array N 2nd line - N code_array Integers 3rd line – target Integer
    Constraints
        N<20
    Output Format
        Int sum_of_mids or -1
    Sample Input 0
        7
        4 5 6 0 1 2 3
        1
    Sample Output 0
        12
    Explanation 0
        mid1= 3 (low=0, high=6) mid2= 5 (low=4, high=6) mid3= 4 (low=4, high=4) sum of mids => 3+5+4 = 12
    Sample Input 1
        8
        7 8 9 10 1 2 4 6
        3
    Sample Output 1
        -1
*/

#include <stdio.h>

int searchForNumber(int N, int *arr, int T)
{
    int sum=0;
    int l=0, r=N-1,found=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        sum=sum+mid;
        if(arr[mid]==T)
        {
            found=sum;
        }
        if(arr[l]<=arr[mid])
        {
            
            if(arr[l]<=T && T<arr[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        else
        {
            
            if(arr[mid]<T && T<=arr[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
    return found;
}

int main()
{
    int N;
    scanf("%d",&N);
    int code_array[N];
    for(int i=0;i<N;i++)
        scanf("%d",&code_array[i]);
    int target;
    scanf("%d",&target);
    int res = searchForNumber(N, code_array, target);
    printf("%d",res);
    return 0;
}