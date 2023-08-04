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

void delete_alt(struct Node*head){
    if(head==NULL){
        return;
    }
    struct Node*prev=head;
    struct Node*node=head->next;
    while(prev && node){
        prev->next=node->next;
        free(node);
        prev=prev->next;
        if(prev!=NULL) node=prev->next;
    }
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
    delete_alt(head);
    
    printLL(head);

    return 0;
}