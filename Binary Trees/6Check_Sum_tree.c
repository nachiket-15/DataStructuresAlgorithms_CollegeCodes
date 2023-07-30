//A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree
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

int sum(Node*root){
    if(root==NULL)
        return 0;
    return sum(root->left)+root->data+sum(root->right);
}

int sumTree(Node*root){
    //BASE CASE
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return 1;
    
    int left_sum=sum(root->left);
    int right_sum=sum(root->right);

    if(root->data==(left_sum+right_sum)&& sumTree(root->left) &&sumTree(root->right))
        return 1;
    //IF ALL ABOVE GIVEN CONDITIONS ARE NOT SATISFIED
    return 0;
}

