#include<stdio.h>
#include<conio.h>

void main()
{

    int arr[3][3], big, small, sum = 0, sum_bs = 0;

    for(int r =0; r<3; r++)
    {
        for(int c =0; c<3; c++)
        {
            printf("Enter a number:- ");
            scanf("%d",&arr[r][c]);
        }
    }

    big = arr[0][0];
    small = arr[0][0];
    printf("The matrix is :- \n");

    for(int r =0; r<3; r++)
    {
        for(int c =0; c<3; c++)
        {
            printf("%d\t ",arr[r][c]);
            if (arr[r][c]>big)
            {
                big = arr[r][c];
            }
            else if(arr[r][c]<small)
            {
                small = arr[r][c];
            }
            sum += arr[r][c];
        }
        printf("\n");
        sum_bs = big+small;
    }

    printf("The biggest number in the array is :- %d\nThe sum of entire array = %d\n", big, sum);
    printf("The sum of biggest and smallest element = %d", sum_bs);

    getch();    
}