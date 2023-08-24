#include<stdio.h>
float pi = 3.14;
void main()
{
    float p,ar,r;
    printf("Enter the radius of the circle:- ");
    scanf("%f", &r);
    p = 2*pi*r;
    ar = pi*r*r;
    printf("The area :- %f cm sq. \nThe perimeter:- %f cm", p,ar);

}