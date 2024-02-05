#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
    int ltag;
    int rtag;
} TreeNode;

TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->ltag = 0;
    newNode->rtag = 0;
    return newNode;
}

void threadTree(TreeNode *root, TreeNode **prev)
{
    if (root == NULL)
        return;

    threadTree(root->left, prev);

    if (*prev != NULL && (*prev)->right == NULL)
    {
        (*prev)->right = root;
        (*prev)->rtag = 1;
    }

    if (root->left == NULL)
    {
        root->left = *prev;
        root->ltag = 1;
    }

    *prev = root;

    threadTree(root->right, prev);
}

void inorderTraversal(TreeNode *root)
{
    TreeNode *current = root;
    while (current != NULL && current->ltag == 0)
    {
        current = current->left;
    }

    while (current != NULL)
    {
        printf("%c", current->data);
    }

    if (current->rtag == 1)
    {
        current = current->right;
    }
    else
    {
        current = current->right;
        while (current != NULL && current->ltag == 0)
        {
            current = current->left;
        }
    }
}
int main111()
{
    TreeNode *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->left->right = createNode('G');
    root->right->left = createNode('E');
    root->right->right = createNode('F');
    TreeNode *prev = NULL;
    threadTree(root, &prev);

    printf("Inorder Traversal of Threaded Binary Tree: ");
    inorderTraversal(root);

    printf("\n");
    return 0;
}
