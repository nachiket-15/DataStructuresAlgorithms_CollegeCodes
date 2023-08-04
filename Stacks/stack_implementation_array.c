#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//GLOBAL DECLARATION
int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top == MAX - 1){
        printf("Stack Overflow !");
    }
    top = top + 1;
    stack_arr[top]=data;
}

void print(){
    int i;
    if(top == -1){
        printf("Stack Underflow !");
    }
    for(i=top;i>=0;i--){
        printf("%d \n",stack_arr[i]);
    }
}

int pop(){
    int value;
    if (top == -1){
        printf("Stack is already empty ");
    }
    value=stack_arr[top];
    top = top - 1;
    return value;
}

int peek(){
    if(top == -1){
        printf("Stack is empty");
        exit(1); 
    }
    return stack_arr[top];
}

int main() {
    int data,choice;
    while(1){
        printf("\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element \n");
        printf("4. Print all the elements in stack \n");
        printf("5. Quit \n");
        printf("\n");
        printf("Please enter your choice : \n");
        scanf("%d",&choice);
    
    switch(choice){
        case 1:
        printf("Enter the element to be pushed : \n");
        scanf("%d",&data);
        push(data);
        break;

        case 2:
        data=pop();
        printf("Deleted element is %d ",data);
        break;

        case 3:
        printf("The topmost element in stack is : %d ",peek());
        break;

        case 4:
        printf("\n\n");
        printf("ELEMENTS IN STACK ARE : \n");
        print();
        break;

        case 5:
        exit(1);
        break;

        default:
        printf("Enter a valid choice !");
    }
    }
    return 0;
}