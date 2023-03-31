#ifndef SqList_test__H
#define SqList_test__H
#include"SqList.h"
#include<stdio.h>
#include<string.h>
int delete_val_min(sqList L );
void  reverse(sqList L);
void delete_val_all(sqList L,int val);
int delete_val_section(sqList L, int m,int n);
void delete_val_repeat(sqList L);
int delete_val_section(sqList L, int m,int n);
SqList  merge_list(sqList L1 ,sqList L2);
 void reverse_1 (sqList L , int m ,int n);
  void  cycle_list(sqList L , int x);
  int  serch_val(sqList L ,int val);
   int  search_mid(sqList L1,sqList L2,int *val);
   int  fund_main(sqList L);
   int fun_min(sqList L);
#endif 
