#include<iostream>
#include <string>

using namespace std;

class Person
{
    friend ostream & operator <<( ostream &out ,Person &ob);
   friend  istream& operator >>(istream &cin , Person &ob);
private:
    int num;
    string name;
    float score;
public:
    Person();
    ~Person();

    void printclass();
    Person operator + (Person ob)
    {
        Person temp;
        temp.name =this->name +ob.name ; // this指针充当了一个成员函数
    }
    bool operator == (Person ob)
    {
       if(this->name ==ob.name ) return true;
       turn   false;
    }
    // xiao++ 先试用后++
   Person operator ++(int)
    {
            //  xiaowang = lucy ++  要考虑到 先将值赋给小王 ，然后 Lucy ++ 可以利用this 指针保存当前值然后再进行操作

            Person   old = *this; //保存旧值
            this->score++;
            return *this;  // 根据需求确定返回值类型  返回旧值
    }
   

    // ++xiao
   Person operator ++() //占位参数的用途
    {
            this->score++;
            return *this;
    }

};

Person::Person(int num , string name ,float score)
{
    this->num =num;
    this->name =name;
    this->score =score;
}

Person::~Person()
{

}
   void Person:: printclass()
   {



   }
ostream & operator <<( ostream &out ,Person ob) // 声明为友元函数进行访问 ,同时返回引用做文链式操作
{
    cout << ob.num <<cout <<ob.name ;
    return  out;
}

 istream& operator >>(istream &cin , Person ob)
{
    cin >> ob.num >>cout >>ob.name ;
}
Person operator +(Person ob2 ,Person ob1)
{
    Person temp;
    temp.name = ob1.name +ob2.name;
    temp.num =ob1.num+ob2.num;
    return  temp;  //   Person& operator +(Person &ob2 ,Person &ob1)   不能返回局部变量的引用  除非加 static

    // 另外 如果是这样 ，cout  的 函数形参不能加引用  因为返回的是一个对象


}


int main()
{
    Person p(10,"xiao",100);
    Person q(10,"xiao",100);
    Person x(10,"xiao",100);
    cout << p <<q ;  // 重载运算符, 左右两边两个运算对象，cout 是其他 用全局函数重载

    cout << p+q  <<endl;   // p+q 返回的是一个 对象   重载 <<  左边是cout  右边是类  所以 <<  的重载对象不能用引用
    cout << p+q + x <<endl;   // p+q 是一个局部对象，传入 重载 + 的函数 的参数是引用，又会进行报错 所以参数不嫩够用引用 
   
    return 0;

}




