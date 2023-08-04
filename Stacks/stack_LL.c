#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

void push(int value){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}

void pop(){
    if(head==NULL){
        printf("Stack is already empty");
    }
    else{
        printf("Popped element is : %d\n",head->data);
        struct Node*temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}

void print(){
    struct Node*temp=head;
    printf("STACK IS \n");
    while(temp){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(10);
    push(15);
    pop();
    print();
    return 0;
}