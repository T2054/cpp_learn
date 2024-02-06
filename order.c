#include <stdio.h>
#include <stdlib.h>

typedef char TElemType; // 修改 TElemType 为 char 类型

// 定义二叉树节点的结构体
typedef struct BiTnode
{
    TElemType data;         // 节点数据
    struct BiTnode *lchild; // 左子树指针
    struct BiTnode *rchild; // 右子树指针
} BiTnode, *BiTree;

// 前序遍历函数
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

// 中序遍历函数
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

// 后序遍历函数
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

// 创建二叉树函数
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf(" %c", &ch); // 添加空格以忽略掉输入缓冲区中的空白字符

    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTnode));
        if (!*T)
            exit(EXIT_FAILURE);
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int main()
{
    BiTree T = NULL;
    printf("请输入二叉树的先序序列（使用'#'表示空节点）：\n");
    CreateBiTree(&T);

    printf("前序遍历结果为：");
    PreOrderTraverse(T);
    printf("\n");

    printf("中序遍历结果为：");
    InOrderTraverse(T);
    printf("\n");

    printf("后序遍历结果为：");
    PostOrderTraverse(T);
    printf("\n");

    return 0;
}
