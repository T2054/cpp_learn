#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *creatNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        return creatNode(data);
    }

    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = insertNode(root->right,data);
    }
    return root;
}

void preorderTraversal(Node*root){
    if(root != NULL){
printf("%d",root->data);
preorderTraversal(root->left);
preorderTraversal(root->right);

    }
}

int main4(){
    Node*root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    // 前序遍历
    printf("前序遍历结果: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}