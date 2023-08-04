/*

Basic Operations : 
1)Insertion 2)Search Element(rec & iter) 3)Length of LL 4)Reverse LL 5)Deletion 
6)Nth Node in LL 7)Nth Node from end

*/

#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

void insertStart(Node**head,int value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=(*head);
    (*head)=newNode;
}

void insertEnd(Node*head,int value){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;

    Node*ptr=head;
    while(ptr->next){
        ptr=ptr->next;
    }
    ptr->next=newNode;
}

void PrintList(Node*head){
    Node*ptr=head;
    while(ptr){
        if(ptr->next)
            printf("%d -> ",ptr->data);
        else 
            printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void insertAtIdx(Node*head,int value,int index){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;

    Node*ptr=head;
    int cnt=1;
    while(cnt<index){
        ptr=ptr->next;
        cnt++;
    }
    Node*store=ptr->next;
    ptr->next=newNode;
    newNode->next=store;
}

void Search(Node*head,int val){
    Node*ptr=head;
    int idx=0;
    while(ptr){
        idx++;
        if(ptr->data==val){
            printf("Element %d found at index %d \n",val,idx);
            break;
        }
        ptr=ptr->next;
    }
    if(ptr==NULL)
        printf("Element %d not found\n",val);
}

//Recursive search implemented on codestudio
void deleteStart(Node**head){
    Node*curr=*head;
    if(*head==NULL){
        printf("Linked list was alredy empty\n");
    }
    else{
        (*head)=(*head)->next;
        free(curr);
    }
}

void deleteLast(Node*head){
    Node*prev=head;Node*curr=head;
    if(head==NULL){
        printf("Linked list was alredy empty\n");
    }
    else if(head->next==NULL){
        free(head);
    }
    else{
        while(curr->next){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        free(curr);
        curr=NULL;
    }
}


int main() {
    Node*head=(Node*)malloc(sizeof(Node));
    head->data=100;
    head->next=NULL;

    insertStart(&head,90);
    insertStart(&head,80);

    insertEnd(head,110);
    insertEnd(head,120);

    insertAtIdx(head,95,2);
 
    PrintList(head);
    Search(head,101);
    deleteStart(&head);
    deleteLast(head);
    PrintList(head);

    return 0;
}