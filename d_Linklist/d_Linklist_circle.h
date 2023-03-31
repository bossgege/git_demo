#ifndef D_LINKLIST_CIRCLE_H
#define D_LINKLIST_CIRCLE_H

#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef int ElemType;
typedef struct Lnode_c
{
   ElemType date ;
   struct Lnode_c* next;
   struct Lnode_c* pre;
}Lnode_c,*Linklist_c; // 我们要操作的就是一个一个带指针的结点

void Init_d_LinkList_c(Linklist_c* head);
void print(Linklist_c head);
#endif 
