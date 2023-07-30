#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    int height;
}Node;

Node*newnode(int key){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->left=temp->right=NULL;
    temp->data=key;
    temp->height=1;
    return temp;
}

int Max(int a , int b){
    return a>b?a:b;
}

int NodeHeight(Node*root){
    //CALCULATE LEFT HEIGHT
    int left_height=(root && root->left ? root->left->height: 0);
    //CALCULATE RIGHT HEIGHT
    int right_height=(root && root->right ? root->right->height: 0);
    //RETURN 1 + MAX HEIGHT
    return 1+Max(left_height,right_height);
}
int height(Node*root){
    if(root==NULL)
        return 0;
    return root->height;
}

int balanceFactor(Node*root){
    if(!root)
        return 0;
    return height(root->left)-height(root->right);
}
//UTILITY FUNCTION TO RIGHT ROTATE SUBTREE ROOTED WITH Y
Node*rightRotation(Node*z){
    Node*y=z->left;//POINTER TO LEFT NODE WHICH IS GOIMG TO BE NEW ROOT
    Node*T3=y->right;//POINTER TO LEFT NODES RIGHT NODE
    
    //PERFORM ROTATION
    y->right=z;//MAKE X AS ROOT BY GIVING PREV ROOT IN ITS RIGHT
    z->left=T3;//NOW THEY BECOME LEFT OF PREV ROOT , AS THEY ARE BIGGER THAN CURRENT ROOT , THEY HAD TO BE IN RIGHT SUBTREE

    //UPDATE HEIGHTS
    y->height=NodeHeight(y);
    z->height=NodeHeight(z);

    return y;
    //RETURN NEW ROOT
}

Node*leftRotation(Node*z){
    Node*y=z->right;
    Node*T2=y->left;

    //PERFORM ROTATION 
    y->left=z;
    z->right=T2;

    //UPDATE HEIGHTS 
    y->height=NodeHeight(y);
    z->height=NodeHeight(z);

    return y;//RETURN NEW ROOT
}

Node*insertNode(Node*root,int key){
    //BST INSERTION
    if(root==NULL){
        return newnode(key);
    }

    //IF KEY IS SMALL , INSERT IN LEFT SUBTREE
    if(key < root->data)
        root->left=insertNode(root->left,key);

    //IF KEY IS LARGE INSERT IN RIGHT SUBTREE 
    else if(key > root->data)
        root->right=insertNode(root->right,key);
    else 
        return root;//RETURN AS EQUAL KEYS ARE NOT ALLOWED
    
    //AFTER EVERY INSERTION AT RETURNING TIME WE ARE UPDATING HEIGHTS OF NODES
    // root->height=1+Max(height(root->left),height(root->right));
    root->height=NodeHeight(root);

    //GET THE BALANCE FACTOR
    int bf=balanceFactor(root);

    //LEFT LEFT CASE 
    if( bf>1 && key < root->left->data )
        return rightRotation(root);

    //RIGHT RIGHT CASE 
    if(bf< -1 && key > root->right->data)
        return leftRotation(root);

    //LEFT RIGHT CASE 
    if(bf>1 && key > root->left->data){
        root->left=leftRotation(root->left);
        return rightRotation(root);
    }

    //RIGHT LEFT CASE 
    if(bf< -1 && key < root->right->data){
        root->right=rightRotation(root->right);
        return leftRotation(root);
    } 

    return root;
}

void preorder(Node*root){
    if(!root)return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node*root=NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    printf("Preorder traversal : \n");
    preorder(root);
    return 0;
}