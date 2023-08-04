#include <stdio.h>
#include <stdlib.h>
//STACK IMPLEMENTATION USING LINKED LIST
struct Node{
    int data;
    struct Node*next;
};

struct Node*head=NULL;

//PUSH OPERATION
void push(int value){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=head;

    head=newnode;
}
//POP OPERATION
void pop(){
    struct Node*temp;
    if(head==NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("Popped element is %d \n",head->data);
        temp=head;
        head=head->next;
        free(temp);
    }
}
//PRINT 
void print(){
    struct Node*temp=head;
    while(temp){
        printf("%d\n",temp->data);
        temp=temp->next;
    }printf("\n");
}


int main() {
    push(10);
    push(20);
    push(30);
    printf("Current stack using Linked List is: \n");
    print();
    pop();
    printf("After the pop, the new Stack is: \n");
    print();
    pop();
    printf("After the pop, the new Stack is: \n");
    print();
    return 0;
}