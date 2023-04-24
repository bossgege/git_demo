#ifndef STACK_H__
#define STACK_H__
#define SIZE 10
#include <iostream>
using namespace std;
typedef struct 
{
    int  date[10];
    int  top;
    
}sqstack;
 
typedef struct 
{
    int  date[10];
    int  top1;
    int  top2;
    
}sqstack_s;

void InitStack_s(sqstack_s *s);

void Push_s(sqstack_s *s,int StackNum ,int val);
void Pop_s(sqstack_s *s,int StackNum );


void InitStack(sqstack* s);
void Push(sqstack* s,int val);
void pop(sqstack* s);
int get_val(sqstack s);
bool is_empty(sqstack s);
void create_stack(sqstack *s);
void print_stack(sqstack s);



#endif 
