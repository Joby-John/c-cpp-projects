#include<stdio.h>
#include<math.h>

int main()
{
    int det,a,b,c;
    float sol;
    printf("Please eneter the coefficients of the quadratic eqn in order x^2,x and constant\n");
    scanf("%d\n%d\n%d", &a, &b, &c);
    det = (b*b) - (4*a*c);
    if(det < 0)
    {
        printf("Equation has no real solution\n");
        return 0;
    }
    else if(det >= 0 )
    {
        if (det > 0)
        {
        printf("The equation has two distinct zeroes that are:- ");
        sol = (-b+ sqrt(det))/2*a;
        printf("%.2f and ", sol);
        }
        else
        {
            printf("The equation has only a single solution:- ");
        }
        sol = (-b - sqrt(det))/2*a;
        printf("%.2f", sol);
    }
return 0;
}