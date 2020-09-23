#include <iostream>
using namespace std;

class A
{
private:
    char *buf;

public:
    A(int k)
    {
        buf = (char *)malloc(sizeof(buf));
        *buf = k;
    }
    virtual void Prin()
    {
        cout << "Prin come form class A" << endl;
    }
    virtual ~A()
    {
        cout << "A::~A()called" << endl;
    }
};
class B : public A
{

public:
    B(int _buf) : A(_buf) {}
    virtual void Prin()
    {
        cout << "Prin come from class B" << endl;
    }
    virtual ~B()
    {
        cout << "B::~B()called" << endl;
    }
};
void fun(A *a)
{
    delete a;
}
int main()
{
    A *a = new B(10);
    a->Prin();
    fun(a);
    B *b = new B(20);
    fun(b);
    return 0;
}
/*
[Inheritance & Polymorphism] Destructor 实时评测
 2020-07-08 23:59
 1000 ms
 32 MB
 刘亚男 ()
Destructor
Description
class A
{
public:
virtual void Prin()
{
cout<<"Prin come form class A"<<endl;
}
};
class B
{
   char *buf;
public:
     void Prin()
{
cout<<"Prin come from class B"<<endl;
}
};
试完成其定义(你可以根据需要增加必要的构造函数、析构函数 ),使得主函数main运行后能得到其后结果：

void fun(A *a)
{
delete a;
}
int main()
{
A *a = new B(10);
a->Prin();
fun(a);
B *b =  new B(20);
fun(b);
return 0;
}
Output
Prin come from class B
B::~B()called
A::~A()called
B::~B()called
A::~A()called
Hint
virtual destructor!

only need to submit class A, B and main()
*/