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

void middle_of_LL(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    if (head != NULL)
    {
        while (fast!=NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("Middle of linked list is %d", slow->data);
    }
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

int main()
{
    struct Node *head = NULL;
    insert_first(&head, 12);
    insert_first(&head, 13);
    insert_first(&head, 14);
    insert_first(&head, 15);
    insert_first(&head, 16);
    printLL(head);
    middle_of_LL(head);
    return 0;
}