// #include <iostream>
// #include <stdio.h>
// using namespace std;

// #define MAXSIZE 20 
// #define OK 1
// #define ERROR 0 
// typedef int ElemType;
// typedef int Status;

// typedef struct
// {
//     ElemType data[MAXSIZE]; /* 数组，存储数据元素 */
//     int length;             /* 线性表当前长度 */
// }SqList;

// // 111
// Status GetElem(SqList L,int i,ElemType *e)
// {
//     if(L.length==0 || i<1 || i>L.length)
//             return ERROR;
//     *e=L.data[i-1];

//     return OK;
// }

// Status ListInsret(SqList * L,int i,ElemType e)
// {
//     int k;
//     if(L->length == MAXSIZE)
//     return ERROR;

//     if(i < 1 || i > L -> length + 1)
//     return ERROR;
    
//     if(i <= L -> length)
//     {
//         for(k = L -> length - 1;k >= i - 1;k--)
//         L->data[k+1]=L->data[k];
//     }
//     L->data[i - 1] = e;
//     L->length++;
//     return OK;
// }

// Status ListDelete(SqList *L,int i,ElemType *e) 
// { 
//     int k;
//     if (L->length==0)               
// 		return ERROR;
//     if (i<1 || i>L->length)         
//         return ERROR;
//     *e=L->data[i-1];
//     if (i<L->length)                
//     {
//         for(k=i;k<L->length;k++)
// 			L->data[k-1]=L->data[k];
//     }
//     L->length--;
//     return OK;
// }

//     typedef struct Node
//     {
// ElemType data;
// struct Node *next;

//     }Node;
//     typedef struct Node *LinkList;

// Status GetELem(LinkList L,int i,int ElemType *e)
// {
// int j;
// LinkList p;
// p = L -> next;
// j = 1;
// while(p && j < 1)
// {
// p = p -> next;
// ++j; 
// }
// if( !p || j > 1)
// }







