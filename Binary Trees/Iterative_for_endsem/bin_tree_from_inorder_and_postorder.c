#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    struct Node* node = createNode(postorder[(*postIndex)--]);
    // (*postIndex)--;

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->val);

    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}



void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

int main() {
    int inorder[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int postorder[] = { 8, 4, 5, 2, 6, 7, 3, 1 };


    int size = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = size - 1;

    int inStart=0;
    int inEnd=size-1;

    struct Node* root = buildTree(inorder, postorder, inStart, inEnd, &postIndex);


    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);

    return 0;
}
