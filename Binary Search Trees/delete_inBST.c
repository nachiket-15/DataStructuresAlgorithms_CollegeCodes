#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

Node*newNode(int key){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->data=key;
    temp->right=temp->left=NULL;
    return temp;
}

Node*insert(Node*root,int key){
    //IF TREE IS EMPTY THEN RETURN THE NEWNODE
    if(root==NULL)
        return newNode(key);
    //IF KEY IS LESS THAN ROOTS DATA , INSERT IN LEFT SUBTREE RECURSIVELY
    if(key<root->data)
        root->left=insert(root->left,key);
    //IF KEY IS GREATER THAN ROOTS DATA , INSERT IN RIGHT SUBTREE RECURSIVELY
    if(key>root->data)
        root->right=insert(root->right,key);
    return root;
}

void inOrder(Node*root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

Node*minValue(Node*root){
    Node*temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;
}

Node*maxValue(Node*root){
    Node*temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node*root,int key){
    if(root==NULL)
        return NULL;

    if(root->data==key){
        //When node has - 0 child --It is leaf Node
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        } 
        //When there is one child - 2 cases 1)left child exists 2)right child exists
        if(root->left && root->right==NULL){
            Node*temp=root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL && root->right){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        //When both the child exists 
        if(root->left && root->right){
            //2 Methods possible
            int mini=minValue(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data>key){
        root->left=deleteFromBST(root->left,key);
    }
    else {
        root->right=deleteFromBST(root->right,key);
    }

    
    return root;
}
int main() {
    Node*root=NULL;
    root=insert(root,20);
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,40);
    root=insert(root,41);
    root=insert(root,31);
    root=insert(root,21);
    root=insert(root,11);

    
    //PRINT INORDER TRAVERSAL OF BINARY SEARCH TREE
    printf("Inorder traversal is : \n");
    inOrder(root);
    printf("\n");

    root=deleteFromBST(root,11);
    //PRINT INORDER TRAVERSAL OF BINARY SEARCH TREE
    printf("Inorder traversal is : \n");
    inOrder(root);
    printf("\n");

    root=deleteFromBST(root,20);
    printf("Inorder traversal is : \n");
    inOrder(root);
    printf("\n");
    return 0;
}