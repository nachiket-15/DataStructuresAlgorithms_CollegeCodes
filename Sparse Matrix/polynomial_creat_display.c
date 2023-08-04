#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;

}*poly = NULL;

void create()
{
    struct Node *newnode, *last;
    int num, i;
    printf("Enter the number of terms in polynomial: \n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter coefficient for term %d: \n",i+1);
        scanf("%d",&newnode->coeff);
        printf("Enter exponent for term %d: \n",i+1);
        scanf("%d",&newnode->exp);
    
        newnode->next=NULL;
        //IF IT IS FIRST TIME INSERTION 
        if(poly==NULL){
            poly=newnode;
            last=newnode;
        }
        //ATLEAST ONE NODE EXIST , SO NEW NODE WILL BE NEXT/AFTER THAT
        else{
            last->next=newnode;
            last=newnode;
        }
    }
}

void display(struct Node*p){
    while(p!=NULL){
        printf(" %dx^%d ",p->coeff,p->exp);
        p=p->next;
        if(p!=NULL){
            printf("+");
        }
    }
    printf("\n");
}

int main()
{
    create();
    display(poly);

    return 0;
}