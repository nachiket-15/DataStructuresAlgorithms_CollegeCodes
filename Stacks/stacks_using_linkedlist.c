#include <stdio.h>
#include <stdlib.h>

struct stacknode {
    int data;
    struct stacknode* link;
};
struct stacknode *top=NULL;

void push(int data){
    struct stacknode *newnode=(struct stacknode*)malloc(sizeof(struct stacknode));
    newnode->data=data;
    newnode->link=NULL;
    if(newnode==NULL){
        printf("Stack overflow!\n");
        exit(1);
    }
    
    newnode->link=top;
    top=newnode;    
}

int pop(){
    struct stacknode*temp=top;
    int value=top->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return value;
}

int peek(){
    return top->data;
}
void print(){
    struct stacknode *temp=top;
    if(temp==NULL){
        printf("\nStack underflow\n");
        exit(1);
    }
    printf("\nThe elements in stack are: \n");
    while(temp){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    int data,choice;
    while(1){
        printf("1.Push onto stack\n");
        printf("2.Pop from stack\n");
        printf("3.Print elements in stack\n");
        printf("4.Quit\n");
        printf("\nPlease enter your choice: \n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the elements to push: \n");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            pop();
            break;

            case 3:
            print();
            printf("\n");
            break;

            case 4:
            exit(1);
            break;

            default:
            printf("Enter a valid choice\n");
        }
    }
    print();
    return 0;
}