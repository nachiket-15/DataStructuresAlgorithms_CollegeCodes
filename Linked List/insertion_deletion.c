

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printlist(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_at_start(struct Node **head, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = *head;
    *head = newnode;
}

void insert_at_end(struct Node *head, int newdata)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = NULL;

    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
}

void insert_at_index(struct Node *head, int index, int newdata)
{
    int count = 1;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = newdata;
    struct Node *ptr = head;
    while (count < index)
    {
        ptr = ptr->next;
        count++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}

void delete_start(struct Node **head)
{
    struct Node *current = *head;
    if (*head == NULL)
    {
        printf("Linked list is already empty");
    }
    else
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
}

void delete_last(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is already empty");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *current = head;
        struct Node *prev = head;
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
        current = NULL;
    }
}

void delete_at_position(struct Node**head,int position)
{
    struct Node *current = *head;
    struct Node *prev = *head;
    if (*head == NULL)
    {
        printf("Linked list is already empty ");
    }
    else if (position==1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (position > 0)
        {
            prev = current;
            current = current->next;
            position--;
        }
            prev->next = current->next;
            free(current);
            current = NULL;
    }
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1000;
    head->next = NULL;

    // INSERTION AT START
    insert_at_start(&head, 45);
    insert_at_start(&head, 55);
    insert_at_start(&head, 65);
    insert_at_start(&head, 75);
    insert_at_start(&head, 85);

    // INSERTION AT END
    insert_at_end(head, 30);
    insert_at_end(head, 40);
    insert_at_end(head, 50);
    insert_at_end(head, 60);
    insert_at_end(head, 70);

    // INSERTION AT SPECIFIC INDEX
    insert_at_index(head, 5, 6767);
    insert_at_index(head, 5, 6767);

    printf("Linked list after insertion operations is : \n");
    printlist(head);

    // head=delete_at_start(head);
    delete_start(&head);
    printf("Linked list after deletion at start is : \n");
    printlist(head);

    delete_last(head);
    delete_last(head);
    printf("Linked list after deletion at end is : \n");
    printlist(head);

    delete_at_position(&head,4);
    printf("Linked list after deletion at index 4 is: \n");
    printlist(head);
    
    return 0;
}