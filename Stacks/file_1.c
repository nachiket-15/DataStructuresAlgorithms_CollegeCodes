#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; // pointer to array
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct stack*ptr,int value){
    if(isFull(ptr)){
        printf("Stack overflow - stack is already full \n");
    }
    else{
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=value;
    }
}

int pop(struct stack*ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow - stack is empty \n");
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--; 
        return value;
    }

}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been created successfully\n");

    printf("Is stack full: \n");
    printf("%d \n",isFull(sp));

    printf("Is stack empty: \n");
    printf("%d \n",isEmpty(sp));

    push(sp,45);
    printf("Used push function once , lets check now\n");
    printf("Is stack full: \n");
    printf("%d \n",isFull(sp));

    printf("Is stack empty: \n");
    printf("%d \n",isEmpty(sp));
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);
    push(sp,15);

    printf("Used push function 10 times  , lets check now\n");
    printf("Is stack full: \n");
    printf("%d \n",isFull(sp));

    printf("Is stack empty: \n");
    printf("%d \n",isEmpty(sp));


    return 0;
}