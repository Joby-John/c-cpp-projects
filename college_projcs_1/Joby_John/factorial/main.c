#include<stdio.h>
#include<conio.h>


void main()
{
    int num,i=1;
    double fact = 1;
    printf("Enter the number you want to calculate factorial for:- ");
    scanf("%d", &num);

    if(num == 0)
    {
        printf("\nfactorial of %d is 1", num);
    }
    else{

        while(i<=num)
        {
            fact *= i;
            i++;

        }
        printf("\nThe factorial of %d is :- %.0f", num , fact);
    }

getch();
}