#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node
{
    int data;
    struct Node *next;
};

// 创建一个新节点
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表尾部插入节点
void appendNode(struct Node **head, int data)
{
    // 创建一个新的节点，并为其分配内存
    struct Node *newNode = createNode(data);

    // 检查链表是否为空
    if (*head == NULL)
    {
        // 如果链表为空，直接将头指针指向新节点，然后函数返回
        *head = newNode;
        return;
    }

    // 如果链表不为空，创建一个指针 current，并将其指向链表的头节点
    struct Node *current = *head;

    // 使用循环遍历链表，直到找到最后一个节点（尾节点）
    while (current->next != NULL)
    {
        current = current->next;
    }

    // 将新节点插入到尾节点的后面，使得链表中新节点成为新的尾节点
    current->next = newNode;
}

// 在链表头部插入节点
void prependNode(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// 删除指定值的节点
void deleteNode(struct Node **head, int data)
{
    // 创建两个指针 current 和 prev，current 指向链表头节点，prev 初始为空
    struct Node *current = *head;
    struct Node *prev = NULL;

    // 使用循环遍历链表，直到找到包含要删除值的节点或者到达链表末尾
    while (current != NULL && current->data != data)
    {
        // 更新 prev 指针为当前节点
        prev = current;
        // 更新 current 指针为下一个节点
        current = current->next;
    }

    // 如果循环结束时 current 为空，说明链表中没有找到要删除的节点
    if (current == NULL)
    {
        // 打印提示信息并返回
        printf("Node with data %d not found.\n", data);
        return;
    }

    // 如果 prev 为空，说明要删除的节点是链表的头节点
    if (prev == NULL)
    {
        // 将头指针指向当前节点的下一个节点，即删除头节点
        *head = current->next;
    }
    else
    {
        // 将 prev 指针所指节点的 next 指针指向当前节点的下一个节点，
        // 从而跳过当前节点，实现删除操作
        prev->next = current->next;
    }

    // 释放当前节点的内存空间
    free(current);
}

// 打印链表
void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main1()
{
    struct Node *list = NULL;

    // 应用场景1：在链表尾部插入节点
    appendNode(&list, 10);
    appendNode(&list, 20);
    appendNode(&list, 30);

    // 应用场景2：在链表头部插入节点
    prependNode(&list, 5);

    // 应用场景3：删除节点
    deleteNode(&list, 20);

    // 应用场景4：打印链表
    printList(list);

    return 0;
}