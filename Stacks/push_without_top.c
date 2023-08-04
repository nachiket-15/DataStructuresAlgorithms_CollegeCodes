#include <stdio.h>
#include <stdlib.h> //for exit()
#define MAX 5

//GLOBAL DECLARATION
int stack_arr[MAX];
int first= -1;

void print(){
    if(first == -1){
        printf("Stack is empty ");
    }
    for(int i=0;i<=first;i++){
        printf("%d\n",stack_arr[i]);
    }
}
void push(int data){
    first = first + 1;
    if(first == MAX - 1){
        printf("Stack Overflow !");
    }
    for(int i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}
int main() {

    push(3);
    push(6);
    push(9);
    push(12);
    printf("CURRENT STACK IS : \n");
    print();

    return 0;
}