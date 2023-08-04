#include <stdio.h>
#include <stdlib.h>
//QUEUE USING LINKED LIST 
struct Node{
    int data;
    struct Node*next;
};

struct Node*front=NULL;
struct Node*rear=NULL;

//ENQUEUE - ADDS ELEMENT AT END OF QUEUE 
void enqueue(int value){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;

    if(front==NULL){
        front = rear = newnode;
    }
    else {
        rear->next=newnode;
        rear=newnode;
    }
}

//DEQUEUE REMOVES FIRST ELEMENT FROM QUEUE
void dequeue(){
    struct Node* temp;
    if(front==NULL){
        printf("Queue is alredy empty ! Nothing to be removed \n");
    }
    else{
        temp=front;
        front=front->next;

        if(front==NULL){
            rear=NULL;
        }

        free(temp);
    }
}

//PRINTING QUEUE
void printQueue(){
    printf("\n");
    struct Node* temp=front;
    while(temp){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    
    enqueue(70);
    enqueue(60);
    enqueue(50);
    enqueue(40);
    enqueue(30);
    enqueue(20);
    enqueue(10);
    printQueue();
    dequeue();
    dequeue();
    printf("Queue after removing first 2 elements: ");
    printQueue();
    return 0;
}
