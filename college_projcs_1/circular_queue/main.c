#include<stdio.h>
#define SIZE 5
int queue[SIZE],f = -1,r = -1;// empty queues has start and end index as -1
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

    if (f==-1)//if its the first element added to an empty queue
    {
        f = 0;
        r = (r+1)%SIZE;//modulo ensures that the r doesnt go out of limit ie, 0%5is 0, 1%5 = 1 and 5%5 = 0 and again 6%5 is 1 this goes on and on
        printf("Enter the element to add:- ");
        scanf("%d", &element);
        queue[r] = element;
    }
    else if((r+1)%SIZE == f)//when r's value reaches f
    {
        printf("queue is full\n");//we doesnt add at that index just prints this message bc else value will get overwritten
    }
    else//for all other cases that first case of an empty queue
    {
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
    else if(f==r)//when f and r meets
    {
        printf("popped element is:- %d\n",queue[f]);
        f =r=-1;
    }
    else{
        printf("popped element is:- %d\n",queue[f]);
        f =(f+1)%SIZE;//increments f ie start to next location 
    }
}
//display

void display()
{
    int i = f; //assigns i to start position
    while (i!=r)
    {
        printf("%d,",queue[i]);
        i = (i+1)%SIZE; //f could be below 5 or above 5 depending on operatons performed so its always safe to use modulo
    }
    printf("%d",queue[i]);
}