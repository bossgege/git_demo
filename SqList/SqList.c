#include "SqList.h"
#include<stdio.h>
#include"SqList_test.h"

void Init_SqList(sqList L) // 传递的地址 修改数据
{
    
     L->date = malloc(SIZE*sizeof(int)); // 给数组开辟内存大小
     L->length =0;
      
   
}

int  Print_List(SqList L) // 不需要对数据进行操作 传入的是顺序表
{
    if(L.length ==0) return 0;
    for (int i = 0; i < L.length; i++)
    {
       printf("%d ",L.date[i]);
    }
        return 1;
}

int List_Insert(SqList* L , int pos , int val)
{
   if(pos > L->length +1 || pos <1)  // 判断输入位置合法
   {
    printf("input error\n");  return 0;
   }
   int i=0; 
   for ( i = L->length-1; i >=pos-1; i--) // 移动元素 （细节： 数组的下标跟我们要插入的值始终小1）
   {
        L->date[i+1] = L->date[i];
   }
   L->date[pos-1]= val;
   L->length++;
   return 1;

}

int List_Delete_pos(sqList L ,int pos ,int* val)
{
    if(pos <1 | pos > L->length) return 0;  // 位置判断
    *val=L->date[pos-1];
      // 不用加判断条件
        for (size_t i = pos-1; i < L->length-1; i++) // 位置始终与数组的下标小1
        {
            L->date[i] = L->date[i+1];
        }
        L->length--; 
    
    return 1;
}

int List_Delete_val(sqList L,int val) 
{
    int j=0;
    while (val != L->date[j]) // 找到值的下标
    {
       j++;
    } 
    if(j>= L->length)return 0;
    if ( val == L->date[j])
    {
        for (size_t i = j; i < L->length-1; i++) //向前移动删除 
        {
           L->date[i] = L->date[i+1];
        }
        L->length--;
        
    }
    return 1;
    //List_Delete_pos(L,j+1,&val); // 传入的是位置  j+1
    
}

 int List_Get_val(SqList L ,int pos)
 {
    return  L.date[pos-1];
 }
 int main(int argc, char const *argv[])
 {
     SqList  L1; // 声明一个顺序表
     SqList  L2; // 声明一个顺序表
     SqList  L;
     int x=0;
     Init_SqList(&L1); //  传入的是顺序表的地址，用指针接收的
     Init_SqList(&L2); //  传入的是顺序表的地址，用指针接收的
    
   
  printf ("%d",fun_min( &L2));
    return 0;
 }
 