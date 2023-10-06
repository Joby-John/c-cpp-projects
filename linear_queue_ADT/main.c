
/*So, in summary:

    If you create a structure variable directly, memory is automatically allocated.
    If you create a pointer to a structure, you need to allocate memory for the structure explicitly.*/
#include<stdio.h>
#include<stdlib.h>

int f =-1, r = -1;
struct myArray
{
   int size;
   int size_now;
   int* addr;
};

void NQ(struct myArray* queue)
{
    if (f == -1)
    {
       f = 0;
    }
    if (r!=queue->size-1)
    {
        r++;
        printf("Enter the element to insert:- ");
        scanf("%d", &queue->addr[r]);
        queue->size_now = r+1;
    }
    else{
        printf("Queue is full\n");
    }
}

void DQ(struct myArray* queue)
{
    if (f == -1)
    {
        printf("Empty queue!\n");
    }
    else{
        printf("The removed element:- %d\n", queue->addr[f]);
        for(int i = 1; i<queue->size_now; i++)
        {
            queue->addr[i-1] = queue->addr[i];
        }
        queue->size_now -= 1;// modifying current size
        r = queue->size_now-1;//modyfying rear end
        if(r == -1)
        {
            f = -1;
        }
        //printf("The size :- %d, r now:- %d", queue->size_now,r);
    }
}


void display(struct myArray* queue)
{
   for (int i = 0; i<queue->size_now-1; i++)
   {
    printf("%d,", queue->addr[i]);
   }
   printf("%d\n",queue->addr[queue->size_now-1]);
}
void main()
{
    int on = 1, choice;
    struct myArray queue;
    printf("Enter the size of the queue:- ");
    scanf("%d",&queue.size);
    queue.addr = (int*)malloc(queue.size*sizeof(int));
    if (queue.addr == NULL)
    {
        printf("Memory allocation failure, exiting .....\n ");
        exit(EXIT_FAILURE);
    }
    while(on){
        printf("Enter your choice :- 1. enqueue, 2.dequeue 3. display , any other key to quit:- \n");
        scanf("%d",&choice);
        switch(choice){
            case 1: NQ(&queue);
                    break;
            case 2: DQ(&queue);
                    break;        
            case 3: display(&queue);  
                    break;
            default:
                     printf("Clearing\n");
                     free(queue.addr);
                     on = 0;                
        }
    }
}