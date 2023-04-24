#include <iostream>
using namespace std;
#define SIZE 10
typedef struct node
{
   char c;  
   struct node* next;
   
}node , *Linklist;
typedef struct
{
    char date[10];
    int top;
}sqstack;
void InitStack(sqstack *s)
{
    s->top =-1;
}
void Push(sqstack *s, char val)
{
    if(s->top>SIZE -1)return;

    s->date[++s->top]=val;
}
void pop(sqstack *s ,char* val)
{
    if(s->top ==-1)return;

    *val = s->date[s->top--];
}
bool IsEmpty(sqstack s)
{
    if(s.top ==-1)return true;
    return false;
}
void create_list(Linklist * L )
{
    (*L) =  new node;
    (*L)->next =NULL;
    cout << "input num"<<endl;
    int nums;
    cin >> nums;
    Linklist tail =new node;
    tail->next =NULL;
    tail = (*L);
    for (int i = 0; i < nums; i++)
    {
        char c;
        cin >>c;
       Linklist p = new node;
       p->c =c;
       p->next =NULL;
       if(i==0)    // 不能直接插在tail的后面，需要将第一个进行赋值
       {
        (*L) =p;
         tail =p;
       } 
       else  {
         tail->next =p;
          tail =p;
       }
      
      
    }
    tail->next =NULL;
   
}
void print_list(Linklist L)
{
    Linklist p =L;
    while (p)
    {
       cout <<p->c;
       p=p->next;
      
    }


}
// 判断 字符串是否中心对称
bool is_dui(Linklist L )
{
    int length=0;
    Linklist p = L; 
    sqstack s;
    InitStack( &s);
    while (p) // 计算链表长度
    {
       p=p->next;

       length++;
      
    }
    
    Linklist q = L;  //  不能 又 进行重新赋值  q= L;
    if(length % 2 ==0)  //链表为偶数
    {
        int x =length /2;
        while (x--)  // 链表前一半先入栈
        {
         Push(&s, q->c);
         q=q->next;
        }
        cout <<q->c;
        while (q)  //后一半出栈比较
        {
            char c ;
            pop(&s,&c);
            if(q->c != c)
            {
                return false;
            }
            else{
                q=q->next;
            }
        }     
    }
    else {  //奇数
        int x =length /2;
        while (x--)  // 链表前一半先入栈
        {
         Push(&s, q->c);
         q=q->next;
        }
         q=q->next; //从中心位置的后一个进行比较
        while (q)  //后一半出栈比较
        {
            char c ;
            pop(&s,&c);
            if(q->c != c)
            {
                return false;
            }
            else{
                q=q->next;
            }
    
    }
    }
    return true;
}

void judge(char* zifu)
{
    sqstack s;
   InitStack( &s);  
   int i=0;
   char c;
   int flag=0;
  while (zifu[i])
  {
     switch (zifu[i])
     {
      case '(' :
                Push(&s,zifu[i]);
        break;
      case '[' :
                Push(&s,zifu[i]);
        break;
      case '{' :
                Push(&s,zifu[i]);
        break;

      case ')' :
                 pop(&s,&c); 
                 if('(' != c) flag=1;
        break;
      case ']' :
                 pop(&s,&c); 
                 if('[' != c) flag=1;
        break;
      case '}' :
                 pop(&s,&c); 
                 if('{' != c) flag=1;
        break; 
     
     }  
     i++; 
  }
  if(flag)cout <<"括号不匹配"<<endl;
  else
    cout <<"匹配成功"<<endl;  



}

void sort(char * zifu)
{
    sqstack s;
    InitStack( &s); 
    char *p ,*q;
    p=zifu;
    q=zifu;
    cout << p <<endl <<q<<endl;
    while (*p)
    {
        if(*p =='H')
        {
            Push(&s,*p);                
        }
        else{
            *q =*p;
             q++;       
        }  
        p++;  
    }
    while (!IsEmpty(s))
    {
        char c;
        pop(&s,&c);
        *q=c;
        q++;
    }

}



int main(int argc, char const *argv[])
{
    sort("HSHSHSH");
    return 0;
}
