#include<stdio.h>
#define SIZE 5
int queue[SIZE],f = -1,r = -1;
void NQ();
void DQ();
void display();

void main()
{
    int on = 1, choice;
    while(on)
    {
        printf("Enter your choice:- 1- enqueue, 2-dequeue, 3- display, 4-quit:- ");
        scanf("%d",&choice);
        switch(choice){
            case (1): NQ();
            break;
            case (2): DQ();
            break;
            case (3): display();
            break;
            default: 
            printf("BYE");
            on = 0;
            break;

        }

    }
}
//enqueue
void NQ()
{
    int element;

    if (f==-1){
        f = 0;
        r = (r+1)%SIZE;
        printf("Enter the element to add:- ");
        scanf("%d", &element);
        queue[r] = element;
    }
    else if((r+1)%SIZE == f)
    {
        printf("queue is full\n");
    }
    else{
        r = (r+1)%SIZE;
        printf("Enter the element to add:- ");
        scanf("%d", &element);
        queue[r] = element;
    }
}
//dequeue

void DQ(){
    if (f == -1)
    {
        printf("Queue is empty\n");
    }
    else if(f==r)
    {
        printf("popped element is:- %d\n",queue[f]);
        f =r=-1;
    }
    else{
        printf("popped element is:- %d\n",queue[f]);
        f =(f+1)%SIZE;
    }
}
//display

void display()
{
    int i = f;
    while (i!=r)
    {
        printf("%d,",queue[i]);
        i = (i+1)%SIZE;
    }
    printf("%d",queue[i]);
}