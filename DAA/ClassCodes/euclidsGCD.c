#include<stdio.h>
int Euclid(int x, int y)
{
    if(x%y == 0) return y;
    else return Euclid(y, x%y);
}
int  main()
{
    printf("Enter Two Numbers To find GCD using Euclid's algorithm : ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("The Answer is %d",Euclid(a,b));
}