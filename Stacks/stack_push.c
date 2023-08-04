#include <stdio.h>
#include <stdlib.h>
#define MAX 5

//GLOBAL DECLARATION
int stack_arr[MAX];
int top=-1;

void push(int data){
    if(top==MAX-1){
        printf("Stack Overflow !");
        return;//INDICATES END OF FUNCTION
    }
    top=top+1;
    stack_arr[top]=data;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);  //EXECUTING THIS LINE PRINTS STACK OVERFLOW AS SIZE IS 5
    
    return 0;
}