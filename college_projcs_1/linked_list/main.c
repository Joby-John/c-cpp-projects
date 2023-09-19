#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next; 
};

void main()
{
    int i = 1;
    struct node* head = NULL;//points to adresses of the entire chunk not stupid next of any node
    struct node* temp = NULL;//he also points to adress of entire chunk not to next of any node
    do 
    {
      struct node* new = (struct node*) malloc (sizeof(struct node));//allocates memory and assigns its address to new*, now new* has a chunk with 2 blocks value and next 
      printf("Enter the value to be stored:- ");
      scanf("%d",&new->value);//entered element goes to value of struct node
      new->next = NULL; //current nodes adress section is set to null bc its first element
      if (head == NULL)
      {
        head = temp = new;//the adress of whole chunk which was first stored in *new is now passed to head and temp
      }
      else//the most convoluted part note:- new is also a pointer
      {
        temp->next = new;//the next that was previously null is now rewritten by address of the new node
        temp = temp->next;//temp is now ponting to new node that just created
      }
      printf("do you want to continue 1or 0:- ");
      scanf("%d",&i);   

    }while (i == 1);
struct node* p = head;
while(p!=NULL)
{
    printf("node of value %d points to %x \n", p->value,p->next);
    p = p->next;

}

 // Free memory
    struct node* current = head;
    while (current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }
}
