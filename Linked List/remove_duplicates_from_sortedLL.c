#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void insert_first(struct Node **head, int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = (*head);
    (*head) = newnode;
}
void printLL(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked list is: \n");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void remove_duplicates(struct Node*head){
    struct Node*current=head;
    struct Node*next_next;
    while(current->next!=NULL){
        if(current->data==current->next->data){
            next_next=current->next->next;
            free(current->next);
            current->next=next_next;
        }
        else{
            current=current->next;
        }
    }
}

int main()
{
    struct Node *head = NULL;
    insert_first(&head, 12);
    insert_first(&head, 12);
    insert_first(&head, 12);
    insert_first(&head, 12);
    insert_first(&head, 12);
    insert_first(&head, 13);
    insert_first(&head, 14);
    insert_first(&head, 14);
    insert_first(&head, 14);
    insert_first(&head, 14);
    insert_first(&head, 15);
    insert_first(&head, 16);
    insert_first(&head, 16);
    insert_first(&head, 16);
    printLL(head);
    remove_duplicates(head);
    printLL(head);
    
    return 0;
}