#include<stdio.h>
#include<math.h>
#include<conio.h>
int main()
{
    int a,b,c;
    float sol,det;
    char compl[100];
    printf("Please eneter the coefficients of the quadratic eqn in order x^2,x and constant:- \n");
    scanf("%d\n%d\n%d", &a, &b, &c);
    det = (b*b) - (4*a*c);
    if(det < 0)
    {
        det = det*-1;
        det = sqrt(det);
        b = -1*b;
        a = 2*a;
        sprintf(compl, "(%d(+-)%.2fi)/%d",b,det,a);
        printf("The soultions are :- %s",compl);
        getch(); 
        return 0;
    }
    else
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
getch();    
return 0;
}