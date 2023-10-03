#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* next;
};

struct node* head = NULL;
struct node* temp = NULL;

void insert_beg(struct node* new)
{
    if (head == NULL)
    {
       head = new;
       printf("Enter the element to insert:- ");
       scanf("%d", &new->value);
       new->next = head;
    }
    else{
        temp = head;
        printf("Enter the elements to enter:- ");
        scanf("%d", &new->value);
        new->next = head;
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        temp->next = new;
        head = new;
    }

}

void insert_end(struct node* new)
{
    if (head == NULL)
    {
       head = new;
       printf("Enter the element to insert:- ");
       scanf("%d", &new->value);
       new->next = head;
    }
    else{
    temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = head;
    printf("Enter the value to enter:- ");
    scanf("%d",&new->value);
    }
}

void insert_mid(struct node* new)
{
    int element,found = 1,at_end = 0;
    temp = head;
    if (head!=NULL){
    printf("After which element you want to enter:- ");
    scanf("%d", &element);
    while(temp->value != element)
    {
        temp = temp->next;
        if(temp->next == head)
        {
            found = 0;
            break;
        }
    }
    if(found){
    new->next = temp->next;
    temp->next = new;
    printf("Enter the data to enter:- ");
    scanf("%d",&new->value);
    }
    else
    {
        printf("No such data, do you want to try entering at the end:- 1/0\n");
        scanf("%d",&at_end);
        if(at_end)
        {
            insert_end(new);
        }
    }
    }
    else{
        insert_beg(new);
    }
}

void display()
{   
    if (head!=NULL){
    temp = head;
    while(temp->next!=head)
    {
        printf("%d,",temp->value);
        temp = temp->next;
    }
    printf("%d\n", temp->value);
    }
    else
    {
        printf("Linked list is empty!\n");
    }
}

void delete_all()
{
    temp = head;
    while(temp->next!=head)
    {
        struct node* to_clear;
        to_clear = temp->next;
        printf("clearing:- %d\n",temp->value);
        free(temp);
        temp = NULL;
        temp = to_clear;
    }
    printf("clearing:- %d\n",temp->value);
    free(temp);
    temp = NULL;
    head = NULL;
}

void main()
{
    int choice,on = 1;

    do{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    printf("Enter your choice:- ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: insert_beg(new);
                break;
        case 2: insert_mid(new);
                break;
        case 3: insert_end(new);
                break;                
        case 4: display();
                break;
        case 5: on = 0;
                delete_all();
                break;        
        default: printf("Invalid choice\n");
                 break;       
    }
    }while(on);   
        
}