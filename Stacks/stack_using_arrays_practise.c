#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    int size;
    int top;
    int *arr;
};

void push(struct stack*ptr,int value){
    if(ptr->top==ptr->size-1){
        printf("Stack overflow , cannot push more elements into stack\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

void printstack(struct stack*ptr){
    printf("CURRENT STACK ELEMENTS ARE: \n");
    for(int i=ptr->top;i>=0;i--){
        printf("%d\n",ptr->arr[i]);
    }
}

int pop(struct stack*ptr){
    if(ptr->top==-1){
        printf("Stack underflow!\n");
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main() {
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=5;
    sp->arr=(int *)malloc(sizeof(int)*sp->size);

    push(sp,45);
    push(sp,55);
    push(sp,65);
    push(sp,75);
    push(sp,85);
    // pop(sp);
    printstack(sp);

    return 0;
}