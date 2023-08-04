#include <stdio.h>
#include <stdlib.h>
#define n 100

//GLOBAL DECLARATION
int arr[n];
int front=0;
int rear=0;

//OPERATIONS ON QUEUES
void enqueue(int data){
    if(rear==n){
        printf("Queue is already full , no space for new element!\n");
    }
    else{
        arr[rear]=data;
        rear++;
    }
}

int dequeue(){
    if(rear==front){
        printf("Queue is already empty , nothing left to remove!\n");
    }
    else{
        int value=arr[front];
        front++;
        if(front==rear){
            //FOR SPACE SAVING AND BETTER UTILIZATION
            front = 0;
            rear = 0;
        }
        return value;
    }
}

void print(){
    if(front!=rear){
        for(int i=front;i<rear;i++){
            printf("%d     ",arr[i]);
        }
    }
    printf("\n");
}
int main() {
    enqueue(30);
    enqueue(31);
    enqueue(32);
    enqueue(33);
    enqueue(34);
    enqueue(35);
    print();
    dequeue();
    print();
    return 0;
}