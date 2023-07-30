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

//LEFT ROOT RIGHT
void inOrder(Node*root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

//ROOT LEFT RIGHT
void preOrder(Node*root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

//LEFT RIGHT ROOT
void postOrder(Node*root){
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

int main(){
    Node*root=newnode(1);
    // root->left=newnode(2);
    root->right=newnode(2);
    //root->left->left = newnode(4);
    //root->left->right = newnode(5);
    root->right->left = newnode(3);
    //root->right->right = newnode(7);

    printf("\nInorder traversal is: \n");
    inOrder(root);

    printf("\nPreorder traversal is: \n");
    preOrder(root);

    printf("\nPostorder traversal is: \n");
    postOrder(root);
    return 0;
}