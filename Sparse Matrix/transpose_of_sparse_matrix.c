#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;
    int column;
    int data;
    struct Node *next;
};

void create_Sparse(struct Node **start,int row,int column,int data)
{
    struct Node*temp,*r;
    temp=*start;
    if(temp==NULL){
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->row=row;
        temp->column=column;
        temp->data=data;
        temp->next=NULL;
        *start=temp;
    }
    else{

        while(temp->next!=NULL){
            temp=temp->next;
        }

        r=(struct Node*)malloc(sizeof(struct Node));
        r->row=row;
        r->column=column;
        r->data=data;
        r->next=NULL;
        temp->next=r;
    }
}

void transpose(struct Node*head){
    struct Node*temp=head;
    while(temp){
        int temp2=temp->row;
        temp->row=temp->column;
        temp->column=temp2;

        temp=temp->next;
    }
    printList(head);
}


void printList(struct Node *start)
{
    struct Node *ptr1, *ptr2, *ptr3; // make 3 pointers for printing row no , col no & value
    ptr1 = ptr2 = ptr3 = start;      // at first make them point towards start


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
        printf("%d  ", ptr3->data);
        ptr3 = ptr3->next;
    }
    printf("\n");
}
int main()
{
    struct Node *head=NULL;
    //Assume a sparse matrix
    int Matrix[4][5]=
    {
        {0, 1, 1, 0, 0},
        {0, 2, 2, 3, 0},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1}
    };
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            if(Matrix[i][j]!=0){
                create_Sparse(&head,i,j,Matrix[i][j]);
            }
        }
    }
    printf("The initial sparse matrix is:\n");
    printList(head);
    printf("The transpose of sparse matrix is:\n");
    transpose(head);

    return 0;
}