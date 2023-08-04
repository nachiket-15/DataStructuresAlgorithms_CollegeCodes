#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void printList(struct Node*head){
    struct Node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }printf("\n");
}

void insert_end(struct Node*head,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct Node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}

struct Node* reverse(struct Node*head){
    struct Node*current=head;
    struct Node*previous=NULL;
    while(current!=NULL){
        current=head->next;
        head->next=previous;
        previous=head;
        head=current;
    }
    return previous;
}

int main() {
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    head->data=1;
    head->next=NULL;

    insert_end(head,2);
    insert_end(head,3);
    insert_end(head,4);
    insert_end(head,5);
    insert_end(head,6);
    printf("Linked List is : \n");
    printList(head);
    head=reverse(head);
    printf("Reversed linked list is: \n");
    printList(head);
    return 0;
}