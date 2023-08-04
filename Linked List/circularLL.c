#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*next;
}Node;

Node*last=NULL;

void insert_at_first(int value){
    Node*newnode=(Node*)malloc(sizeof(Node));
    //If new node is the only node in the list
    if(last == NULL){
        newnode->data=value;
        newnode->next=newnode;//Circular nature
        last=newnode; 
    }
    else{
        newnode->data=value;
        newnode->next=last->next;//Means newnode cha next ata magashi ji node first hoti tila point karel 
        last->next=newnode;//newnode ata last chya nntr yeil , so ti ata first node ahe 
        //last cha nntr che node first aste , tithun ch C ll chalu hotey
    }
}

void insert_at_last(int value){
    Node*newnode=(Node*)malloc(sizeof(Node));
    //NEWNODE IS THE ONLY NODE IN LIST
    if(last ==NULL){
        newnode->data=value;
        newnode->next=newnode;
        last=newnode;
    }
    //ADDING NEWNODE TO LAST OF EXISTING LL
    else{
        newnode->data=value;
        newnode->next=last->next;
        last->next=newnode;
        last=newnode;
    }
}
void printList(){
    printf("Current Circular LL is: \n");
    if(last==NULL){
        printf("Linked list is empty\n");
    }
    else{
        Node*temp=last->next;
        do{
            printf("%d  ",temp->data);
            temp=temp->next;
        }while(temp!=last->next);
    }printf("\n");
}
int main() {
    insert_at_first(05);
    insert_at_first(45);
    insert_at_first(45);
    insert_at_first(45);
    insert_at_first(75);
    printList();
    insert_at_last(34);    
    printList();
    insert_at_last(24);    
    printList();

    return 0;
}