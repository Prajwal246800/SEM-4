/*
    Aaryan is in a treasure hunt game, there is a digital lock whose password is the single digit which is sum of digits of a number. If the sum of digits exceeds 9 then that new number’s digits sum is the password.To help Aaryan write a recursive C program to find the sum of digits of a number N.
    Input Format
        1st line – N an integer
    Constraints
        N is positive Integer
    Output Format
        Single Integer

    Sample Input 0
        23
    Sample Output 0
        5
    Explanation 0
        2 + 3 = 5
*/

#include <stdio.h>
int NumberSum(int n)// should be recursive function
{
// Write your code here
    int sum = 0;
    while(n){
        sum+=n%10;
        n=n/10;
    }
    if(sum > 9)
        sum = NumberSum(sum);
    return sum;
}
// Driver code
int main()
{
    int n, sum;
    scanf("%d", &n);
    sum = NumberSum(n);
    printf("%d\n",sum);
    return 0;
}