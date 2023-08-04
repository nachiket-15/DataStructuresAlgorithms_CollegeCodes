#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node* insert_at_beginning(struct Node*head,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=head;
    head=newnode;
    return head;
}

void print(struct Node*ptr){
    printf("Current linked list is: \n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main() {
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    head->data=25;
    head->next=NULL;

    head=insert_at_beginning(head,35);
    head=insert_at_beginning(head,45);
    print(head);
    return 0;
}