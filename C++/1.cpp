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


int main(int argc, char const *argv[])
{
    Point p;
    p.set_x(10);
    Circle c;
    c.set_r(6);
   cout<< c.judge_C(p);
    return 0;
}
int main(int agrc ,int* argv[])
{
    Dage d1("hello");
    Dage d2 =d1;

}