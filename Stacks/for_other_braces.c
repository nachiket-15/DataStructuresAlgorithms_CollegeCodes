#include <stdio.h>
#include <stdlib.h>
//WE WILL USE STACK USING LINKED LIST FOR SOLVING THIS PROBLEM 

struct Node{
    char data;
    struct Node*next;
};
struct Node*head=NULL;

void push(char data){
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

char pop(){
    struct Node*temp;
    if(head==NULL){
        printf("Stack is already empty!\n");
    }
    else{
        temp=head;
        char ch=head->data;
        head=head->next;
        free(temp);
        return ch;
    }
}

int isbalanced(char *exp){
    int i;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('|| exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            char ch=exp[i];
            if(head==NULL){
                return 0;
            }
            else{
                
                char top=head->data;

                if(top=='{' && ch=='}'){
                    pop();
                }
                else if(top=='(' && ch==')'){
                    pop();
                }
                else if(top=='[' && ch==']'){
                    pop();
                }
                
            }
        }
    }
    if(head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    char *ch="{()[]}";
    
    int result=isbalanced(ch);
    if(result==1){
        printf("Balanced parenthesis\n");
    }
    else{
        printf("Not a balanced parenthesis\n");
    }

    return 0;
}