#include"Linklist.h"



void Init_LinkList(Linklist* head)
{
   *head = (Lnode*)malloc(sizeof(Lnode));
   (*head)->next = NULL;  

}
void Create_Linklist(Linklist* head) //  等价于 Linklist head
{
    Lnode *p;  // 头插法创建  p为工作指针
     int nums;
    printf("input create nums\n");
    scanf("%d",&nums);
    // for (size_t i = 0; i < nums; i++)  //头插法
    // {
    //     ElemType date;
    //     scanf("%d",&date);
    //     p = (Lnode*)malloc(sizeof(Lnode));
    //     p->date=date;
    //     p->next = (*head)->next;
    //     (*head)->next =p;

    // }
   Lnode *tail= (Lnode*)malloc(sizeof(Lnode));  // 创建尾结点 ，不是为指针
          tail->next = NULL;  
    *head = tail;
    for (size_t i = 0; i < nums; i++)  // 尾插法
    {
        ElemType date;
        scanf("%d",&date);
        p = (Lnode*)malloc(sizeof(Lnode));
        p->date=date;
        p->next = NULL;
        tail->next = p;
        tail=p;
       
    } 
    //  *head =head  reaturn  head    
}

void print_Linklist(Linklist head)
{
    if(head->next ==NULL)return; 
        Lnode*  p=head->next;    
        while (p!=NULL)
        {
           printf("%d",p->date);
           p=p->next;
        }         
}
void Insert_front_Linklist(Linklist* head,ElemType val)
{
    Lnode* p =(Linklist)malloc(sizeof(Lnode)); //创建结点存放数据
    p->date =val;
    p->next=NULL;
    if ((*head)->next ==NULL) // 空链表 直接放在后面
    {
        (*head)->next =p;
    }
    p->next =(*head)->next;  // 否则前插
    (*head)->next=p;
    

}
void Insert_behind_Linklist(Linklist* head,ElemType val)
{
    Lnode* p =(Linklist)malloc(sizeof(Lnode)); //创建结点存放数据
    p->date =val;
    
    if ((*head)->next ==NULL) // 空链表 直接放在后面
    {
        (*head)->next =p;
    }
   Lnode* q= (*head);  //创建工作结点遍历到链表的末尾
   while(q->next !=NULL) 
   {
     q=q->next;
   }
   q->next = p;
  p->next =NULL;
}
void Insert_pos_Linklist(Linklist* head,int pos,ElemType val)
{
    Lnode* q =(*head);
    int j=1;
    while (q->next !=NULL && j<pos) // 遍历查找位置
    {
        q=q->next;
        j++;
    }
    Lnode* p =(Linklist)malloc(sizeof(Lnode)); //创建结点存放数据
    p->date =val;  
    p->next =q->next;   //插入
    q->next =p;
}
void delete_pos_Linlist(Linklist* head,int pos)
{
  Lnode* q =(*head); // 工作结点遍历
    int j=1;
    while (q->next !=NULL && j<pos) // 遍历查找位置
    {
        q=q->next;
        j++;
    } 
    q->next=q->next->next;
}

    

int main(int argc, char const *argv[])
{
    Linklist head ;  // 链表 本身就是对指针操作  初始化为  Lnode *head   而不是 node
    Init_LinkList(& head);  //  传递指针的地址，就不需要返回值了 
    Create_Linklist(& head);
  //  Insert_front_Linklist(&head , 100);
  
    print_Linklist(head);
   
    return 0;
}


