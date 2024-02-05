#include <stdio.h>
#include <stdlib.h>

typedef int TElemType; // 假设 TElemType 为 int，你可以根据实际需要修改

// 定义二叉树节点的结构体
typedef struct BiTnode
{
    TElemType data;         // 节点数据
    struct BiTnode *lchild; // 左子树指针
    struct BiTnode *rchild; // 右子树指针
} BiTnode, *BiTree;

void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

