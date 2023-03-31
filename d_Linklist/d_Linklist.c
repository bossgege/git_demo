#include "d_Linklist.h"

void Init_d_LinkList(D_Linklist *head)
{
    (*head) = (D_Linklist)malloc(sizeof(d_Linklist));
    (*head)->next = NULL;
    (*head)->pre = NULL;
}
void Insert_pos_d_LinkList(D_Linklist *head, int pos, ElemType val) // 不能插到元素的末尾
{
    d_Linklist *q = (*head)->next; // 工作结点用来遍历
    int i = 1;
    while (i < pos && q != NULL)
    {
        q = q->next;
        i++;
    }
    if(i==pos)
    {
        Insert_behind_Linklist( head, val);
    }
    else{
        d_Linklist *p = (d_Linklist *)malloc(sizeof(d_Linklist));
    p->date = val;
    p->next = p->pre = NULL;
    p->next = q;
    p->pre = q->pre;
    q->pre->next = p;
    q->pre = p;

    }
    
}
void delete_pos_d_LinkList(D_Linklist *head, int pos) //不能删除最后一个
{
    d_Linklist *temp, *p = (*head)->next; // 工作结点 ， 前驱结点 ，temp结点
    int i = 1;
    if (p->next == NULL || p ==NULL)
    {
        free(p);
        (*head)->next = (*head)->pre = NULL;
        return;
    }
    else
    {
        while (i < pos && (p->next != NULL))
        {
            i++;
            p = p->next;
        }
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    }
}

void Create_d_LinkList(D_Linklist *head)
{
    D_Linklist p; // p为工作指针
    int nums;
    printf("input create nums\n");
    scanf("%d", &nums);

    //  for (size_t i = 0; i < nums; i++)   // 头插法创建
    // {     int date;
    //     scanf("%d",&date);
    //     p= (D_Linklist)malloc(sizeof(d_Linklist));
    //     p->date =date;
    //     p->next=p->pre=NULL;
    //     if(i==0)  // 因为直接插的时候  后面的NULL不能指向头会报错
    //     {
    //         (*head)->next =p;
    //          p->pre =(*head);
    //     }
    //     else{
    //          p->pre =(*head);
    //          p->next = (*head)->next;
    //          (*head)->next->pre =p;
    //           (*head)->next=p;
    //     }

    // }
    d_Linklist *tail = (D_Linklist)malloc(sizeof(d_Linklist));
    tail->next = tail->pre = NULL;
    tail = (*head);                   // 创建尾结点方便插入
    for (size_t i = 0; i < nums; i++) // 尾插法创建
    {
        int date;
        scanf("%d", &date);
        p = (D_Linklist)malloc(sizeof(d_Linklist));
        p->date = date;
        p->next = p->pre = NULL;

        if (i == 0) // 因为直接插的时候  后面的NULL不能指向头会报错
        {
            tail->next = p;
            p->pre = tail;
            tail = p;
        }
        else
        {
            p->pre = tail;
            tail->next = p;
            tail = p;
        }
    }
}
void Insert_front_d_LinkList(D_Linklist *head, ElemType val) // 头插法
{
    d_Linklist *p = malloc(sizeof(d_Linklist)); // 创建结点
    p->next = p->pre = NULL;
    p->date = val;
    if ((*head)->next == NULL) // 如果为空直接接在后面
    {
        (*head)->next = p;
        p->pre = (*head);
    }
    else
    { // 否则 接到head的后面
        p->next = (*head)->next;
        p->pre = (*head);
        (*head)->next->pre = p;
        (*head)->next = p;
    }
}
void print_d_LinkList(D_Linklist head)
{
    D_Linklist p;
    p = head->next;
    while (p)
    {
        printf("%d", p->date);
        p = p->next;
    }
}
void Insert_behind_d_LinkList(D_Linklist *head, ElemType val)
{
    d_Linklist *p = malloc(sizeof(d_Linklist)); // 创建结点保存数据
    p->next = p->pre = NULL;
    p->date = val;
    //  d_Linklist* tail = malloc(sizeof(d_Linklist));  // 不需要创建尾结点  ，只有创建链表的时候需要
    //  tail->next=tail->pre=NULL;
    //  tail=(*head);
    if ((*head)->next == NULL) // 如果为空直接接在后面
    {
        (*head)->next = p;
        p->pre = (*head);
        (*head) = p;
    }
    else
    {
        d_Linklist *q = (*head); // 遍历链表加到末尾
        while (q->next != NULL)
        {
            q = q->next;
        }

        q->next = p;
        p->pre = q;
    }
}
int main(int argc, char const *argv[])
{
    D_Linklist head;
    Init_d_LinkList(&head);
    Create_d_LinkList(&head);
    print_d_LinkList(head);
    return 0;
}
