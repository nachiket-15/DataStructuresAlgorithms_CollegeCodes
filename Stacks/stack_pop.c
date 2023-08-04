#include <stdio.h>
#include <stdlib.h>

#define MAX 7

// GLOBAL DECLARATION
int stack_arr[MAX];
int top = -1;

void print(){
    int i;
    if(i == -1){
        printf("Stack Underflow");
    }
    for (i=top ; i>=0 ; i--){
        printf("%d\n",stack_arr[i]);
    }
    printf("\n");
}

void push(int data)
{
    if(isFull()){
        printf("Stack Overflow !");
        return;
    }
    top = top + 1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow !\n");
        exit(1);
    }
    value=stack_arr[top];
    top = top - 1;
    return value;
}

int isFull(){
    if(top == MAX - 1){
        return 1;// STACK IS FULL
    }
    else {
        return 0;//STACK IS NOT FULL
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else {
        return 0;
    }
}
int main()
{
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    printf("CURRENT STACK IS \n");
    print();

    data=pop();
    printf("STACK AFTER REMOVING FIRST TOP ELEMENT \n");
    print();

    data=pop();
    printf("STACK AFTER REMOVING SECOND TOP ELEMENT \n");
    print();
    return 0;
}