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

void search_in_LL(struct Node*head,int data){
    struct Node*ptr=head;
    int count=1;
    while(ptr!=NULL){
        if(ptr->data==data){
            printf("Node with data found at index %d\n",count);
            break;
        }
        ptr=ptr->next;
        count++;
    }
}

void count_node(struct Node*head){
    struct Node*ptr=head;
    int count=0;
    while(ptr!=NULL){
        count ++;
        ptr=ptr->next;
    }
    printf("Number of nodes in given linked list is : %d \n",count);
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
    printf("Current linked list is : \n");
    printList(head);

    search_in_LL(head,4);
    count_node(head);
    return 0;
}