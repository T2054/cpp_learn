#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int row;
    int col;
    int value;
    struct Node *right;
    struct Node *down;
} Node;

Node *createNode(int row, int col, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->right = NULL;
    newNode->down = NULL;
    return newNode;
}

Node *initialize(int rows, int cols)
{
    Node *head = createNode(-1, -1, 0);
    Node *rowHeads[rows];
    Node *colHeads[cols];

    for (int i = 0; i < rows; i++)
    {
        rowHeads[i] = createNode(i, -1, 0);
        rowHeads[i]->right = rowHeads[i];
    }

    for (int j = 0; j < cols; j++)
    {
        colHeads[j] = createNode(-1, j, 0);
        colHeads[j]->down = colHeads[j];
    }

    for (int i = 0; i < rows; i++)
    {
        Node *lastInRow = rowHeads[i];
        for (int j = 0; j < cols; j++)
        {
            Node *newNode = createNode(i, j, 0);
            lastInRow->right->right = newNode;
            lastInRow = newNode;

            Node *colHead = colHeads[j];
            while (colHead->down->row < i)
            {
                colHead = colHead->down;
            }
            newNode->down = colHead->down;
            colHead->down = newNode;
        }
        head->right = rowHeads[i];
    }

    return head;
}

void insert(Node *head, int row, int col, int value)
{
    Node *rowHead = head->right;
    Node *colHead = head->down;

    while (rowHead->row != row)
    {
        rowHead = rowHead->right;
    }

    while (colHead->col != col)
    {
        colHead = colHead->down;
    }

    Node *newNode = createNode(row, col, value);
    newNode->right = rowHead->right;
    rowHead->right = newNode;
    newNode->down = colHead->down;
    colHead->down = newNode;
}

void print(Node *head, int rows, int cols)
{
    Node *currentRow = head->right->right;
    Node *currentCol;

    for (int i = 0; i < rows; i++)
    {
        currentCol = currentRow;
        for (int j = 0; j < cols; j++)
        {
            if (currentCol->down != NULL && currentCol->down->row == i)
            {
                printf("%d ", currentCol->down->value);
                currentCol = currentCol->right;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
        currentRow = currentRow->down;
    }
}

int main003()
{
    int rows = 3;
    int cols = 3;

    Node *head = initialize(rows, cols);
    insert(head, 0, 0, 1);
    insert(head, 0, 2, 2);
    insert(head, 1, 1, 3);
    insert(head, 2, 0, 4);
    insert(head, 2, 2, 5);

    printf("打印十字链表：\n");
    print(head, rows, cols);

    return 0;
}
