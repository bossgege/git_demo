#ifndef __SqList_H__
#define __SqList_H__
#include <stdlib.h>

#define SIZE 40
typedef struct  {

    int* date;
    int  length;
}SqList,*sqList; // 定义了一个 SqList的指针  方便后面形参的书写



void Init_SqList(sqList L);

 int List_Insert(sqList L , int pos , int val);
 int List_Delete_pos(sqList L ,int pos ,int* val);
 int List_Delete_val(sqList L,int val);
 int List_Get_val(SqList L ,int pos);
 int  List_Print(SqList L);

#endif