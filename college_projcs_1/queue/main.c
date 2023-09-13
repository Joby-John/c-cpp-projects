#include<stdio.h>

#define SIZE 5
int q[SIZE], f=-1, r =-1;

void NQ(int);
void DQ();
void display();

void NQ(int data)
{
    if (f ==-1)
    {
        f = 0; 
    }
    if(r!=SIZE-1)
    {
        r++;
        q[r] = data;

    }
    else{
        printf("Queue is full\n");
    }
}

void DQ()
{
    if( f ==-1 && r ==- 1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Dequeued element :- %d", q[f]);
        f++;
    }
    if(f==r)
    {
        f = -1;
        r = -1;
    }
}


void display()
{
    printf("Elements:- ");
    for(int i = f; i<=r; i++)
    {
        printf("%d,",q[i]);
    }
    printf("\n");
}

void main()
{
    int choice;
    int on = 1;
    int data;
    while(on)
    {
        printf("\nEnter your choice\n 1-enqueue, 2-dequeue, 3-display, 5-quit:- \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case(1):
                printf("Enter element:- ");
                scanf("%d", &data); 
                NQ(data);
                break;
            case(2): 
                DQ();
                break;
            case (3):
                display();
                break;
            default:
                on = 0;
                break;
        }
    }
}    