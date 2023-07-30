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
//WORST CASE TIME COMPLEXITY IS O(H) , WHERE H IS HEIGHT OF BINARY SEARCH TREE 
//IN WORST CASE WE MAY HAVE TO TRAVEL FROM ROOT TO DEEPEST LEAF O(N)

void inOrder(Node*root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

//SEARCH IN A BINARY SEARCH TREE
int search(Node*root,int key){
    //BASE CASE - IF ROOT IS NULL OR IF ROOTS DATA IS REQUIRED KEY THEN WE NEED TO RETURN ROOT
    if(root==NULL||root->data==key){
        return 1;
    }
    //IF ROOTS DATA IS SMALLER THAN KEY , SEARCH IN RIGHT SUBTREE
    if(root->data<key)
        return search(root->right,key);
    //IF ROOTS DATA IS GREATER THAN KEY , SEARCH IN LEFT SUBTREE
    if(root->data>key)
        return search(root->left,key);
    return 0;
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

    int temp=search(root,45);
    if(temp)
        printf("\nElement found\n");
    else 
        printf("\nElement not found\n");
    // return 0;

    Node*temp2=minValue(root);
    printf("\nThe minimum value in BST is %d ",temp2->data);

    Node*temp1=maxValue(root);
    printf("\nThe maximum value in BST is %d ",temp1->data);

}