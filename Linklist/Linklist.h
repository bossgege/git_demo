#ifndef LINKLIST_H_
#define LINKLIST_H_

#include<stdio.h>
#include<stdlib.h>

/* 不带指针，传值的方式  Linklist head = Init_LinkList1(head);
 head= Create_Linklist1(head);  // 创建完后接收 
 print_Linklist(head);     
Lnode* Create_Linklist1(Linklist head) //  等价于 Linklist head
{
    Lnode *p,*q ;
    int nums;
    printf("input create nums\n");
    scanf("%d",&nums);
    for (size_t i = 0; i < nums; i++)
    {
        ElemType date;
        scanf("%d",&date);
        p = (Lnode*)malloc(sizeof(Lnode));
        p->date=date;
        p->next = head->next;
        head->next =p;

    }
    return head;
     
}
Linklist Init_LinkList1(Linklist head)
{
   head = (Lnode*)malloc(sizeof(Lnode));
   head->next = NULL;  
    return head;
}
*/
typedef int ElemType;
typedef struct Lnode
{
   ElemType date ;
   struct Lnode* next;
}Lnode,*Linklist; // 我们要操作的就是一个一个带指针的结点


void Init_LinkList(Linklist* head); // 因为要知道链表的本质就是修改指针的指向，如果只是查找就不需要修改指针的指向
void print_Linklist(Linklist head); //  不需要修改指针的指向，只需要传入结点就行
void Insert_front_Linklist(Linklist* head,ElemType val);
void Insert_behind_Linklist(Linklist* head,ElemType val);
void Insert_pos_Linklist(Linklist* head,int pos,ElemType val);
void delete_pos_Linlist(Linklist* head,int pos);
void Create_Linklist(Linklist* head);
#endif 
