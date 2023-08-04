#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}Node;

//FUNCTION TO INSERT NEW NODE 
Node *insert_in_beginning(Node*head,int value){
    //NODE CREATION AND DATA UPDATION
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->prev=NULL;
    newnode->data=value;
    newnode->next=NULL;
    //POINT NEWNODES NEXT TO PREVIOUS FIRST NODE
    newnode->next=head;
    //POINT PREV OF FIRST NODE TO NEWNODE
    if(head!=NULL){
        head->prev=newnode;
    }
    //MAKE HEAD POINT TO NEW FIRST NODE
    head=newnode;
    //NOW RETURN HEAD AS THIS IS *NODE TYPE FUNCTION
    return head;
}

Node *add_to_end(Node*head,int value){
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->prev=NULL;
    newnode->data=value;
    newnode->next=NULL;

    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

Node *add_to_position(Node*head,int value,int position){
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    Node*current=head;
    Node*prev=head;
    newnode->next=NULL;
    newnode->next=NULL;

    
    while(position>1){
        prev=current;
        current=current->next;
        position--;
    }
    prev->next=newnode;
    newnode->next=current;
    current->prev=newnode;
    newnode->prev=prev;
    return head;
}

Node *delete_first(Node*head){
    Node*temp=head;
    head=head->next;
    free(temp);
    head->prev=NULL;
    return head;
}

Node *delete_last(Node*head){
    Node*current=head;
    Node*prev=head;
    while(current->next!=NULL){
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);
    return head;
}

Node *delete_at_position(Node*head,int position){
    Node*current=head;
    Node*prev=head;
    while(position>1){
        prev=current;
        current=current->next;
        position--;
    }
    prev->next=current->next;
    current->next->prev=prev;
    free(current);
    return head;
}

void printList(Node*head){
    Node*temp=head;
    printf("Current doubly LL is: \n");
    while(temp){
        printf("%d  ",temp->data);
        temp=temp->next;
    }printf("\n");
}

int main() {
    Node*head=NULL;
    head=insert_in_beginning(head,45);
    printList(head);
    head=insert_in_beginning(head,55);
    head=insert_in_beginning(head,65);
    head=insert_in_beginning(head,75);
    head=insert_in_beginning(head,85);
    printList(head);
    head=add_to_end(head,1515);
    printList(head);
    head=add_to_position(head,5656,3);
    printList(head);
    head=delete_first(head);
    printList(head);
    head=delete_last(head);
    printList(head);

    head=delete_at_position(head,2);
    printList(head);
    return 0;
}