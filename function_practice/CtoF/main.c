#include<stdio.h>

float ctof(int celc)
{
    return (celc*1.8)+32;
}

int main()
{
    float celcius;
    printf("Enter the temperature in celcius :- ");
    scanf("%f",&celcius);
    printf("Converted temperature in farenheit = %.2f", ctof(celcius));
}