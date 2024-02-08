#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *creatnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void appendNode(struct Node **head, int data)
{
    struct Node *newNode = creatnode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void prependNode(struct Node **head, int data)
{
    struct Node *newnode = creatnode(data);
    newnode->next = *head;
    *head = newnode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node **head,int data){
    struct Node *current = *head;
    struct Node *prev = NULL;
    
    while(current->data != data && current != NULL)
    {
        prev = current;
        current = current->next;
    }
    
    if(current == NULL){
        printf("Node with data %d not found.\n", data);
        return;

    }
    if(prev == NULL){
        *head = current->next;
    }
    else{
        prev->next = current->next;
    }
    free(current);
}

void updateNode(struct Node **head,int data,int data1){
    struct Node *current = *head;

    
    while(current->data != data && current != NULL)
    {
        current = current->next;
    }
    
    if(current == NULL){
        printf("Node with data %d not found.\n", data);
        return;

    }

    else{
        current->data = data1;
    } 
}
int main57()
{
    struct Node *head = NULL;

    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 50);
    deleteNode(&head,30);
    printList(head);
    prependNode(&head,10);
    updateNode(&head,10,123);
    printList(head);
    return 0;
}