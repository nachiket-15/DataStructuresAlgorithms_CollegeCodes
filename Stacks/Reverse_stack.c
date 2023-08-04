#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack{
    int top;
    int arr[MAX];
}st;

void initialize(){
    st.top=-1;
}

void push(int value){
    if(st.top==MAX-1){
        printf("Stack overflow\n");
    }
    else{
        st.top++;
        st.arr[st.top]=value;
    }
}

int pop(){
    int temp;
    if(st.top == -1){
        printf("Stack underflow\n");
    }
    else{
        temp=st.arr[st.top];
        st.top--;
        return temp;
    }
}

void insertAtBottom(int value){
    if(st.top==-1){
        push(value);
    }
    else{
        int top=pop();
        insertAtBottom(value);
        push(top);
    }
}

void reverse(){
    if(st.top!=-1){
        int top=pop();
        reverse();
        insertAtBottom(top);
    }
}

void print(){
    int temp=st.top;
    printf("Stack is:\n");
    while(temp!=-1){
        printf("%d\n",st.arr[temp]);
        temp--;
    }
    printf("\n");
}
int main() {
    initialize();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    reverse();
    print();
    return 0;
}