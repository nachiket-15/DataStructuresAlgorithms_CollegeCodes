/*The diameter/width of a tree is defined as the number of nodes on the longest path between two end nodes

Approach: The diameter of a tree T is the largest of the following quantities:
1)The diameter of T’s left subtree.
2)The diameter of T’s right subtree.
3)The longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)*/

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

int diameter(Node*root){
    if(root==NULL)
        return 0;
    //DIAMETER CAN BE IN LEFT SUBTREE
    int op1=diameter(root->left);
    //DIAMETER CAN BE IN RIGHT SUBTREE
    int op2=diameter(root->right);
    //WHEN DIAMETER IS IN BOTH LEFT & RIGHT PARTS 
    int op3=height(root->left)+height(root->right)+1;

    //DIAMETER IS MAXIMUM OF THESE 3 OPERATIONS
    int ans = Max(op1,Max(op2,op3));
    return ans;
}
int main(){
    Node*root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);

    printf("\nThe height of given tree is %d",height(root));
    printf("\nThe diameter of given tree is %d\n",diameter(root));

    return 0;
}