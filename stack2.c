#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}

void printStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++)
    {
        printf("%d\n", stack->items[i]);
    }
}

int main3()
{
    Stack stack;
    initializeStack(&stack);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    printf("top element:  %d\n", peek(&stack));
    int a = pop(&stack);
    printf("a = %d\n", a);
    printStack(&stack);
}
