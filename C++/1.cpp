#include<iostream>

using namespace std ;

class Point
{
private:
    int x;
    int y;
public:
    void set_x(int x1)
    {
        x=x1;
    }
    void set_y(int y1)
    {
        y=y1;
    }
    int get_x(void){return x;}
    int get_y(void){return y;}

};
class Circle
{
private:
   Point p;
   int r;
public:
   void set_r(int R){r=R;}
   int get_r(){return r;};
   void set_p(int x1 ,int y1){p.set_x(x1);p.set_y(y1);}
   int judge_C(Point &ob)
   {
     if(ob.get_x() -p.get_x() >r){return 1;}
     else if(ob.get_x()<r){return -1;}
     else if(ob.get_x() ==r){return 0;}
     return 0;
   }
};

class Dage
{
private:
   char *name;
public:
    Dage();  //无参构造
    Dage(char* p); //有参构造
    ~Dage();
    Dage(const Dage &ob);
};

Dage::Dage(/* args */)
{
   
    name =NULL;
}
Dage::Dage(char* p)
{
    name  = (char*)malloc(strlen(p)+1);
    strcpy(name ,p);
}

Dage::~Dage()
{
    free(name);
    name =NULL;
}
Dage::Dage(const Dage& ob)
{
  name  = (char*)malloc(strlen(ob.name)+1);
    strcpy(name ,p);
}
class TV;  //声明类 ，防止下面的出现，下面的类不能中不能直接访问另一个类的数据 ，

class Remote
{
private:
   TV *p;  // 定义指针变量操作电视
public:
    Remote(TV *p);
    ~Remote();
    void offoron(void);
    void  upVolume(void);
    void  dowmVolume(void);   //电视机的基本功能，遥控器也有

    void setchannel(int channel);
    

};

class TV{

    enum { OFF ,ON};
    enum{  minVol ,maxVol=10};
    enum {minChan , maxChan=25};  // 在类中定义匿名枚举类型，保存类的封装性
    friend void Remote :: setchannel(int channle);  // 把遥控器的设置频道函数作为友元函数 ，不知道 Remote 这个类 ，提前
    private : 
        int state;
        int volume;
        int channle;
    friend class Remote;    
    public:
        TV()  // 构造函数初始化
        {
            state =OFF;
           volume =minVol ;
           channle = minChan;
        }
    void offoron(void);
    void  upVolume(void);
    void  dowmVolume(void);
    

};
 void TV:: offoron()
 {
        state  = (state == OFF ? OFF : ON);
 }

void  TV ::upVolume()
{
    volume ++;

}
void TV ::dowmVolume()
{
    volume --;
}



Remote::Remote(TV *p)
{
    p->offoron();
}

Remote::~Remote()
{

}

 void Remote:: offoron()
 {
       p->offoron();  //直接调用方法
 }

void  Remote ::upVolume()
{
   p->upVolume();

}
void Remote ::dowmVolume()
{
   p->dowmVolume();
}

void  Remote :: setchannel(int channel)
{
    p->channle =channel;
}

class Arrary
{
    private:
            int* arr;
            int  size;
            int capacity;
    public:
            Arrary(void); // 无参构造
            Arrary(int capacity); // 有参构造
            Arrary(const Arrary &ob);  // 有指针成员完成的是深拷贝
            ~Arrary();  // 析构
            void pushBack(int elem);
            int  getCapcity();
};

 int Arrary :: getCapcity(int elem)
 {
    if(size == capacity)
    {
        int* temp = new int [2*capacity]; // 申请空间
        memcpy(temp ,arr ,capacity*sizeof(int));  // 内存拷贝

        delete [] arr;      //释放原有空间
        arr = temp;     // 更新空间
    }
    arr[size++] = elem;


 }
Arrary ::Arrary()
{
    capacity =5;
    size =0;
    arr =  new int[capacity];
    memset(arr, 0 ,0);
}
Arrary ::Arrary(int  capacity)
{
  this->capacity =capacity;
    size =0;
    arr =  new int[capacity];
    memset(arr, 0 ,0);
}
 Arrary ::Arrary(const Arrary &ob)
 {
    capacity =ob.capacity;
    size = ob.size;
    arr = new int[capacity]; // 深拷贝 重新开辟内存
   memcpy(arr,ob.arr,capacity); //内存进行赋值
 }
Arrary ::~Arrary()
{
  delete [] arr;    
  arr =NULL;  
}
 int Arrary :: getCapcity()
 {
    return capacity;
 }
int main(int agrc ,int* argv[])
{
   TV tv;
   tv.offoron();
   tv.offoron();

   Remote re(&tv); 
    re.dowmVolume();  

}