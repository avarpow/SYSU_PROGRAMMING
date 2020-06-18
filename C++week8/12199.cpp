#include <iostream>
using namespace std;
class Writing
{
public:
    Writing()
    {
        cout << "Writing constructor" << endl;
    }
    ~Writing() { cout << "~Writing" << endl; }
};

class Racing
{
public:
    Racing() { cout << "Racing constructor" << endl; }
    ~Racing() { cout << "~Racing" << endl; }
};
class Weekend : public Writing, public Racing
{
private:
public:
    Weekend();
    ~Weekend();
};

Weekend::Weekend()
{
    cout << "Weekend constructor" << endl;
}

Weekend::~Weekend()
{
    cout << "~Weekend" << endl;
}
class Workday : public Racing, public Writing
{
private:
public:
    Workday();
    ~Workday();
};

Workday::Workday()
{
    cout << "Workday constructor" << endl;
}

Workday::~Workday()
{
    cout << "~Workday" << endl;
}

//main.cpp
//#include "source.h"
int main()
{
    {
        Weekend end;
        Workday day;
    }
    return 0;
}
/*
multiple inheritance
Description
写作和赛车是韩少的两大最爱，但在生活的不同时期还是要有所取舍。

韩少的原则是：

周末：写作优先； 周内：赛车优先；

这些可以提现在Weekend和Workday的对象构造中，类继承关系如下：

Racing            Writing

    \                       /

  Weekend/Workday

 

其中Racing和Writing如下：

 

class Writing
{
public:
 Writing(){cout<<"Writing constructor"<<endl;}
 ~Writing(){cout<<"~Writing"<<endl;}
};

class Racing
{
public:
 Racing(){cout<<"Racing constructor"<<endl;}
 ~Racing(){cout<<"~Racing"<<endl;}
};

主函数如下：

int main()
{
 {
 Weekend end;
 Workday day;
}
}
 

如何使得输出为：

Writing constructor
Racing constructor
Weekend constructor
Racing constructor
Writing constructor
Workday constructor
~Workday
~Writing
~Racing
~Weekend
~Racing
~Writing
 

 

Input
none

Output
Writing constructor
Racing constructor
Weekend constructor
Racing constructor
Writing constructor
Workday constructor
~Workday
~Writing
~Racing
~Weekend
~Racing
~Writing
 

Sample_Input

Sample_Ouput
Writing constructor
Racing constructor
Weekend constructor
Racing constructor
Writing constructor
Workday constructor
~Workday
~Writing
~Racing
~Weekend
~Racing
~Writing
Hint
提交main函数之外的所有类
*/