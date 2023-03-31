#ifndef XITI_H
#define XITI_H

#include<iostream>
using namespace std;

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





typedef Lnode* Linklist;
void create_deltete_x(Linklist* L);
void deltete_x(Linklist* L,int x);
void print_Linklist(Linklist L);
void cLinkList_Head(Linklist *head);
void  delete_part(Linklist* head ,int m ,int n);
#endif 
