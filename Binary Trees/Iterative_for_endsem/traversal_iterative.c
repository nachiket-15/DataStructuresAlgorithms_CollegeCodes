#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Stack structure
typedef struct Stack {
    int capacity;
    int top;
    Node** array;
} Stack;

// Function to create a new stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (Node**)malloc(capacity * sizeof(Node*));
    return stack;
}

Node* newNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to push a node to the stack
void push(Stack* stack, Node* node) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = node;
}

// Function to pop a node from the stack
Node* pop(Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

// Iterative inorder traversal
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    Stack* stack = createStack(100); // Set an appropriate capacity
    Node* curr = root;

    while (curr || !isEmpty(stack)) {
        // Reach the leftmost node of the current subtree
        while (curr) {
            push(stack, curr);
            curr = curr->left;
        }

        // Current node is NULL, backtrack and process the nodes in the stack
        curr = pop(stack);
        printf("%d ", curr->data); // Process the data

        // Move to the right subtree
        curr = curr->right;
    }

    free(stack->array);
    free(stack);
}

// Iterative postorder traversal
void postorderTraversal(Node* root) {
    if (root == NULL)
        return;

    Stack* stack1 = createStack(100); // Set an appropriate capacity
    Stack* stack2 = createStack(100); // Set an appropriate capacity

    push(stack1, root);

    while (!isEmpty(stack1)) {
        Node* node = pop(stack1);
        push(stack2, node);

        if (node->left)
            push(stack1, node->left);
        if (node->right)
            push(stack1, node->right);
    }

    while (!isEmpty(stack2)) {
        Node* node = pop(stack2);
        printf("%d ", node->data);
    }

    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);
}

// Iterative preorder traversal
void preorderTraversal(Node* root) {
    if (root == NULL)
        return;

    Stack* stack = createStack(100); // Set an appropriate capacity

    push(stack, root);

    while (!isEmpty(stack)) {
        Node* node = pop(stack);
        printf("%d ", node->data);

        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }

    free(stack->array);
    free(stack);
}

// Test the code
int main() {
    // Create a binary tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
