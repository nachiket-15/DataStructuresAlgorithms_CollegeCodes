#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct Stack
{
    struct StackNode *top;
};

bool isEmpty(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(struct Stack *stack, int data)
{
    struct StackNode *newnode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newnode->data = data;
    newnode->next = NULL;

    if (newnode == NULL)
    {
        printf("Stack Overflow!");
    }
    newnode->next = stack->top;
    stack->top = newnode;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is already empty!");
        exit(1);
    }
    struct StackNode *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

void printStack(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is already empty!");
        return;
    }
    struct StackNode *temp = stack->top;
    printf("Current stack is: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void reverse_stack(struct Stack*stack){
    struct Stack reverse;
    reverse.top=NULL;
    while(isEmpty(stack)){
        int data=pop(stack);
        push(&reverse,data);
    }
    stack->top=reverse.top;
}
int main()
{
    struct Stack stack;
    stack.top=NULL;
    push(&stack, 45);
    push(&stack, 55);
    push(&stack, 65);
    push(&stack, 75);
    push(&stack, 85);
    push(&stack, 95);
    push(&stack, 105);
    push(&stack, 115);
    printStack(&stack);
    reverse_stack(&stack);
    printStack(&stack);
    
    return 0;
}