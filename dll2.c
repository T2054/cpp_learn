#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
};

struct Node *creatnode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->pre = NULL;
    return newnode;
}

void appendNode(struct Node **head, int data)
{
    struct Node *newNode = creatnode(data);

    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
        (*head)->pre = *head;
        return;
    }

    struct Node *current = *head;

    while (current->next != *head)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    newNode->pre = current;
    (*head)->pre = newNode;
}

void prependNode(struct Node **head, int data)
{
    struct Node *newnode = creatnode(data);
    (*head)->pre->next = newnode;
    newnode->pre = (*head)->pre;
    (*head)->pre = newnode;
    newnode->next = *head;
    *head = newnode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    do
    {
        printf("%d->", current->data);
        current = current->next;
    } while (current != head);
    printf("NULL\n");
}

// void deleteNode(struct Node **head,int data){
//     struct Node *current = *head;
//     struct Node *prev = NULL;

//     do{
//         prev = current;
//         current = current->next;
//     }
//     while(current != *head && current->data != data );

//     if(current == *head){
//         printf("Node with data %d not found.\n", data);
//         return;

//     }
//     // 删除头结点
//     if(prev == *head){
//         if(current->pre ==current)
//         {
//             current = NULL;
//         }
//         else
//         {
//             (*head)->next->pre = (*head)->pre;
//             (*head)->pre->next = (*head)->next;
//             *head = (*head)->next;
//         }

//     }

//     else{
//         prev->next = current->next;
//         if (current->next != NULL)
//         {
//             current->next->pre = prev;
//         }
//     }

//     free(current);
// }

void deleteNode1(struct Node **head, int data)
{
    // 检查链表是否为空
    if (*head == NULL)
    {
        printf("Empty list, cannot delete.\n");
        return;
    }

    // 初始化当前节点为头结点
    struct Node *current = *head;
    // 初始化前一个节点为NULL
    struct Node *prev = NULL;
    int deleted = 0;

    // 查找要删除的节点
    do
    {
        // 找到要删除的节点
        if (current->data == data)
        {
            // 删除头结点
            if (current == *head)
            {
                // 链表中只有一个节点
                if (current->next == current)
                {
                    free(current); // 释放当前唯一的节点
                    *head = NULL;  // 头指针设为NULL，链表为空
                }
                else
                {
                    // 更新头指针，删除头结点
                    current->next->pre = current->pre;
                    current->pre->next = current->next;
                    *head = current->next;
                }
            }
            else
            {
                // 删除中间或尾节点
                prev->next = current->next;
                if (current->next != NULL)
                {
                    current->next->pre = prev;
                }
            }

            free(current); // 释放找到的节点
            deleted = 1;
            // return;
        }
        else
        {
            prev = current;
        }

        // 更新前一个节点和当前节点

        current = current->next;

    } while (current != *head); // 继续查找直到回到头结点

    if (!deleted)
    {
        // 没有找到要删除的节点
        printf("Node with data %d not found.\n", data);
    }
}

void deleteNode(struct Node **head, int data)
{
    // 检查链表是否为空
    if (*head == NULL)
    {
        printf("Empty list, cannot delete.\n");
        return;
    }

    // 初始化当前节点为头结点
    struct Node *current = *head;
    // 初始化前一个节点为NULL
    struct Node *prev = NULL;
    // 标记是否有删除操作
    int deleted = 0;

    do
    {
        // 找到要删除的节点
        if (current->data == data)
        {
            // 删除头结点
            if (current == *head)
            {
                // 链表中只有一个节点
                if (current->next == current)
                {
                    free(current); // 释放当前唯一的节点
                    *head = NULL;  // 头指针设为NULL，链表为空
                }
                else
                {
                    // 更新头指针，删除头结点
                    current->next->pre = current->pre;
                    current->pre->next = current->next;
                    *head = current->next;
                }
            }
            else
            {
                // 删除中间或尾节点
                prev->next = current->next;
                if (current->next != NULL)
                {
                    current->next->pre = prev;
                }
            }

            free(current); // 释放找到的节点
            deleted = 1;   // 标记有删除操作
        }
        else
        {
            // 更新前一个节点和当前节点
            prev = current;
        }

        current = current->next;

    } while (current != *head); // 继续查找直到回到头结点

    if (!deleted)
    {
        // 没有找到要删除的节点
        printf("Node with data %d not found.\n", data);
    }
}

void updateNode(struct Node **head, int data, int data1)
{
    struct Node *current = *head;

    while (current != NULL && current->data != data)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }

    else
    {
        current->data = data1;
    }
}
int main2()
{
    struct Node *head = NULL;

    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 20);
    appendNode(&head, 50);
    deleteNode1(&head, 20);
    // // printList(head);
    // prependNode(&head,10);
    // prependNode(&head,10);
    // updateNode(&head,30,123);
    printList(head);
    return 0;
}