#include <stdio.h>
#include <stdlib.h>

#define MAX 8
// GLOBAL ARRAY DECLARATION
int arr[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow!\n");
    }
    else
    {
        top = top + 1;
        arr[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped element is: %d\n", arr[top]);
        top = top - 1;
    }
}

void print()
{   
    printf("Current stack is \n");
    int temp=top;
    while (temp > -1)
    {
        printf("%d \n", arr[temp]);
        temp--;
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        return arr[top];
    }
}
int main()
{
    push(13);
    push(14);
    push(15);
    print();
    printf("Peek element in stack is: %d\n", peek());
    return 0;
}
