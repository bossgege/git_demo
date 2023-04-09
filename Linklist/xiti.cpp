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
// 8/23

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

//18
void C_cicrellist(Linklist *L)
{
      (*L) = new Lnode ;
       (*L)->next =(*L);
      Linklist tial;
      tial = (*L);
      int nums;
      cout<< "input nums" <<endl;
      cin >> nums;
      for (size_t i = 0; i < nums; i++)
      {
          int date;
          cin >>date;
          if(i==0)
          {
            (*L)->date =date;  
          }
          else{
              Linklist p =new Lnode;
              p->date =date;
              tial->next =p;
              p->next = *L;
              tial =p;
          }
      }
        tial->next =(*L);
}

void Circlelist_insert(Linklist *L1 ,Linklist *L2)
{
      Linklist p = (*L1);
      while (p->next!=(*L1))  // 找到 L1的最后一个节点
      {
       p=p->next;
      }

      Linklist q = (*L2);
      while (q->next!=(*L2)) // 找到 L2的最后一个节点
      {
       q=q->next;
      }
      p->next =(*L2);   // 连接
      q->next =(*L1);  


}

// 19
void  create_list_c(Linklist *head)
{ 
   (*head) = new Lnode;
   (*head)->next =(*head);
   Linklist tail =(*head);

   int nums ;
   cin >>nums;
    for (size_t i = 0; i < nums; i++)
    {
        int date;
        cin >>date;
        Linklist p =new Lnode;
        p->date=date;
        p->next =tail;
        tail->next =p;
        tail =p;
    }
    tail->next =(*head);
}


void delete_min_c(Linklist *head)
{
   Linklist min;
  Linklist premin;
  Linklist temp;
  premin = (*head);
  min=(*head)->next;
  while ((*head)->next !=(*head)) // 控制轮数直到结点全部释放为止
  {
      premin = (*head);
      min=(*head)->next; // 假定第一结点为最小值
      Linklist temp;
      while (min->next!=(*head))
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
  free (head);   

}

void create_d_list(Node** head)
{
  cout << "input nums"<<endl;
  int nums ;
  cin >>nums;
   (*head)->next=(*head)->pre =NULL;
   Node* tail=(*head);
  for (size_t i = 0; i < nums; i++)
  {
      int date;
      cin >>date;
      if(i==0)
      {
        Node* p = new Node;
        p->date =date;  
        p->pre =p->next =NULL;
        (*head)->next =p;
        p->pre =(*head);
        tail =p;
      }
      else{
          
        Node* p = new Node;
        p->date =date;  
        p->pre =p->next =NULL;
        tail->next =p;
        p->pre =tail;
        tail =p;
      }
  }
  tail->next =NULL;

}
//20
void prints(Node* head)
{ 
  Node*  q = head->next;   // 要创建工作结点
  while (q)
    {
     
      cout << q->date <<'\t';
      q=q->next;
    }
 
}

void Locate(Node** head , int x)
{
  Node* p = (*head)->next;
  while (p!=NULL && p->date !=x) // 找x 的值
  {
   p=p->next;
  }
  if(!p){cout <<"结点不存在"; return;}
  else{
      cout << "访问 p结点:" << p->date<<endl;
       p->fre ++;

      Node* q = p->pre; 
      p->next->pre=p->pre;
      p->pre->next=p->next; // 将p 结点拿下来

      while (q !=(*head) && q->fre <=p->fre) // 查找到要插入的结点
      {
        q=q->pre;
      }

      p->next =q->next;
      q->next->pre=p;
      q->next=p;
      p->pre=q; // 插入节点

  }

}
void  fre_list(Node** head,int x)
{
  Node* p =(*head)->next;
  while (p!=NULL && p->date !=x)
  {
    p=p->next;
  }
  p->fre ++;
  cout << "当前结点的频域"<<p->fre<<endl;

}
void print_fre(Node* head)
{
   Node* p =head->next;
   while (p)
   {
    cout << "当前结点的数据:" <<p->date <<"频域："<<p->fre<<endl;
    p=p->next;
   }
   
}

//21
void  create_c(Lnode ** L)
{
  (*L) = new Lnode;
  (*L)->next =NULL;
  
  cout<< "input nums"<<endl;
  int nums;
  cin>>nums;
  Lnode* tail;
  tail=(*L);
  Lnode *q;
  for (size_t i = 0; i < nums; i++)
  {
      int date ;
      cin >> date;
      if(i==0)
      {
        Lnode * p =new Lnode;
        p->next =NULL;
        p->date=date;
        (*L)=p;
        tail=(*L);
      }
      else{
         Lnode * p =new Lnode;
        p->next =NULL;
        p->date=date;
        tail->next =p;
        tail =p;     
      }
      if(i==2) q =tail;
  }
  tail->next =q;
}
 bool is_cicle(Lnode* L)
 {
    Lnode *low;
    Lnode *fast;
    low=L;
    fast =L->next;
    while (fast !=NULL && low!=NULL)
    {
       low =low->next;
       fast=fast->next->next;
       if(fast ==low)return true;
    }
    return false;
 }

//22
void  create_c1(Lnode ** L)
{
  (*L) = new Lnode;
  (*L)->next =NULL;
  
  cout<< "input nums"<<endl;
  int nums;
  cin>>nums;
  Lnode* tail;
  tail=(*L);
  Lnode *q;
  for (size_t i = 0; i < nums; i++)
  {
      int date ;
      cin >> date;
      if(i==0)
      {
        Lnode * p =new Lnode;
        p->next =NULL;
        p->date=date;
        (*L)=p;
        tail=(*L);
      }
      else{
         Lnode * p =new Lnode;
        p->next =NULL;
        p->date=date;
        tail->next =p;
        tail =p;     
      }
      
  }
  tail->next =NULL;
}

void get_pos(Lnode *L,int k)
{
  Lnode * fast;
  Lnode *slow;
  fast =  L; 
  slow =L;
  while (k--)
  {
    slow=slow->next;
  }
  while (slow)
  {
    fast=fast->next;
    slow =slow->next;
  }
  cout << "倒数第K个结点的值:"<<fast->date<<endl;



}

//24
void Create_Linklist(Lnode** head) //  等价于 Linklist head
{
    Lnode *p;  // 头插法创建  p为工作指针
     int nums;
    printf("input create nums\n");
    scanf("%d",&nums);
    Lnode *tail; // 创建尾结点 ，不是为指针
     tail=*head;
    for (size_t i = 0; i < nums; i++)  // 尾插法
    {
        int date;
        scanf("%d",&date);
        p = (Lnode*)malloc(sizeof(Lnode));
        p->date=date;
        p->next = NULL;
        tail->next = p;
        tail=p;
       
    } 
    tail->next =NULL;
}

void  delete_re(Lnode**L,int n) // 删除重复元素利用数组来进行操作，以时间换空间
{
  int* arr = new int[n+1];
  memset(arr,0,n*sizeof(int)); // 开辟一个数组大小为n 的数组 ，L中的数据不会大于n
  Lnode* p =(*L)->next;
  Lnode *pre =(*L);
  while(p)
  {
   
    if(arr[p->date]==0)   // 如果出现了 就将这个下标的值变为1 
    {
     arr[p->date]=1;
    }
    else if(arr[p->date]==1)
    {
       Lnode *temp =p->next;
       pre->next =p->next;
       free(p);
       p=temp;   
    }
    pre=p;
    p=p->next;
  }
}
void print_Linklist1(Lnode* head)
{
  Lnode* q =head->next;
  while (q)
  {
 cout <<q->date;
  q=q->next;
  }
  
}
//25
void Create_Linklist2(Lnode** L) //  等价于 Linklist head
{
    Lnode *p;  // 头插法创建  p为工作指针
     int nums;
    printf("input create nums\n");
    scanf("%d",&nums);
    Lnode *tail; // 创建尾结点 ，不是为指针
     tail=*L;
    for (size_t i = 0; i < nums; i++)  // 尾插法
    {
        int date;
        scanf("%d",&date);
        p = (Lnode*)malloc(sizeof(Lnode));
        p->date=date;
        p->next = NULL;
        if(i==0)
        {
           (*L)=p;
           tail=p;
        }
        else{
           tail->next = p;
           tail=p;
        } 
    } 
    tail->next =NULL;
}
void sort_list(Lnode **L)
{
  Lnode* slow=(*L);
  Lnode* fast=(*L)->next;

  while (fast->next!=NULL)  // 找到中间结点
  {
    fast=fast->next->next;
    slow =slow->next;
  }
  Lnode *q = slow->next;
  slow->next =NULL;
  while (q)  //  后面半段的链表进行逆置
  {
     Lnode* p =q->next;
     q->next =slow->next;
     slow->next =q;
     q=p;
  }
  
    
   



}
void print_L(Lnode* L)
{
  Lnode* p = L;
  while (p)
  {
    cout << p->date <<" ";
    p=p->next;
  }
  
}


int main(int argc, char const *argv[])
{
    Linklist L1;
   // Linklist L;
    Lnode *L;
   // Node* head;
   // create_c(&L);
   // print_Linklist(L);
   // cout<< is_cicle(L);
  // prints(head);
 
  Create_Linklist2(&L);
 sort_list(&L);
  print_L(L);
   return 0;

}



