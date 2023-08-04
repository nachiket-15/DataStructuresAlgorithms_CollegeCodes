#include <stdio.h>
#include <stdlib.h>
// Node that represents sparse matrix
struct Node
{
    int row;
    int column;
    int value;
    struct Node *next;
};

// Function to create new node
void create_new_node(struct Node **start, int row_no, int col_no, int value)
{

    struct Node *temp, *r; // make 2 pointers temp and r (will use later to dynamically create two different type of nodes)

    temp = *start; // make temp point where start is pointing

    // Condition 1 will be nothing is already created & we are creating first node
    if (temp == NULL)
    {
        // create a node dynamically , temp will point that
        temp = (struct Node *)malloc(sizeof(struct Node));
        // Update node with required data
        temp->row = row_no;
        temp->column = col_no;
        temp->value = value;
        temp->next = NULL;
        *start = temp; // update start pointer - make it point to this node now as this is first most node
    }
    // Condition 2 - when at least one node exist and we want to append matrix - add new node to last
    else
    {
        // there can be multiple nodes already present , but we want to add at last , so we will first traverse till end and then perform required operation of node creation and value updation

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Create new node dynamically
        r = (struct Node *)malloc(sizeof(struct Node));
        // update data in row , col value and next address blocks
        r->row = row_no;
        r->column = col_no;
        r->value = value;
        r->next = NULL;
        // make previously last node point current node so that our current node becomes the last node - this fullfills our objective of adding at last i.e. append
        temp->next = r;
    }
}

// Function to print content of Sparse Matrix - Linkedlist Representation
void printList(struct Node *start)
{
    struct Node *ptr1, *ptr2, *ptr3; // make 3 pointers for printing row no , col no & value
    ptr1 = ptr2 = ptr3 = start;      // at first make them point towards start

    printf("Sparse matrix is: \n");

    // Use ptr1 to print value of row
    while (ptr1 != NULL)
    {
        printf("%d  ", ptr1->row);
        ptr1 = ptr1->next;
    }
    printf("\n");
    // Use ptr2 to print value of column
    while (ptr2 != NULL)
    {
        printf("%d  ", ptr2->column);
        ptr2 = ptr2->next;
    }
    printf("\n");
    // Use ptr3 to print value of data value
    while (ptr3 != NULL)
    {
        printf("%d  ", ptr3->value);
        ptr3 = ptr3->next;
    }
    printf("\n");
}
int main()
{
    // Assume 4x5 sparse matrix
    int sparseMatrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}};

    struct Node *start = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // Pass only those values which are non-zero
            if (sparseMatrix[i][j] != 0)
                create_new_node(&start, i, j, sparseMatrix[i][j]);
        }
    }

    printList(start);
    return 0;
}