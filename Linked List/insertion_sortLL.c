#include <stdio.h>
#include <stdlib.h>
// STRUCTURE OF NODE
struct Node
{
    int data;
    struct Node *next;
};
//GLOBAL POINTERS 
struct Node*head=NULL;
struct Node*sorted=NULL;

//INSERTION OPERATION
void insert_at_first(struct Node **head, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

void printLL(struct Node *head)
{
    printf("\nLINKED LIST IS: \n");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}

void sorted_insert(struct Node*newnode){
    if(sorted == NULL || sorted->data >= newnode->data ){
        newnode->next=sorted;
        sorted=newnode;
    }
    else{
        struct Node*current=sorted;
        while(current->next!=NULL && current->next->data< newnode->data){
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
}

void insertionSort(){
    struct Node*current=head;
    while(current){
        struct Node*next=current->next;
        sorted_insert(current);
        current=next;
    }
    head=sorted;
}

int main() {
     
    insert_at_first(&head,11);
    insert_at_first(&head,13);
    insert_at_first(&head,10);
    insert_at_first(&head,211);
    insert_at_first(&head,51);
    insert_at_first(&head,234);
    insert_at_first(&head,24);
    insert_at_first(&head,124);
    insert_at_first(&head,214);
    insert_at_first(&head,224);
    insert_at_first(&head,29);

    printLL(head);

    insertionSort();
    printLL(head);

    return 0;
}