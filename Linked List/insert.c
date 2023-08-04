#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
void printlist(struct Node*head){
    struct Node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
void push(struct Node**head,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=*head;
    *head=newnode;
}

void append(struct Node*head,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct Node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
}

void insertAtIndex(struct Node*head,int index,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    int count=1;
    struct Node*ptr=head;
    while(count<index){
        count++;
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;

}
int main() {
    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    head->data=25;
    head->next=NULL;
    push(&head,7);
    push(&head,78);
    append(head,999);
    append(head,9999);
    append(head,9999);
    append(head,9999);
    append(head,9999);
    append(head,9999);
    insertAtIndex(head,2,4545);
    printlist(head);
    return 0;
}