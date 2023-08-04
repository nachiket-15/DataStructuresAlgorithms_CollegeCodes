#include <stdio.h>
#include <stdlib.h>
#define max 44
int front = 0;
int rear = 0;
int queue_arr[max];

void enqueue(int value){
    if(max==rear){
        printf("Queue is full\n");
    }
    else{
        queue_arr[rear]=value;
        rear++;
    }
}

int dequeue(){
    if(front==rear){
        printf("Queue is empty\n");
    } 
    else{
        int value=queue_arr[front];
        front++;
        if(rear==front){
            rear=front=0;
        }
        return value;
    }
}

void push(int value){
    enqueue(value);
}

int pop(){
    if(front == rear){
        printf("Queue is empty");
    }
    else{
        int value=queue_arr[rear];
        rear--;
        return value;
    }
}
void print(){
    for(int i=front;i<rear;i++){
        printf("%d  ",queue_arr[i]);
    }printf("\n");
}
int main()
{
    push(55);
    push(45);
    push(35);
    push(25);
    push(15);
    print();
    pop();
    print();
    return 0;
}