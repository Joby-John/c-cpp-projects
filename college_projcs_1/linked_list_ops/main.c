#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* next;
};
struct node* head = NULL;
struct node* temp = NULL;

void insert(struct node* addr)
{
    int data;
    if (head == NULL)
    {
       head = addr;
       printf("Enter the value you want to enter:- ");
       scanf("%d", &data);
       head->value = data;
       head->next = NULL;
       temp = head;
    }
    else{
        temp = head;
        while(temp->next!= NULL)// because prbbly ill reset temp in middle() and after that when i try to enter normally itll be a mess
        {
            temp = temp->next;
        }
        temp->next = addr;
        temp = addr;
        printf("Enter the value you want to enter:- ");
        scanf("%d", &data);
        temp->value = data;
        temp->next = NULL;
    }

}

void middle(struct node* addr)
{
    int element;
    temp = head;
    printf("After which element you want to enter data:- ");
    scanf("%d",&element);
    while(temp->value!= element)
    {
       temp = temp->next;
       if (temp == NULL)
       {
        break;
       }
    }
    if (temp != NULL)
    {
        addr->next = temp->next;
        temp->next = addr;
        printf("Enter the value to enter:- ");
        scanf("%d",&addr->value);
    }
    else{
        printf("NO SUCH ELEMENT FOUND!\n");
    }    
}

void display()
{
    temp = head;
    while (temp->next!= NULL)
    {
       printf("%d", temp->value);
       temp = temp->next;
       printf(",");
    }
    printf("%d",temp->value);
    printf("\n");
}


void main()
{
    int on = 1;
    int choice;

    do
    {
        printf("Enter your choice \n1-regular insert \n2-insert at choice\n3-to display\n4- To free memory and Quit \n:- ");
        scanf("%d",&choice);
         
        struct node *new = (struct node*) malloc(sizeof(struct node));
        switch(choice){
            case (1):
                    insert(new);
                    break;
            case (2):
                    middle(new);
                     break;
            case (3):
                    display();
                    break;
            // delete at choice here        
            case (4):
                    on = 0;
                    temp = head;
                    struct node* toclear;
                    while(temp!=NULL)
                    {
                        toclear = temp->next;
                        free(temp);
                        temp = toclear;
                        printf("Clearing\n");
                    }
                    printf("Clearing memory complete");
                    break;            
            default:
                    printf("Enter a valid choice\n");
                    break;                         

        }
    } while (on);
    
}