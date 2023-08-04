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
    newnode->next = *head;
    *head = newnode;
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
struct Node *reverse_LL(struct Node*head){
    struct Node*previous=NULL;
    struct Node*current=head;
    while(current){
        current=head->next;
        head->next=previous;
        previous=head;
        head=current;
    }
    return previous;
}
int main()
{
    struct Node *head = NULL;
    insert_first(&head, 12);
    insert_first(&head, 13);
    insert_first(&head, 14);
    insert_first(&head, 15);
    insert_first(&head, 16);
    printLL(head);
    head=reverse_LL(head);
    printLL(head);
    
    return 0;
}