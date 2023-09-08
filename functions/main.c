#include<stdio.h>

float circle(float);

void main()
{
    float r, area;
    printf("Enter the radius of the circle\n");
    scanf("%f",&r);
    area = circle(r);
    printf("The area is %.2f", area);
}

float circle(float r)
{
    float pi = 3.14;
    return (3.14*r*r); 

}