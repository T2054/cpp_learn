#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义栈结构
typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initializeStack(Stack *stack)
{
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// 入栈操作
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// 出栈操作
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// 获取栈顶元素
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->items[stack->top];
}

int main1()
{
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Is stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}