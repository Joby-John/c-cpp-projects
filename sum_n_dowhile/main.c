#include<stdio.h>

int main()
{
    int i = 1, sum = 0, lim;
    printf("Enter the limit:- ");
    scanf("%d",&lim);
    do{
        sum += i;
        printf("%d+", i);
        if (i == lim)
        {
           printf("\b");
        }
        i++;
    }while(i <= lim);
    
    printf(" = %d", sum);
    return 0;
}