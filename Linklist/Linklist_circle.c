#include"Linklist_circle.h"

void Init_LinkList_c(Linklist_c* head)
{
   (*head) = (Linklist_c)malloc(sizeof(Lnode_c));
   (*head)->next =(*head);
   //(*head)=NULL;
}
void Create_Linklist_c(Linklist_c* head)
{
    Lnode_c *p;  // 头插法创建  p为工作指针
    int nums;
    printf("input create nums\n");
    scanf("%d",&nums);
    
   //  for (size_t i = 0; i < nums; i++)
   //  {      int date;
   //      scanf("%d",&date);
   //   p= (Lnode_c*)malloc(sizeof(Lnode_c));
   //   p->date=date;
   //     p->next = (*head)->next;
   //     (*head)->next =p;
   //  }
    
    Lnode_c* tail = (Lnode_c*)malloc(sizeof(Lnode_c)); // 创建尾结点  尾插法
     tail->next = (*head);   // 确定指向
     tail= (*head);  // 初始化
     for (size_t i = 0; i < nums; i++)
    {      int date;
        scanf("%d",&date);
      p= (Lnode_c*)malloc(sizeof(Lnode_c));
      p->date=date;
       p->next =(*head);
       tail->next =p;
       tail =p ;
    }

}
void print_Linklist_c(Linklist_c head)
{
    //if(head->next ==head)return; 
        Lnode_c*  p=head->next;    
        while (p!=head)
        {
          
           printf("%d",p->date);
           p=p->next;
        }  
       
}
int main(int argc, char const *argv[])
{
    Linklist_c head;
    Init_LinkList_c(&head); // 初始化单链表，让头对着头
    Create_Linklist_c(&head);
    print_Linklist_c(head);
    
    return 0;
}
