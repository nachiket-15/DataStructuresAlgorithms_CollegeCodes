
#include <stdio.h>
#include <stdlib.h>
// STRUCTURE OF NODE
struct Node
{
    int data;
    struct Node *next;
};

// INSERTION OPERATION
void insert_at_first(struct Node **head, int value)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

void insert_at_last(struct Node *head, int value)
{
    struct Node *temp = head;

    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_at_position(struct Node *head, int position, int value)
{
    if (position == 1)
    {
        insert_at_first(&head, value);
    }
    else
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = value;
        struct Node *temp = head;

        while (position > 2)
        {
            temp = temp->next;
            position--;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// DELETION OPERATION
void delete_first(struct Node **head)
{
    if (*head == NULL)
    {
        printf("Linked list is already empty\n");
    }
    else
    {
        struct Node *temp = *head;
        *head = temp->next;
        free(temp);
        temp = NULL;
    }
}

void delete_last(struct Node *head)
{
    if (head == NULL)//LINKED LIST WITH ONE ELEMENT
    {
        printf("Linked list is already empty\n");
    }
    else if (head->next == NULL)//LINKED LIST WITH SINGLE ELEMENT
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *current = head;
        struct Node *previous = head;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        free(current);
        current = NULL;
        previous->next = NULL;
    }
}

void delete_at_position(struct Node *head, int position)
{
    if (position == 1)
    {
        delete_first(&head);
    }
    else
    {
        struct Node *current = head;
        struct Node *previous = head;
        while (position > 1)
        {
            previous = current;
            current = current->next;
            position--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
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

int count_nodes(struct Node *head)
{
    struct Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int sum(struct Node *head)
{
    struct Node *temp = head;
    int sum = 0;
    while (temp)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

int max_element(struct Node *head)
{
    struct Node *temp = head;
    int max = 0;
    while (temp)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

int linear_search_iterative(struct Node*head,int value){
    struct Node*temp=head;
    while(temp){
        if(value==temp->data){
            return 1;
            break;
        }
        temp=temp->next;
    }
    return 0;
}

int linear_search_rec(struct Node*head,int value){
    if(head==NULL){
        return 0;
    }
    else if(head->data==value){
        return 1;
    }

    return linear_search_rec(head->next,value);
    
}
int main()
{
    struct Node *head = NULL;
    // INSERTION
    insert_at_first(&head, 10);
    insert_at_first(&head, 11);
    insert_at_first(&head, 12);
    insert_at_first(&head, 13);
    insert_at_first(&head, 14);

    insert_at_last(head, 9);
    insert_at_last(head, 8);
    insert_at_last(head, 1010);

    insert_at_position(head, 4, 4545);

    printLL(head);

    // DELETION
    printf("After deletion operation: \n ");
    // delete_first(&head);
    // delete_last(head);
    delete_at_position(head, 4);
    printLL(head);

    printf("Count of nodes in current linked list is: %d\n", count_nodes(head));
    printf("Sum of nodes in current linked list is: %d\n", sum(head));
    printf("Maximum element in current linked list is: %d\n", max_element(head));

    int search_1=linear_search_iterative(head,1011);
    if(search_1==1) printf("Iteartive Search - Element found\n");
    else printf("Iteartive Search - Element not found\n");

    int search_2=linear_search_rec(head,1011);
    if(search_2==1) printf("Recursive Search - Element found\n");
    else printf("Recursive Search - Element not found\n");


    return 0;
}