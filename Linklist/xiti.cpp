#include"xiti.h"
//1、
void create_deltete_x(Linklist* L)
{
   int nums;
   cout <<"input create nums"<<endl;
   cin >> nums; // 输入要创建链表的元素个数
    Linklist p; // 创建结点接收数据
    // Linklist   tail = (Linklist)malloc(sizeof(Lnode));   //创建尾结点方便插入数据
    // tail->next =NULL;
      Linklist tail= (*L);
   for(int i =0; i<nums ;i++)
   {
      p =(Linklist)malloc(sizeof(Lnode));  
      p->next =NULL;
      int date;
      cin >> date;   //创建结点接收数据
      p->date =date;
      tail->next =p;
      tail =p;
   }
   tail->next =NULL;
   Linklist q =(*L); // 创建结点打印数据
   cout << "创建完的链表的值 :"<<endl;
  
   while (q)
   {
     cout << q->date <<'\t';
     q=q->next;
   }

}
void deltete_x(Linklist *L,int x)
{
    Lnode * q ;
    if((*L==NULL))return;
    
    else if ((*L)->date ==x) {
      q =(*L);  
      *L =(*L)->next;  // 头结点指向下一位
      free(q);    // 删除
      deltete_x( &*L,x);  // 再次判断
    }
    else{
        deltete_x(&(*L)->next,x);
    }
}
void print_Linklist(Linklist L)
{
     while (L)
    {
        cout << L->date <<'\t';
        L=L->next;
    }
}

//2、
void cLinkList_Head(Linklist *head)
{
  (*head)= (Linklist)malloc(sizeof(Lnode)); // 创建头结点
  (*head)->next=NULL; 
   int nums;
   cout <<"input create nums"<<endl;
   cin >> nums; // 输入要创建链表的元素个数
    Linklist p; // 创建结点接收数据
    Linklist   tail = (Linklist)malloc(sizeof(Lnode));   //创建尾结点方便插入数据
     tail->next =NULL;
     tail= (*head);
   for(int i =0; i<nums ;i++)
   {
      p =(Linklist)malloc(sizeof(Lnode));  
      p->next =NULL;
      int date;
      cin >> date;   //创建结点接收数据
      p->date =date;
      tail->next =p;
      tail =p;
   }
   tail->next =NULL;
  //  Linklist q =(*head)->next; // 创建结点打印数据
  //  cout << "创建完的链表的值 :"<<endl;
  //  while (q!=NULL)
  //  {
  //     cout<< q->date <<'\t';
  //     q=q->next;
  //  }
  //  cout<<endl;
  
}
//2、
void deltete_preate_x(Linklist *head, int x)
{
  Linklist p;//创建工作结点      // 方法一   直接删除
   Linklist q ,pre;   //删除保存的结点，前驱结点
  p=(*head)->next;
  pre =(*head);
  while (p!=NULL)
  {
  
    if(p->date==x)
    {
     q=p;
     p=p->next;
    pre->next = p;
     free(q);
    }
    else{
       pre =p;
        p=p->next;
    }
  }
  
    // Linklist p;//创建工作结点     尾插法
    // (*head) =p;
    // Linklist tail ;
    //  tail=(*head);
    //  tail->next =NULL;
    // Linklist q;
    // Linklist n;
    // while (p->next)
    // {
    //  if(p->date !=x)
    //  {  
    //     tail->next =p;
    //     tail =p;
    //     p=p->next;
    //  }
    //  else{
    //       q=p;
    //       p=p->next;
    //       free(q);
    //  }
    // }
    // tail->next =NULL;

}
// 3/5
void   reverse(Linklist* head)
{
  Linklist p ;  // 工作指针   头插法
  Linklist q;   // 保存结点的指针
  p = (*head)->next;
 (*head)->next =NULL;  // 把头结点拿出来
  while (p!=NULL)
  {

     q= p->next ; 
     p->next =(*head)->next;  // 拿原来链上的指针去指
     (*head)->next =p;
     p=q;
    // q = p;
    // q->next =(*head)->next;  //不能将原来链上数据放到一个临时变量上 只修改了指向没有保留值
    // (*head)->next =q;
    // p=p->next;

  }
  
}
void prints(Linklist head)
{ 
  Linklist  q = head->next;   // 要创建工作结点
  while (q)
    {
     
      cout << q->date <<'\t';
      q=q->next;
    }

}
//7
void  delete_part(Linklist* head ,int m ,int n)
{
  Linklist p,q,pre;
  pre= (*head);
  p=(*head)->next;
  while (p!=NULL)
  {
     if( p->date  > m  && p->date <n)
     {
       
       q=p;
       p=p->next;
       pre->next=p;
       free(q);
     } 
     else{
        pre =p;
        p=p->next;
     }


  }
}
//4、
void delete_min(Linklist *head)
{
  Linklist p,pre;
  Linklist mpre,min;
   pre=(*head);
   p=(*head)->next; //遍历结点
   min=p;  //
   mpre =pre;
   while (p!=NULL)
   {

     if(p->date <min->date) // 更新最小值
     {
      min =p;
      mpre =pre;
     } 
     else{ //  遍历寻找最小值
       pre =p; 
       p=p->next;
     }    
   }
   mpre->next =min->next; // 防止断链
   free(min);
}
// 5

Linklist serch_same_node(Linklist L1 ,Linklist L2)
{
    int i=0;
    int j =0;   // 计算两个链表的长度
    Linklist L1_count=L1->next;
    while (L1_count)
    {
     i++;
     L1_count=L1_count->next;
    }
    Linklist L2_count=L2->next;
    while (L2_count)
    {
     j++;
     L2_count=L2_count->next;
    }
    // 计算他们长度的差值，使他们的头在一起
     Linklist l1 =L1->next;;
    if(i>j)
    {
      int dis =i-j;
     
      while (dis)
      {
        l1 = l1->next;
        dis --;
      }
      
    }
    Linklist l2=L2->next;
     if(i<j)
    {
    
      int dis =j-i;
      while (dis)
      {
        l2 = l2->next;
        dis --;
      } 
    }
    // 一起走当他们的数值想同时找到公共结点
    while (l2!=NULL )
    {
      if(l2->date == l1->date)
      {
         return l2;
      }
      l2=l2->next;
      l1=l1->next;
    }
    return 0;
}
//9 
void delete_min1(Linklist* head)
{
  Linklist min;
  Linklist premin;
  Linklist temp;
  premin = (*head);
  min=(*head)->next;
  while ((*head)->next !=NULL) // 控制轮数直到结点全部释放为止
  {
      premin = (*head);
      min=(*head)->next; // 假定第一结点为最小值
      Linklist temp;
      while (min->next!=NULL)
      {
           if(min->next->date <min->date) // 每次那当前的最小值与下一个进行比较
           {
             premin =min; // 更新最小值的前一个结点
           }
            min=min->next;
      }
       cout << premin->next->date <<endl;
       temp = premin->next; //保存当前最小值
       premin->next = temp->next ; // 防止断链
       free(temp);
  }
  


}
//10
void divide_list(Linklist head)
{ 
  Linklist head_o = (Linklist)malloc(sizeof(Lnode));  // 创建偶数的头结点
  head_o->next =NULL; 
   Linklist head_o_tail = (Linklist)malloc(sizeof(Lnode));  // 创建偶数
   head_o_tail =head_o;

  Linklist head_j = (Linklist)malloc(sizeof(Lnode));  // 创建奇数的头结点
  head_j->next =NULL;
   Linklist head_j_tail = (Linklist)malloc(sizeof(Lnode));  // 创建偶数的头结点
   head_j_tail =head_j;
  Linklist q;
    q=(*head).next; // 创建工作结点
  while (q)
  {
      if(q->date %2 ==0)
      {
         Linklist p = (Linklist)malloc(sizeof(Lnode)); 
          p->date = q->date;
          p->next =NULL;
          head_o_tail->next =p;
          head_o_tail =p;
      }
     else if(q->date %2 ==1)
      {
         Linklist p = (Linklist)malloc(sizeof(Lnode)); 
          p->date = q->date;
          p->next =NULL;
          head_j_tail->next =p;
          head_j_tail =p;
      } q=q->next;
  } 
 
   cout << "偶数";
    prints(head_o);
   cout <<endl;
   cout << "奇数";
   prints(head_j);
}
//11
void divide_list1(Linklist head)
{ 
  Linklist head_a = (Linklist)malloc(sizeof(Lnode));  
  head_a->next =NULL; 
   Linklist head_a_tail = (Linklist)malloc(sizeof(Lnode));  
   head_a_tail =head_a;

  Linklist head_b = (Linklist)malloc(sizeof(Lnode));  
  head_b->next =NULL;
  Linklist q;
  q=(*head).next; // 创建工作结点
   int i=1; // 记录结点的位置

  while (q)
  {   

      if(i %2 ==1)
      {
         Linklist p = (Linklist)malloc(sizeof(Lnode)); 
          p->date = q->date;
          p->next =NULL;
          head_a_tail->next =p;
          head_a_tail =p;
          cout << head_a->next->date<<endl; 
      }
     else if(i %2 ==0)
      {
         Linklist p = (Linklist)malloc(sizeof(Lnode)); 
          p->date = q->date;
          p->next =NULL;
         p->next =  head_b->next ;
          head_b->next =p;       
      } 
      ++i;      
      q=q->next;
     
  } 
 
   cout << "head_a  ";
   prints(head_a);
   cout <<endl;
   cout << "head_b  ";
 prints(head_b);
}
//12
void delete_repeat(Linklist* head)
{
   Linklist q ; // 删除结点
   Linklist p; // 进行遍历
     p=(*head)->next;
     if((*head)->next ==NULL);
    while (p->next!=NULL)
    {
      if(p->next->date == p->date)  // 直接找下一个节点是否等于当前结点
      {
        q = p->next;
        p->next =p->next->next;
        free(q);
      }
      else{
         p=p->next;
      }
    }
    
  
}
// 13
 Linklist merge_list(Linklist L1 ,Linklist L2)
 {
   Linklist head = (Linklist)malloc(sizeof(Lnode));
   head->next =NULL;
   Linklist p1 =L1->next;
   Linklist p2= L2->next;
   Linklist p;  
   while (p1 != NULL  && p2!=NULL)
   {
      if(p1->date < p2->date)
      {
        
         p =p1->next;   // 结点保存后一个值防止断链
         p1->next = head->next;
         head->next =p1;  // 头插法
         p1=p;  
      }
      else 
      {
         p =p2->next;
         p2->next = head->next;
         head->next =p2;
         p2=p;
      }

   }  
   if(p1){p2=p1;} // 将还没为空的结点接到已经为空的结点
    while (p2)
    {
       p =p2->next;
         p2->next = head->next;
         head->next =p2;
         p2=p;
    }  
   return head;

 }
// 14 15
Linklist merge_same(Linklist L1 ,Linklist L2)
{
    Linklist head = (Linklist)malloc(sizeof(Lnode));
    head->next =NULL;
    Linklist tail = L1; // 创建尾指针 tail= head 为14
    Linklist L1_min = L1->next;
    Linklist L2_min = L2->next; // 创建结点记录 ，每次从较小的遍历，看是否相等，直到其中一个链表为空

     while (L1_min && L2_min)
     {
         if(L1_min->date < L2_min->date) L1_min =L1_min->next;
         else if(L1_min->date > L2_min->date) L2_min =L2_min->next;  // 较小的后移直到遇到相等的
         else{
               Linklist p = (Linklist)malloc(sizeof(Lnode));   // 相等同时后移
                p->date= L1_min->date;
               tail->next =p;
               tail =tail->next;
               L1_min =L1_min->next;
               L2_min =L2_min->next;
         }
     }
     return L1;

}
//16
bool kmp_list(Linklist L1 ,Linklist L2)
{
   Linklist L1_p =L1->next;
   Linklist L2_p =L2->next;
   Linklist L1_pt =L1->next;

    while (L2_p && L1_p)
    {
        if(L2_p->date == L1_p->date)
        {
           L2_p=L2_p->next ;  
           L1_p=L1_p->next ; // 相等后移继续比较
        }
        else{
            L1_pt=L1_pt->next;  // 不相等  从L1的后移结点进行比较
            L1_p =L1_pt;
            L2_p= L2->next;    // L2 重新开始比较
        }
         
    }
     if(L2_p ==NULL)return true;
     else return false; 
}

void Create_Circlelist(node** head)
{
    (*head) = (node*)malloc(sizeof(node));
     (*head)->next =(*head);
     (*head)->pre =(*head);

      node* tail =*head;
     cout << "input nums"<<endl;
     int nums;
     cin>>nums;
     for (int i = 0; i < nums; i++)
     {
        int date ;
        cin >> date;
        node* p = (node*)malloc(sizeof(node));
        p->date =date;
        p->next =(*head);
        tail->next =p;
        p->pre =tail;
        tail =p;
     }
     tail->next =(*head);
     (*head)->pre =tail;
}
void print_cicle(node* head)
{
  node* p = head->next;
  while (p!=head)
  {
    cout << p->date <<" ";
    p=p->next;
  }
  
}
// 17
bool judge_duicheng(node* head)
{
  node* last =head->next;
  node* front =head->pre;
  while (last != front && front->next !=last)
  {
      if(last->date == front->date)
      {
       
        last=last->next;
        front = front->pre;
      }
      else{
           return false;
      }
  }
  return true;
 
}


int main(int argc, char const *argv[])
{
    Linklist L1;
    Linklist L2;
    node* head;
   
     //create_deltete_x(&L);
    // deltete_x( &L,3);
    // cout <<'\n';
    // 
    // cLinkList_Head( &L1);
    // cLinkList_Head( &L2);
  //   //delete_min( &head);
  //  // deltete_preate_x( &head, 3);
  //  // delete_part(& head ,1 ,5);
  // Linklist L= serch_same_node(L1,L2);
    //delete_min1( &L1);
    //divide_list( L1);
    //divide_list1( L1);
   //print_Linklist(L1);
   // prints(head);
  // cout << 1%2;
   Create_Circlelist(&head);
   cout << judge_duicheng(head);
    //cout << head->pre->date << head->next->date;

   //cout<<kmp_list( L1 , L2);
  // prints(head);
   return 0;

}



