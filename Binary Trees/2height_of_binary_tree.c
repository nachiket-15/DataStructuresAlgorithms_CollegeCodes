#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

Node*newnode(int data){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

int height(Node*root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    
    int max= (lh>rh) ? lh : rh;
    return max+1;
}

int main(){
    Node*root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    printf("The height of given tree is %d",height(root));
    return 0;
}