#ifndef QUEEN_H__
#define QUEEN_H__
#define SIZE 10
#include<iostream>
using namespace std;
/*队列有三种 方法检测 
第一: rear的下一个预留出来

 第二：设置           设置队列的大小
 第三：设置 flag  入队时flag =1 当 rear和front相等是且flag =1时对满
                 出队时flag = 0 当rear和front相等时flag =0 时对空
                出队入队都让flag发生变化
*/
typedef struct  queen
{
    int date[SIZE];
    int front;
    int rear;

}queen;

typedef struct L_queen
{
    int  date;
    struct L_queen* next;    
    struct L_queen* front;
    struct L_queen* rear;
}L_queen ,*Link_queen;

void Initqueen(queen *q);
bool QueueEmpty(queen q);
void Enqueen(queen *q, int value);
void DeQueue(queen *q,int* value);
int GetVal(queen q );

void InitLinkQueen(Link_queen *q);
bool QueueLinkEmpty(Link_queen q);
void EnLinkqueen(Link_queen *q, int value);
void DeLinkQueue(Link_queen *q,int* value);
int GetLinkVal(Link_queen q );




#endif 
