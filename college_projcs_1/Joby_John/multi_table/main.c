#include<stdio.h>
#include<conio.h>

void main()
{
    int num,i;
    printf("Enter the number you want multiplication table for:- ");
    scanf("%d", &num);

    for(int i = 1; i<=10; i++)
    {
        printf("\n%dx%d = %d", num, i, num*i);
    }

    getch();
}