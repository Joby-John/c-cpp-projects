#include<stdio.h>

void s_l(int*, int);
void reverse(int*, int);
void sum_mean(int*, int);

void main()
{
    int size, choice, on = 1;
    printf("Enter the size of the array:- ");
    scanf("%d", &size);
    int arr[size];

    for(int i = 0; i<size; i++)
    {
        printf("Enter element no.%d:- ", i+1);
        scanf("%d", &arr[i]);
    }

while(on == 1){
    printf("Enter '1' to find largestand smallest\n 2 to reverse the array\n 3 to get the sum and mean of the array\n:-");
    scanf("%d",&choice);

    switch (choice)
    {
    case(1):
        s_l(&arr[0], size);
        break;
    case(2):
        reverse(&arr[0], size);
        break;
    case(3):
        sum_mean(&arr[0], size);
        break;
    default:
        on = 0;            
        printf("enter a valid option");
        break;
    }
}
}




void s_l(int* loc, int lim)
{
    int small = *loc, large = *loc;
    for (int i = 1; i < lim; i++)
    {
       if (small > *(loc+i))
       {
          small = *(loc+i);
       }
       if (large<*(loc+i))
       {
        large = *(loc+i);
       }
    }
    printf("Largest = %d\n smallest =%d\n",large,small);
}

void reverse(int* loc, int lim)
{
    printf("Reverse:-");
    for(int i = lim-1; i>=0; i--)
    {
       printf("%d,", *(loc+i));
    }
    printf("\n");
}

void sum_mean(int* loc, int lim)
{
    int sum = 0; 
    float mean = 0;
    for(int i = 0; i<lim;i++)
    {
        sum += *(loc+i);
    }
    mean = (float)sum/(float)lim;

    printf("The Total sum is :- %d and mean is %.2f\n", sum , mean);
}