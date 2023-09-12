#include<stdio.h>
# define N 5
int stack[N], topa = -1;

void push();
void pop();
void top();
void display();

void push()
{
    int data;
    printf("Enter the element to push:- ");
    scanf("%d", &data);
    if (topa <= N-1) /*total of 7 elements*/
    {
        topa ++;
        stack[topa] = data;
    }
    else{
        printf("Overflow\n");
    }
}

void pop()
{
    int data;
    if(topa > -1)
    {
        data = stack[topa];
        topa --;
        printf("The popped element is %d\n", data);
    }
    else{
        printf("Under Flow\n");
    }    

}

void top()
{
    int data;
    if(topa != -1)
    {
        data = stack[topa];
        printf("The top element is %d\n", data);
    }
    else{
        printf("Stack is empty\n");
    }    
}

void display()
{
    int data;
    printf("Stack display:- ");
    for(int top = topa; top>-1; top--)
    {
        data = stack[top];
        printf("%d, ", data);
    }
}


void main()
{
    int choice;
    int on = 1;
    while(on)
    {
        printf("Enter your choice\n 1-push, 2-pop, 3-top, 4-display, 5-quit:- \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case(1): 
                push();
                break;
            case(2):
                pop();
                break;
            case (3):
                top();
                break;
            case (4):
                display();
                break;
            default:
                on = 0;
                break;
        }
    }                   

}