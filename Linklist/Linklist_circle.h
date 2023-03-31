#ifndef LINKLIST__CRICLE_H_
#define LINKLIST__CRICLE_H_

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Lnode_c
{
   ElemType date ;
   struct Lnode_c* next;
}Lnode_c,*Linklist_c; // 我们要操作的就是一个一个带指针的结点


void Init_LinkList_c(Linklist_c* head); // 因为要知道链表的本质就是修改指针的指向，如果只是查找就不需要修改指针的指向
void print_Linklist_c(Linklist_c head); //  不需要修改指针的指向，只需要传入结点就行
void Insert_front_Linklist_c(Linklist_c* head,ElemType val);
void Insert_behind_Linklist_c(Linklist_c* head,ElemType val);
void Insert_pos_Linklist_c(Linklist_c* head,int pos,ElemType val);
void delete_pos_Linlist_c(Linklist_c* head,int pos);
void Create_Linklist_c(Linklist_c* head);
#endif 
