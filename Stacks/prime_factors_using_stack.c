#include <stdio.h>
#include <stdlib.h>

struct stack
{   
    int size;
    int top;
    int *arr;
};

void push(struct stack*ptr,int value){
    if(ptr->top==ptr->size-1){
        printf("Stack overflow - stack is already full to push other elements\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

void print(struct stack*ptr){ 
    if(ptr->top==-1){
        printf("Stack Underflow - Stack is already empty\n");
    }
    else{
        printf("\nPrime factors are : \n");
        for(int i=ptr->top;i>=0;i--){
            printf("%d \n",ptr->arr[i]);
        }
    }
}
void prime_factors(struct stack*ptr,int num){
    int i=2;
    while(num != 1){
        while(num % i==0){
            push(ptr,i);
            num=num/i;
        }
        i++;
    }
    print(ptr);
}

int main() {
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=50;
    sp->top=-1;
    sp->arr=(int*)malloc(sizeof(int)*sp->size);

    int num;
    printf("Enter a number to see its prime factors inside a stack container: \n");
    scanf("%d",&num);
    prime_factors(sp,num);
    return 0;
}