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
void begining(struct node* addr)
{
    temp = head;
    head = addr;
    printf("Enter the value you wantt to enter:- ");
    scanf("%d",&head->value);
    addr->next = temp;
}

void middle(struct node* addr)
{
    int element;
    temp = head;
    printf("After which element you want to enter data:- ");
    scanf("%d",&element);

    while(temp!= NULL && temp->value!= element)
    {
       temp = temp->next;

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
    if (temp!=NULL){
    while (temp->next!= NULL)
    {
       printf("%d", temp->value);
       temp = temp->next;
       printf(",");
    }
    printf("%d",temp->value);
    printf("\n");
}
else{
    printf("You are trying to display empty List!\n ");
}
}

void delete() //need to do delete from begining without bug and set head = null on complete list deletion
{
    temp = head;
    int element, found = 1;
    if (head!= NULL)
    {
    struct node* previous = head;
    printf("Enter the element which you want to delete:- ");
    scanf("%d", &element);
    while(temp->value!=element )
    {
        previous = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            found = 0;
            break;
        }
    }
    if(found == 1)
    {
    if (temp!= head){
    previous->next = temp->next;
    free(temp);
    temp = NULL;
    }
    else
    {
        if (temp->next == NULL)// this if resolved the deletion bug
        {
            free(head);
            head = NULL;
            temp = head;
            //printf("%d", head);
        }
        else{
        head = temp->next;
        free(temp);
        temp = NULL;
    }
    }
    }
    else{
        printf("Entered element not found!\n");
    }
    }
    else{
        printf("The list is empty!\n");
    }

}

void search()
{
    int element;
    temp = head;
    printf("Enter the item to search:-");
    scanf("%d",&element);

    while(temp!=NULL && temp->value!=element)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("ELEMENT NOT FOUND\n");
    }
    else
    {
        printf("ELEMENT FOUND\n");
    }
}


void main()
{
    int on = 1;
    int choice;

    do
    {
        printf("Enter your choice \n1-regular insert \n2-insert at begining \n3-insert at choice\n4-to display\n5-To Delete specific value\n6-To search\n7- To free memory and Quit \n:- ");
        scanf("%d",&choice);
         
        struct node *new = (struct node*) malloc(sizeof(struct node));
        switch(choice){
            case (1):
                    insert(new);
                    break;
            case (2):
                    begining(new);
                    break;        
            case (3):
                    middle(new);
                     break;
            case (4):
                    display();
                    break;
            case (5):
                    delete();
                    //printf("Did well");
                    break;
            case(6):
                    search();
                    break;                
            case (7):
                    on = 0;
                    temp = head;
                    struct node* nexttoclear;
                    while(temp!=NULL)
                    {
                        printf("Clearing %d\n", temp->value);
                        nexttoclear = temp->next;
                        free(temp);
                        temp = nexttoclear;
                    }
                    printf("Clearing memory complete");
                    break;            
            default:
                    printf("Enter a valid choice\n");
                    break;                         

        }
    } while (on);
    
}