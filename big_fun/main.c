#include<stdio.h>
int big(int, int);
void point_big(int*);

int big(int a, int b)
{
    if(a>b){return a;}
    else{return b;}
}

void point_big(int *A)
{
    if (A > (A+1))
    {
        *(A+2) = A;
    }
    else{
        *(A+2) = (A+1);
    }
}


void main()
{
    int a,b,bigone;
    int *A;
    printf("Enter two numbers\n");
    scanf("%d%d",&a,&b);

    A = &a;
   *(A+1) = &b;
    bigone = big(a,b);
    point_big(A);
    printf("normal function :- %d", bigone);
    printf("Pointer Big:- %d", *(A+2));
}