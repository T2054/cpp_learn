#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int data[MAX_SIZE];
    int rear, front;
} Queue;

void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isempty(Queue *queue)
{
    return queue->front == queue->rear;
}

int isFull(Queue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enQueue(Queue *queue, int e)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isempty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % MAX_SIZE;

    printf("Enqueued: %d\n", e);
}

int deQueue(Queue *queue)
{
    if (isempty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int a = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    if (isempty(queue))
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return a;
}

int peek(Queue *queue)
{
    if (isempty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    return queue->data[queue->front];
}

void printQueue(Queue *queue)
{
    if (isempty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d->", queue->data[i]);
    }
    printf("end\n");
}

int lengthQueue(Queue *queue)
{
    return (queue->rear - queue->front + MAX_SIZE) % MAX_SIZE;
}

int main12()
{
    Queue queue;
    initializeQueue(&queue);
    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);
    enQueue(&queue, 40);
    deQueue(&queue);
    deQueue(&queue);
    enQueue(&queue, 50);
    enQueue(&queue, 60);
    printf("queue length = %d\n", lengthQueue(&queue));
    deQueue(&queue);
    deQueue(&queue);
    enQueue(&queue, 50);
    printQueue(&queue);
    printf("peek e is %d\n", peek(&queue));
}