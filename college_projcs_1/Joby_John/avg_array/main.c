#include<stdio.h>
#include<conio.h>

void avg(int*);

void avg(int *addr)
{
    int sum = 0;
    for(int i = 0; i<5; i++)
    {
        sum += *(addr+i);

    }

    printf("total = %d\n", sum);
    printf("Average = %d", (sum/5));

}

void main()
{
    int marks[5],*addr;

    for (int i = 0; i<5; i++)
    {
        printf("Enter the marks of subject no. %d:- ", i+1);
        scanf("%d", &marks[i]);
    }

    addr = &marks[0];

    avg(addr);    

getch();
}
