#include "d_Linklist_circle.h"
#include <unistd.h>




void Init_d_LinkList_c(Linklist_c *head)
{
    (*head) = (Lnode_c*)malloc(sizeof(Lnode_c));
    (*head)->next = (*head);
    (*head)->pre = (*head);
}

void Create_d_LinkList_c(Linklist_c *head )
{
    int nums;
    Lnode_c * p;  
    printf("input nums\n");
    scanf("%d",&nums);
    Lnode_c *tail =(Lnode_c*)malloc(sizeof(Lnode_c)); // 创建尾结点方便插入
    tail->next=tail->pre =(*head);
    tail=(*head);
    for (size_t i = 0; i < nums; i++)
    {
        int val;
        scanf("%d",&val);
         p = (Lnode_c*)malloc(sizeof(Lnode_c));  //创建工作结点存放数据
         p->date = val;
         p->next=p->pre=NULL; 
            tail->next=p;
            p->pre=tail;
            tail=p;      
    }
     tail->next =(*head);     

}
void print(Linklist_c head)
{
    Lnode_c* p= head->next;
    while (p!=head)
    {
        printf("%d",p->date);
        p=p->next;
       
    }
    
}

int main(int argc, char const *argv[])
{
    Linklist_c head;
    Init_d_LinkList_c( &head);
    Create_d_LinkList_c( &head);
    print(head);
    return 0;
}
