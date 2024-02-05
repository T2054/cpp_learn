#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
    int ltag; // 左线索标记
    int rtag; // 右线索标记
} TreeNode;

// 创建新节点
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
    newNode->ltag = 0; // 初始状态不是线索
    newNode->rtag = 0; // 初始状态不是线索
    return newNode;
}

// 中序线索化二叉树
void threadTree(TreeNode *root, TreeNode **prev)
{
    if (root == NULL)
        return;

    // 递归线索化左子树
    threadTree(root->left, prev);

    // 如果前一个节点的右子树为空，则将其线索化为指向当前节点
    if (*prev != NULL && (*prev)->right == NULL)
    {
        (*prev)->right = root;
        (*prev)->rtag = 1;
    }

    // 如果当前节点的左子树为空，则将其线索化为指向前一个节点
    if (root->left == NULL)
    {
        root->left = *prev;
        root->ltag = 1;
    }

    // 更新前一个节点
    *prev = root; // 更新prev指针的值为当前节点的地址

    // 递归线索化右子树
    threadTree(root->right, prev);
}

// 中序遍历线索二叉树
void inorderTraversal(TreeNode *root)
{
    // 找到中序遍历的起始节点，即最左边的节点
    TreeNode *current = root;
    while (current != NULL && current->ltag == 0)
    {
        current = current->left;
    }

    // 从起始节点开始输出中序遍历结果
    while (current != NULL)
    {
        printf("%c ", current->data);

        // 如果当前节点的右指针是线索，则移动到后继节点
        if (current->rtag == 1)
        {
            current = current->right;
        }
        else
        {
            // 否则，移动到右子树的最左边
            current = current->right;
            while (current != NULL && current->ltag == 0)
            {
                current = current->left;
            }
        }
    }
}

int main()
{
    // 创建示例二叉树
    TreeNode *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->left->right = createNode('G');
    root->right->left = createNode('E');
    root->right->right = createNode('F');

    // 线索化二叉树
    TreeNode *prev = NULL;
    threadTree(root, &prev);

    // 中序遍历线索二叉树
    printf("Inorder Traversal of Threaded Binary Tree: ");
    inorderTraversal(root);

    printf("\n");

    // 释放内存
    // 这里省略了释放节点的代码，实际应用中需要释放所有节点的内存

    return 0;
}