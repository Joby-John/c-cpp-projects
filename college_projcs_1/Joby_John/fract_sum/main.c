#include<stdio.h>
#include<conio.h>

void main()
{
    int N, numerator = 1, denominator = 1, simp_denominator;
    printf("To find the sum upto nth term of series 1+1/2+1/3...1/N\nEnter the value of N:- ");
    scanf("%d",&N);
    for(int i =2; i<= N; i++)
    {
        numerator = numerator*i + denominator;
        denominator *= i;
    }

    printf("Sum = %d/%d\n",numerator ,denominator);

    simp_denominator = denominator;

    for(int i = 2; i<=denominator; i++)
    {
        if((numerator%i==0)&&(denominator%i==0))
        {
            numerator /= i;
            simp_denominator /= i;
        }
    }

    printf("The simplified form = %d/%d", numerator,simp_denominator);
getch();
}