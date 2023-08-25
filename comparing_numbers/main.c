#include <stdio.h>

void main()
{
    float a,b,c,greatest;
    printf("Enter three numbers:-");
    scanf("%f%f%f",&a,&b,&c);

    if (a>b && a>c){greatest = a;}
    else if (b>a && b>c){greatest = b;}
    else if (c>a && c>b){greatest = c;}

    printf("The greatest number of %f %f %f is :- %f", a,b,c,greatest);
}