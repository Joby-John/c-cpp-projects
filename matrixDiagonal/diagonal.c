#include<stdio.h>

void main()
{

    int rows , columns;
    printf("Enter the rows of the matrix\n");
    scanf("%d", &rows);
    printf("Enter the columns of the matrix\n");
    scanf("%d", &columns);

    int matrix [rows][columns];


    for ( int i = 0; i<rows; i++)
{
    for( int j = 0; j<columns; j++)
    {
    printf("Enter elment for %d x %d ", i+1, j+1);
    scanf("%d", &matrix[i][j]);
    }
}

printf("The diagonal elements are :- \n");
 for ( int i = 0; i<rows; i++)
{
    for( int j = 0; j<columns; j++)
    {
        if (i==j)
        {
            printf("%d", matrix[i][j]);
            
        }
        else
        printf(" ");
    }
    printf("\n");
}


    
}