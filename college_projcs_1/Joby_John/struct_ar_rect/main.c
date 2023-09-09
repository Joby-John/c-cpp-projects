#include<stdio.h>
#include<conio.h>

struct rectangle
{
    int length;
    int breadth;
}r1;

void main()
{
    int area;
    printf("Enter the dimensions of the rectangle lxb:- \n");
    scanf("%d%d", &r1.length, &r1.breadth);
    area = r1.length*r1.breadth;
    printf("Area = %d", area);
    getch();
}