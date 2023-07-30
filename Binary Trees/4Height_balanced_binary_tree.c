/*A height balanced binary tree is a binary tree in which the height of the left subtree and right subtree of any node does not differ by more than 1 and both the left and right subtree are also height balanced.*/

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

int Max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
}

int height(Node*root){
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    
    // int max= (lh>rh) ? lh : rh;
    return Max(lh,rh)+1;
}

int isBalanced(Node*root){
    //BASE CASE , IF ROOT IS NULL IT IS BALANCED
    if(root==NULL)
        return 1;
    //GET HEIGHT OF LEFT AND RIGHT SUBTREES 
    int lh=height(root->left); 
    int rh=height(root->right);

    //CONDITION FOR BALANCED : ABS DIFF SHOULD BE LESS THAN EQ 1 , LEFT AND RIGHT SUBTREES SHOULD ALSO BE BALANCED 
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    //IF WE REACH HERE , THEN CONDITION WAS NOT SATISFIED 
    return 0; 
}
int main(){
    Node*root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    int ans=isBalanced(root);
    printf("%d",ans);
    return 0;
}
