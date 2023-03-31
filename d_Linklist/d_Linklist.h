#ifndef D_LINKLIST_H
#define D_LINKLIST_H
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct d_Linklist
{
    int date;
   struct d_Linklist *pre;  
   struct d_Linklist *next;
}d_Linklist,*D_Linklist;



void Init_d_LinkList(D_Linklist* head); // 因为要知道链表的本质就是修改指针的指向，如果只是查找就不需要修改指针的指向
void print_d_LinkList(D_Linklist head); //  不需要修改指针的指向，只需要传入结点就行
void Insert_front_d_LinkList(D_Linklist* head,ElemType val);
void Insert_behind_d_LinkList(D_Linklist* head,ElemType val);
void Insert_pos_d_LinkList(D_Linklist* head,int pos,ElemType val);
void delete_pos_d_LinkList(D_Linklist* head,int pos);
void Create_d_LinkList(D_Linklist* head);

#endif 
