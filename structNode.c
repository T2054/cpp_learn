#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

void initializeQueue(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow!\n");
        return -1;
    }
    int dequeuedItem = queue->front->data;
    Node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return dequeuedItem;
}

int peek(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->front->data;
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main33(){
Queue queue;
initializeQueue(&queue);
enqueue(&queue,20);
enqueue(&queue, 30);
enqueue(&queue, 40);
enqueue(&queue, 50);
enqueue(&queue, 60);
printQueue(&queue);
printf("Dequeued element: %d\n", dequeue(&queue));
printQueue(&queue);

return 0;
}
