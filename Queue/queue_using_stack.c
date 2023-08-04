#include <stdio.h>
#include <stdlib.h>
#define size 30
// QUEUE USING STACK
int stack_arr[size];
int top = -1;

int isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pop()
{
    return stack_arr[top--];
}

void push(int value)
{
    if (isFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        top = top + 1;
        stack_arr[top] = value;
    }
}

void enqueue(int val)
{
    push(val);
}

// Recursive function call
int dequeue()
{
    int data, result;
    if (isEmpty())
    {
        printf("Queue is empty , nothing to remove\n");
    }
    else if (top == 0)
    {
        return pop();
    }
    data = pop();
    result = dequeue();
    push(data);
    return result;
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d  ", stack_arr[i]);
    }
    printf("\n");
}
int main()
{
    printf("Current queue is :\n");
    enqueue(34);
    enqueue(14);
    enqueue(124);
    print();
    int t = dequeue();
    int r = dequeue();
    printf("Current queue is: \n");
    print();
    return 0;
}