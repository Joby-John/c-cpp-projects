#include<stdio.h>

float force(float mass)
{
    return(mass*9.8);
}

int main()
{
    float kg;
   printf("Enter the weight of the object in Kg:- ");
   scanf("%f",&kg);
   printf("The force of attraction excerted by earth on that object is:- %.2f N", force(kg));
}