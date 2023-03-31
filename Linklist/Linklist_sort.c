#include "Linklist_sort.h"

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Bubble_sort(Linklist *head)
{
    Linklist move = NULL; // 移动交换顺序
    Linklist turn = NULL; // 控制轮数
    Linklist save = NULL; // 记录每次交换的最后一个节点 ， 优化
    for (turn = (*head)->next; turn->next != NULL; turn = turn->next)
    {
        int flag = 0;
        for (move = (*head)->next; move->next != save; move = move->next)
        {
            if (move->date > move->next->date)
            {
                swap(&(move->date), &(move->next->date));
            }
            flag = 1;
        }
        if (!flag)
            return;  // 已经有序了 直接退出
        save = move; // 记录每一次的交换的最后一个元素
    }
}
void Insert_sort(Linklist *head)
{
    Linklist disorderMove; // 用来链表
    Linklist orderMove;    // 用来判断的插入的位置
    Linklist back;         // 保留要插入节点的 下一个结点
    Linklist front;        // 保留插入节点的前一个结点的位置

    disorderMove = (*head)->next->next; // 不是 heaed->next  考虑到要插入的第一个节点没有前驱结点
    orderMove = (*head);                //  总是那 orderMove的下一个结点与  disorderMove 进行比较
    front = (*head)->next;              // 假定第一结点总是有序的

    while (disorderMove != NULL)
    {
        while (orderMove->next != disorderMove)
        {
            if (disorderMove->date < orderMove->next->date)
            {
                back = disorderMove->next;            // 保存插入节点的下一个结点
                disorderMove->next = orderMove->next; // 断链插入节点
                orderMove->next = disorderMove;       // 将要插入的结点放到大的前面
                front->next = back;                   // 防止断链
                orderMove = front;                    // 后移 为了继续遍历  因为前面的都是有序的，每次都可以给到
            }
            break; // 插入完成后直接跳出
        }
        front = disorderMove;
        disorderMove = disorderMove->next;
        orderMove = (*head); // 每次都将查找要遍历的结点指向head
    }
}