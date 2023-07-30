//Two trees are identical when they have the same data and the arrangement of data is also the same
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

int identicalTrees(Node*root1,Node*root2){
    //WHEN BOTH ARE EMPTY 
    if(!root1 && !root2)
        return 1;
    // IF NON EMPTY CHECK DATA AND RECURSIVELY CALL FOR LEFT AND RIGHT
    if(root1 && root2){
        return (root1->data==root2->data && identicalTrees(root1->left,root2->left)&& identicalTrees(root1->right,root2->right));
    }
    //WHEN ONE WILL BE EMPTY AND OTHER NOT THEN RETURN FALSE
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

    Node*root2=newnode(1);
    root2->left=newnode(2);
    root2->right=newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5);
    root2->right->left = newnode(6);
    // root2->right->right = newnode(7);

    int ans=identicalTrees(root,root2);
    if(ans)
        printf("Given two trees are identical");
    else 
        printf("Given trees are not identical");

    return 0;
}