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
Node*search(Node*root,int key){
    //BASE CASE - IF ROOT IS NULL OR IF ROOTS DATA IS REQUIRED KEY THEN WE NEED TO RETURN ROOT
    if(root==NULL||root->data==key){
        return root;
    }
    //IF ROOTS DATA IS SMALLER THAN KEY , SEARCH IN RIGHT SUBTREE
    if(root->data<key)
        return search(root->right,key);
    //IF ROOTS DATA IS GREATER THAN KEY , SEARCH IN LEFT SUBTREE
    return search(root->left,key);
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

    Node*temp=search(root,45);
    if(temp)
        printf("\nElement found");
    else 
        printf("\nElement not found");
    return 0;
}