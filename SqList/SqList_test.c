#include"SqList_test.h"

/*
1.
*/
int delete_val_min(sqList L )
{
    int min = L->date[0];
    int min_i=0;
    for (size_t i = 1; i < L->length; i++)
    {
        if(L->date[i] <min)
        {
            min = L->date[i];
            min_i=i;
        }
    }
    L->date[min_i] = L->date[L->length-1];
    L->length --;


}
/*
2
*/
void  reverse(sqList L)
{
    for (size_t i = 0; i < L->length/2; i++)
    {
       int temp = L->date[i];
       L->date[i]= L->date[L->length-1-i];
       L->date[L->length-1-i]=temp;
    }   
}

/*
3.
*/
void delete_val_all(sqList L,int val)
{
    //  int k=0; // 双指针 指向同一个位置
    // for (size_t i = 0; i < L->length; i++)
    // {
    //    if(L->date[i]!=val)    // 利用值相等的方法
    //    {
    //     L->date[k++]=L->date[i];
    //    }

    // }
    // L->length=k;   

    int k=0;
    for (size_t i = 0; i < L->length; i++)
    {
        if(val== L->date[i])  // 利用值不相等 跳跳法 
        {
            k++;
        }
        else {
            L->date[i-k] =L->date[i]; 
        }
    }
    L->length-=k;

}
/*
4
*/
int delete_val_section_order(sqList L, int m,int n)
{
    if( m > n || n>L->length ) return 0;
    int i=0;
    while(i<L->length && L->date[i] < m ) // 找到大于左区间的第一个值下标
    {
        i++;
    }
    int j=i;
     while(j<L->length && L->date[j] <= n ) // 找到大于右区间的第一个值下标
    {
        j++;
    }
    for (; j < L->length; i++,j++) //将后面的值移到前面
    {
       L->date[i] = L->date[j];
    }
    L->length = i;
    
}

/*
5
*/
int delete_val_section(sqList L, int m,int n)
{
    if( m>n || m > L->length) return 0;

    int k=0;
    for (size_t i = 0; i < L->length; i++)
    {
       if(L->date[i] > m && L->date[i] < n)  // 跳跳法 在区间就跳过
       {
        k++;
       }
       else {                              // 不在区间就进行移动
         L->date[i-k]= L->date[i];
       }
    }
    L->length -=k;
}

/*
6.
*/
void delete_val_repeat(sqList L)
{
    int k=0;
    for (size_t i = 0; i < L->length; i++)
    {
      if(L->date[k]!=L->date[i])
      {
         L->date[++k]=L->date[i];//前置++
      }
    }
    L->length =k;
    
}
/*
7
*/
SqList  merge_list(sqList L1 ,sqList L2)
{
    int L1_i=0;
    int L2_i=0;
    int L_i=0;
    SqList L;
    Init_SqList(&L);
    while (L1_i <L1->length && L2_i <L2->length) //合并
    {
       if(L1->date[L1_i] < L2->date[L2_i])
       {
         L.date[L_i++]= L1->date[L1_i++];
       }
       else   {
         L.date[L_i++]= L2->date[L2_i++];
       }
    }
    while (L1_i <L1->length)  //连接L1
    {
        L.date[L_i++]=L2->date[L1_i++];
    }
     while (L2_i <L2->length) //连接L2
    {
        L.date[L_i++]=L2->date[L2_i++];
    }
    L.length=L_i;
    return L;
    
}

/*
8
*/
 void reverse_1 (sqList L , int m ,int n)
 {

    while(m<n)
    {
       int temp= L->date[m-1];
       L->date[m-1] = L->date[n-1];
       L->date[n-1] =temp;
       m++;
       n--;
    }
 }
 void  cycle_list(sqList L , int x)
 {
    reverse_1(L,1,x);
    reverse_1(L,x+1,L->length);
    reverse_1(L,1,L->length);

 }
 /*
 9
 */
void swap(int* m ,int *n)
{
    int temp= *m;
    *m=*n;
    *n=temp;
}
int  serch_val(sqList L ,int val)
{
    int left =0 ; 
    int right = L->length -1;
    int mid ;
    while (left <= right )
    {
       mid =  (left + right) /2;
        if(L->date[mid] < val)
        {
                left = mid+1;
        }
        else if (L->date[mid] > val)
        {
                 right = mid-1;
        }
        else if (L->date[mid]== val)
        {
            break;
        }
    }
    if( L->date[mid] == val && mid !=L->length-1)  // 找到值进行交换
    {
      swap(&L->date[mid],&L->date[mid+1]);
    } 
    else 
    {
       List_Insert(L,mid+1,val);
    }
    
     
}
/*
11
*/
int  search_mid(sqList L1,sqList L2,int *val)
{
    int L1_i=0;   //方法一  利用归并排序找
    int L2_i=0;
    int mid=0;
    int arr[L1->length+L2->length];
    while (L1_i<L1->length && L1_i <L2->length )
    {
        if(L1->date[L1_i]<L2->date[L2_i])
        {
           
            arr[mid++]=L1->date[ L1_i++];
        }
       else  if(L1->date[L1_i]>L2->date[L2_i])
        {
           
            arr[mid++]=L1->date[ L2_i++];
        }
    }
    while (L1_i <L1->length)
    {
        arr[mid++]=L1->date[ L1_i++];
    }
     while (L2_i <L2->length)
    {
        arr[mid++]=L2->date[ L2_i++];
    }
    *val=arr[mid/2-1];
    
    
   /* int L1_left,L2_left;   //  方法二  二分
    L1_left=L2_left=0;
    int L1_right,L2_right;
   L1_right = L1->length-1;
   L2_right = L2->length-1;
    int  L1_mid=0 ,L2_mid=0;
    while ( L1_left != L1_right ||  L2_left != L2_right)
    {
       L1_mid =(L1_left +L1_right)/2;
       L2_mid =(L2_left +L2_right)/2;
        if(L1->date[L1_mid] == L2->date[L2_mid]) return  L1->date[L1_mid];
        if ( L1->date[L1_mid]< L2->date[L2_mid])
        {
            if((L1_left+L1_right)%2==0) // 如果为奇数
            {
                L1_left=L1_mid;
                L2_right = L2_mid;  // 舍弃 L1 中位数前面的 和 L2中位数后面的
            }
            else{          // 如果为偶数 舍弃 L1 的中位数和前面的
                 L1_left=L1_mid+1;
                L2_right = L2_mid;  // 舍弃 L1 中位数前面的和中位数 和 L2中位数后面的
            }
        }
        else{
            if((L2_right+L2_left)%2==0) // 如果为奇数
            { 
                L2_left = L2_mid;  // 舍弃 L2 中位数前面的 和 L1中位数后面的
                L1_right=L1_mid;
               
            }
            else{
                 L2_left = L2_mid+1;  // 舍弃 L1 中位数前面的和中位数 和 L2中位数后面的
                 L1_right=L1_mid;
               
            }

        }
    }
    return L1->date[L1_mid] < L2->date[L2_mid]  ? L1->date[L1_mid] :L2->date[L2_mid] ;
 */
}

/*
12
*/

int  fund_main(sqList L)
{
    int* arr_cout = (int*) malloc(sizeof(int)* L->length);
     
     for (int  i = 0; i < L->length; i++)
     {
         arr_cout[L->date[i]]++;  // 遍历数组然后计数
     }
     for (size_t i = 0; i < L->length; i++)
     {
        if(arr_cout[i] > L->length/2)  // 找主值
        return  arr_cout[i];
     }
     return 0;

}
int fun_min(sqList L)
{
    int* arr_cout = (int*) malloc(sizeof(int)* L->length);
    memset(arr_cout,0,sizeof(int)* L->length);
    for (size_t i = 0; i < L->length; i++)
    {
          if(L->date[i]< L->length) //超过数组大小的值可以直接忽略掉
          {
            arr_cout[L->date[i]]=1;  // 遍历数组然后计数
          }
        
          
    }
    int k=1;  //  从 1 开始
    for ( ; k <  L->length; k++)
    {
        
       if(arr_cout[k]==0) 
       {
         return k;
       }
      


    }
    return k+1; 
    

}