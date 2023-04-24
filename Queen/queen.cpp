#include"queen.h"



void Initqueen(queen *q)
{
    q->front =q->rear =0;
}
bool QueueEmpty(queen q)
{
    if(q.front ==q.rear)return true;
    return false;
}
void Enqueen(queen *q, int value)
{
    if( (q->rear +1)%SIZE == q->front)
    {
        cout <<"对列满了"<<endl;

    }
    q->date[q->rear] = value;
    q->rear = (q->rear+1) % SIZE;

}
void DeQueue(queen *q,int* value)
{
    if(q->rear ==q->front)
    {
        cout << "对列空了"<<endl;
    }
   *value = q->date[q->front];
    q->front = (q->front+1) %SIZE;
}
int GetVal(queen q )
{
   return q.date[q.front];
}




void InitLinkQueen(Link_queen *q)
{
 (*q)->front =(*q)->next =(*q)->rear =NULL;
}
bool QueueLinkEmpty(Link_queen q)
{
    if(q->front == q->rear)return true;
    return false;
}
void EnLinkqueen(Link_queen *q, int value)
{
    Link_queen p = new L_queen;
    p->date =value;
    p->next =NULL;
    (*q)->rear->next =p;   
    (*q)->rear=p;
}
void DeLinkQueue(Link_queen *q,int* value)
{
    *value = (*q)->front->date; 
    (*q)->front =(*q)->next;
}
void CreateQueen(Link_queen *q)
{
  int nums;
  cin >>nums;
  for (size_t i = 0; i < nums; i++)
  {
        int value;
        cin >>value;
       Link_queen p = new L_queen;
        p->date =value;
        p->next =NULL; 
        if(i==0)
        {
            (*q)=p;
            (*q)->rear =p;
            (*q)->front =p;
        }
        else{
            (*q)->rear->next =p;
            (*q)->rear =p;
        }
        
  }
  (*q)->rear->next =NULL;  

}

void print_Queen(Link_queen q)
{
    Link_queen p=q;

    while (p)
    {
       cout << p->date;
       p=p->next;
    }
    
}


int main(int argc, char const *argv[])
{
    Link_queen q;
    InitLinkQueen(&q);
    CreateQueen( &q);
    EnLinkqueen(&q,100);
    cout << q->front->date;
    int value;
    DeLinkQueue(&q,&value);
     cout << q->front->date;    
    return 0;
}
