#include<stdio.h>

void main()
{
    int a = 5;
    int *A = &a;
    int **B = &A;
    int ***C = &B;
    printf("%x", ***C);
}
