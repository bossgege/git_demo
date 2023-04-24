#include"Stack.h"


void InitStack(sqstack* s)
{
   s->top =-1;  // 初始化栈顶为 -1;   栈顶永远指向的栈顶元素
   // 数组已经给定了空间大小不用初始化
}

void Push(sqstack* s ,int val)
{
    if(s->top == SIZE-1) //  top 指向的是栈顶元素
    {
        return;
    }
    s->date[++s->top] =val;  // 先移动栈顶后 赋值 
}
void pop(sqstack *s)
{
    if(s->top ==-1) //  到达栈底 返回
    {
        return;
    }
    s->top --;
}
int get_val(sqstack s)
{
    if(s.top ==-1)
    {
        return -1;
    }
    return s.date[s.top];
}
bool is_empty(sqstack s)
{
    if (s.top ==-1)
    {
       return true;
    }
    return false;
    
}
void create_stack(sqstack *s)
{
    int nums;
    cout << "input nums"<<endl;
    cin >>nums;
    for (size_t i = 0; i < nums; i++)
    {
       int val ;
       cin >>val;
       s->date[++s->top]=val;

    }
    
}

void print_stack(sqstack s)
{
    while (s.top != -1)
    {
      cout << s.date[s.top--]<< '\t';
    }
    
}
void InitStack_s(sqstack_s *s)
{
    s->top1 = -1;
    s->top2 = SIZE ;

}

void Push_s(sqstack_s *s,int StackNum ,int val)
{
 if(s->top2 - s->top1 ==1)  // 栈满
 {
    return;
 }
    if(StackNum == 1)
    {
       s->date[++s->top1]=val;
    }
    else if (StackNum ==2) {
        
        s->date[--s->top2]=val;
    }

}
void Pop_s(sqstack_s *s,int StackNum)
{
    if(StackNum ==1)
    {
        if(s->top1 ==-1)
        {
            return;
        }
        s->top1 --;
    }
    if(StackNum ==2)
    {
        if(s->top2 ==SIZE)
        {
            return;
        }
        s->top2 ++;
    }

}

int main(int argc, char const *argv[])
{
    // sqstack s;
    // InitStack(&s);
    // // create_stack(&s);
    // // print_stack(s); 
    sqstack_s s;
    InitStack_s(&s);
    Push_s(&s, 1, 3);
  
   return 0;
}
