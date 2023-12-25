#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    long long int result = factorial(number);
    printf("%d! = %lld\n", number, result);
    return 0;
}


/*

1.Function: factorial(n)
Input: An integer n
Output: The factorial of n
Steps:
Base case: If n is equal to 0, return 1 (0! is 1).
Recursive case: Otherwise, return n multiplied by the factorial of n-1.
    This means the function calls itself with a smaller value of n until it reaches the base case.

2. Main program:
Step 1: Declare an integer variable number to store the user input.
Step 2: Use printf to prompt the user to enter a number and store the input in number using scanf.
Step 3: Call the factorial(number) function and store the returned value in the long long integer variable result.
Step 4: Use printf to print the factorial of the number entered by the user in the format "n! = result".
Step 5: Return 0 to indicate successful program execution.

*/