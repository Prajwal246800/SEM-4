#include <stdio.h>

unsigned long long int calculateProduct(int n)
{
    unsigned long long int product = 1;
    for (int i = 1; i <= n; ++i)
    {
        product *= i;
    }
    return product;
}
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0)
    {
        printf("Factorial for negative numbers is undefined.\n");
    }
    else
    {
        unsigned long long int result = calculateProduct(num);
        printf("Product of numbers from 1 to %d is: %llu\n", num, result);
    }
    return 0;
}