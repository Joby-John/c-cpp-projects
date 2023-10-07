#include<stdio.h>


float avg(int a, int b, int c)
{
    float avg;
    avg = (float)(a+b+c)/3;
    return avg;
}

void main()
{
    int a,b,c ;
    printf("Enter the value of a:- ");
    scanf("%d",&a);
    printf("Enter the value of b:- ");
    scanf("%d",&b);
    printf("Enter the value of c:- ");
    scanf("%d",&c);
    printf("average = %.2f", avg(a,b,c));
}