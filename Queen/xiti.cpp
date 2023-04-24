#define SIZE 10
#include<iostream>
using namespace std;

typedef struct queue_f
{
   int flag;
   int date[SIZE];
   int  front;
   int  rear;

}queue_f;

typedef struct stack
{
     int date[SIZE];
     int top;
}stack;


void InitQueen(queue_f *q)
{
  (*q).flag =0;
  (*q).rear=(*q).front =0;

}
void Enqueue(queue_f *q,int val)
{
    if((*q).front ==(*q).rear && (*q).flag ==1)
    {
        cout <<"满了"<<endl;
        return;
    }
    (*q).date[(*q).rear]=val;
    (*q).rear = ((*q).rear +1) %SIZE; 
    (*q).flag =1;
}
void Dequeue(queue_f *q,int* val)
{
   if( (*q).front ==(*q).rear && (*q).flag ==0)
   {
     cout <<"空了"<<endl;
     return;
   }
    *val= (*q).date[(*q).front];
    (*q).front = ((*q).front +1) %SIZE;
     (*q).flag =0; 
}
bool IsEmpty(queue_f q)
{
     if( q.front ==q.rear && q.flag ==0)return true;
     return false;
   
}

void InitStack(stack *s)
{
    (*s).top =-1;
}
void  Push(stack *s , int val)
{
    if((*s).top == SIZE)
    {
        cout << "栈满"<<endl;
        return;
    }
    (*s).date[++(*s).top]=val;
}

void Pop(stack *s , int* val)
{
    if((*s).top == -1)
    {
        cout << "栈空"<<endl;
        return;
    }
    *val =(*s).date[(*s).top];
    (*s).top --;
}
bool IsEmptyStack(stack s)
{
    if(s.top ==-1)return true;
    return false;
}
/**
 * @brief 队列中的数据进行逆置
 * 
 */
void change()
{
   stack s;
   InitStack(&s);
   queue_f q;
   InitQueen(&q);
   Enqueue(&q,1);
   Enqueue(&q,2);
   Enqueue(&q,3);

   while (!IsEmpty(q))
   {
        int val;
        Dequeue(&q,&val);
        Push(&s,val);
   }
   while (!IsEmptyStack(s))
   {
        int val;
        Pop(&s,&val);
        Enqueue(&q,val);
   }
   cout << q.date[q.front];

}


int main(int argc, char const *argv[])
{
    
    change();    
    return 0;
}

