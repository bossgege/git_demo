#include<iostream>

using namespace std ;

class Mystring
{
    friend ostream& operator<<(ostream  &out , Mystring ob);
    friend istream& operator>>(istream  &cin , Mystring ob);// 重载 >>
private:
     char* str;
     int size;
public:
    Mystring();
    Mystring(char* str);
    Mystring(const Mystring &ob);
    ~Mystring();
   char& operator [](int pos);
   Mystring  operator+(Mystring ob);
     Mystring  operator+(char* str);
      Mystring&  operator=(Mystring ob);
      Mystring&  operator=(char* str);
      bool  operator>(Mystring ob);
};

Mystring::Mystring(/* args */)
{
    str =NULL;
    size =0;
}
Mystring::Mystring(char* str)
{
    size = sizeof(str)+1;
    this->str = new char[size+1];
    memset(this->str,0,size+1);
    strcpy(this->str,str); 

}
Mystring::Mystring(const Mystring &ob)
{
      size =ob.size;
      str = new char[size+1];
       memset(str,0,size+1);
       strcpy(str,ob.str); 
}

Mystring::~Mystring()
{
    if(str!=NULL);
    delete [] str;
    str=NULL;
}

ostream& operator<<(ostream  &out , Mystring ob) // 重载 <<
{
       out<<ob.str;
       return cout;
}
istream& operator>>(istream  &cin , Mystring &ob) // 重载 >>  操作外界的值，需要进行引用
{
    char buf []="";
    cin >>buf;

    if(ob.str !=NULL)
    {
        delete [] ob.str;
        ob.str =NULL;
    }

    ob.size =strlen(buf);
    ob.str =new char[ob.size+1];
    memset(ob.str,0,size+1);
    strcpy(ob.str,buf);
    return cin;
}
  char& Mystring::operator [](int pos)
  {
    if(pos <0 || pos>=size)
    {
        cout <<"error";
    }
    return  str[pos];

  }

Mystring Mystring:: operator+(Mystring ob)
{
    Mystring temp;
    temp.size =size+ob.size +1;
     temp.str = new char[temp.size+1];
     memset(temp.str,0,temp.size);
     strcpy(temp.str,this->str);
     strcat(temp.str,ob.str);

    return  temp;  // 局部不能用引用


}
Mystring Mystring:: operator+(char* str)
{
    Mystring temp;
    temp.size =size+strlen(str);
     temp.str = new char[temp.size+1];
     memset(temp.str,0,temp.size);
     strcpy(temp.str,this->str);
     strcat(temp.str,str);

    return  temp;  // 局部不能用引用
}
Mystring&  Mystring::  operator=(Mystring ob)
{
// str2= str1
    if(this->str !=NULL)
    {
        delete [] this->str;
        this->str= NULL;
    }
    this->size =ob.size;
    this->str =new char [this->size+1];
    memset(this->str,0,this->size+1);
    strcpy(this->str,ob.str);
    return *this;

}

Mystring&  Mystring::  operator=(char* str)
{
// str2= str1
    if(this->str !=NULL)
    {
        delete [] this->str;
        this->str= NULL;
    }
    this->size =strlen(str);
    this->str =new char [this->size+1];
    memset(this->str,0,this->size+1);
    strcpy(this->str,str);
    return *this;

}
 bool Mystring:: operator>(Mystring ob)
 {
        if(this->str ==NULL || ob.str ==NULL) return 0;

        if(strcmp(this->str,ob.str)>0)return 1;
        return 0;
 }


int main(int argc, char const *argv[])
{
    Mystring  s1( "hello");
    cout << s1; // 输出对象，<< 进行重载

    Mystring s2;
    cin >>s2;

    Mystring s3 ="hello";

    s2= s3;   // 对象赋值有指针成员，会调用析构函数析构两次，必须重载 =
    cout<<s3[1];
    s3[1]='E';
    cout<<s3[1];
    cout << s1+s2;
    return 0;
}
