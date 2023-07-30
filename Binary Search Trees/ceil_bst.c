#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

Node*newNode(int data){
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->right=temp->left=NULL;
    return temp;
}

Node*insert(Node*root,int key){
    if(root==NULL)
        return newNode(key);
    if(key>root->data)
        root->right=insert(root->right,key);
    if(key<root->data)
        root->left=insert(root->left,key);
    return root;
}

void find_ceil(Node*root,int key){
    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil=root->data;
        }

        if(key>root->data){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    printf("Ceil is %d",ceil);
}
int main(){
    Node*root=NULL;
    root=insert(root,20);
    root=insert(root,12);
    root=insert(root,10);
    root=insert(root,40);
    root=insert(root,41);
    root=insert(root,31);
    root=insert(root,21);
    root=insert(root,11);

    find_ceil(root,9);
    return 0;
}