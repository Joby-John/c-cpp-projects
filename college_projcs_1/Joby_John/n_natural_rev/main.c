#include<stdio.h>
#include<conio.h>

void main()
{
    int num;
    printf("Enter the starting number for the reverse order:- ");
    scanf("%d", &num);
     
    printf("Natural numbers from %d are :- " ,num);

    for(num; num>0; num--)
    {
        printf("%d," ,num);
    }

    getch();
}