#include<stdio.h>

void main()
{
    float c,f;
    printf("Enter the temperature in C:-");
    scanf("%f", &c);

    f = (c*1.8)+32;

    printf("The converted tempertaure in F :- %f", f);
}