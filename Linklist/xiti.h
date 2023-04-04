#ifndef XITI_H
#define XITI_H

#include<iostream>
using namespace std;
  #include <string.h>
struct Lnode
{
    int date;
    struct  Lnode* next;
};

struct node
{
    int date;
    struct node* next;
    struct node* pre;
};
struct Node
{
    int date;
    struct Node * next;
    struct Node *pre;
    int fre=0;
};





typedef Lnode* Linklist;
void create_deltete_x(Linklist* L);
void deltete_x(Linklist* L,int x);
void print_Linklist(Linklist L);
void cLinkList_Head(Linklist *head);
void  delete_part(Linklist* head ,int m ,int n);
#endif 
