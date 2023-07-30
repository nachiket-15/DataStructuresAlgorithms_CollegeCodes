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

int height(Node*root){
    if(root==NULL)
        return 0;
    return root->height;
}

int balanceFactor(Node*root){
    if(root==NULL)
        return 0;
    return height(root->left)-height(root->right);
}

//LEFT LEFT CASE
Node*rightRotation(Node*z){
    Node*y=z->left;//POINTER TO LEFT NODE WHICH IS GOING TO BE NEW ROOT
    Node*T3=y->right;//POINTER TO LEFT NODES RIGHT NODE
    
    //PERFORM ROTATION
    y->right=z;//MAKE X AS ROOT BY GIVING PREV ROOT IN ITS RIGHT
    z->left=T3;//NOW THEY BECOME LEFT OF PREV ROOT , AS THEY ARE BIGGER THAN CURRENT ROOT , THEY HAD TO BE IN RIGHT SUBTREE

    //UPDATE HEIGHTS
    y->height=Max(height(y->left),height(y->right))+1;
    z->height=Max(height(z->left),height(z->right))+1;

    return y;
    //RETURN NEW ROOT
}

//RIGHT RIGHT CASE
Node*leftRotation(Node*z){
    Node*y=z->right;
    Node*T2=y->left;

    //PERFORM ROTATION 
    y->left=z;
    z->right=T2;

    //UPDATE HEIGHTS 
    y->height=Max(height(y->left),height(y->right))+1;
    z->height=Max(height(z->left),height(z->right))+1;

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
    root->height=Max(height(root->left),height(root->right))+1;

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

Node*minValue(Node*root){
    Node*temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}

Node*deleteNode(Node*root,int key){
    //BST DELETION
    if(root==NULL)
        return root;
    if(root->data==key){
        //3 CASES POSSIBLE 

        //CASE 1 - IT IS A LEAF NODE
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }

        //CASE 2 - WHEN ONE CHILD IS LEFT
        if(root->left && root->right==NULL){
            Node*temp=root->left;
            free(root);
            return temp;
        }
        if(root->right && root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        //CASE 3 - WHEN ITS BOTH CHILD EXISTS 
        if(root->left && root->right){
            //2 METHODS ARE POSSIBLE - HERE WE ARE REPLACING BY SUCCESSOR
            int mini=minValue(root->right)->data;
            root->data=mini;
            root->right=deleteNode(root->right,mini);
            return root;
        }
    }
    else if(key < root->data){
        root->left=deleteNode(root->left,key);
    }
    else {
        root->right=deleteNode(root->right,key);
    }

    //AFTER EVERY DELETION WE ARE UPDATING HEIGHTS OF NODES
    root->height=Max(height(root->left),height(root->right))+1;

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
    if(!root)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

Node* deleteTree(Node*root){
    if(root==NULL)
        return root;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    root=NULL;

    return root;
}

void AVL_Status(Node*root){
    if(root==NULL){
        printf("\nAVL Tree destroyed successfully");
    }
    else if (root){
        printf("\nAVL Tree exists with root node as %d",root->data);
    }
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
    root=deleteNode(root,10);
    printf("\nPreorder traversal : \n");
    preorder(root);

    // root=deleteTree(root);
    // AVL_Status(root);
   

    // preorder(root);
    return 0;
}