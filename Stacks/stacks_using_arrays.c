//REVISION OF BASIC STACK OPERATIONS - PUSH POP ISFULL ISEMPTY 
//NEW LEARNINGS PRINT PEEK , STACK TOP STACK BOTTOM

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;//Stack Implementation using array 
};

int stackTop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
    }
    else{
        return ptr->arr[ptr->top];
    }
}

int stackBottom(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty\n");
    }
    else{
        return ptr->arr[0];
    }
}

int isFull(struct stack *ptr){
    return ptr->top==ptr->size-1;
}

int isEmpty(struct stack *ptr){
    return ptr->top==-1;
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("Stack overflow - Stack is already full so we cannot add more elements \n");
    }
    else{
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=value;
        printf("%d pushed into stack\n",value);
    }  
}

int pop(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow - stack is already empty so we cannot pop furthermore\n");
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        printf("%d has been popped from stack\n",value);
        return value;
    }
}

void print(struct stack *ptr){
    int index;
    if(ptr->top==-1){
        printf("Stack is empty , nothing to print");
    }
    else{
        printf("CURRENT STACK IS \n");
        for(index=ptr->top;index>=0;index--){
            printf("%d \n",ptr->arr[index]);
        }
    }
}

void peek(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is already empty \n");
    }
    else{
        printf("%d is the peek element in stack\n",ptr->arr[ptr->top]); 
    }
}


int main() {
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=5;
    sp->top=-1;
    sp->arr=(int*)malloc(sizeof(int)*sp->size);

    printf("Stack of size %d has been created successfully!\n",sp->size);
    printf("\n");
    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    int data=pop(sp);
    peek(sp);
    printf(" sab sahi chalraha %d",isFull(sp));
    printf("\n");
    print(sp);
    printf("\n");
   
    return 0;
}