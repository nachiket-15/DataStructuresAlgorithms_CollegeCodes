#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
};

struct Node* add_to_empty_list(struct Node*head,int newdata){
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=newdata;
    temp->next=NULL;
    head=temp;
    return head;
}

struct Node* add_to_beginning(struct Node*head,int newdata){
    struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
    //initial
    temp->prev=NULL;
    temp->data=newdata;
    temp->next=NULL;
    //for required function
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}

struct Node* add_to_end(struct Node*head,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    struct Node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->prev=ptr;
    return head;
}

struct Node* add_to_position(struct Node*head,int position,int newdata){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=newdata;
    struct Node*ptr=head;
    struct Node*ptr2=head;
    int count=1;
    if(position==1){
        head=add_to_beginning(head,newdata);
        return head;
    }

    while(count<position-1){
        count++;
        ptr=ptr->next;
    }
    
    ptr2=ptr->next;

    //adding at last somewhat doubtful
    if(ptr2==NULL){
        ptr->next=newnode;
        newnode->prev=ptr;
        newnode->next=NULL;
    }

    ptr->next=newnode;
    ptr2->prev=newnode;
    newnode->prev=ptr;
    newnode->next=ptr2;
    return head;
}

struct Node*delete_first(struct Node*head){
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    head->next->prev=NULL;
    return head;
}

struct Node*deletelast(struct Node*head){
    struct Node*slow=head;
    struct Node*fast=head;
    while(fast->next!=NULL){
        slow=fast;
        fast=fast->next;
    }
    slow->next=NULL;
    free(fast);
    fast->prev=NULL;
}

struct Node*delete_at_position(struct Node*head,int position){
    struct Node*prev=NULL;
    struct Node*current=head;
    if(position==1){
        head=delete_first(head);
        return head;
    }
    while(position!=1){
        position--;
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    current->next->prev=prev;
    current->next=NULL;
    current->prev=NULL;
    return head;

}
void printList(struct Node*head){
    struct Node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }printf("\n");
}
int main() {
    struct Node*head=NULL;
    head=add_to_empty_list(head,35);
    printList(head);
    head=add_to_beginning(head,34);
    printList(head);
    head=add_to_end(head,6767);
    printList(head);

    head=add_to_position(head,1,4545);
    printf("Linked List as of now is : \n");
    printList(head);

    head=delete_first(head);
    printf("Linked list after deleting first node is: \n");
    printList(head);

    printf("Linked list after deleting the last node is : \n");
    deletelast(head);
    printList(head);

    printf("Again New linked list is: \n");
    head=add_to_end(head,12);
    head=add_to_end(head,14);
    head=add_to_end(head,15);
    head=add_to_end(head,16);
    head=add_to_end(head,17);
    printList(head);

    printf("Linked list after deletion at specific position is : \n");
    delete_at_position(head,3);
    printList(head);


    return 0;
}