//Inheritance.hpp
#include <iostream>
//#include "Inheritance.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
class baseA
{
private:
public:
    baseA();
    ~baseA();
};

class baseB
{
private:
public:
    baseB();
    ~baseB();
};

class derivedA : public baseA
{
private:
public:
    derivedA();
    ~derivedA();
};

class derivedB : public baseA, public baseB
{
private:
public:
    derivedB();
    ~derivedB();
};

class C : public derivedA, public derivedB
{
private:
public:
    C();
    ~C();
};

//
//  Inheritance.cpp
//  C++
//
//  Created by 李天培 on 16/3/24.
//  Copyright © 2016年 lee. All rights reserved.
//
//#include "Inheritance.hpp"
baseA::baseA()
{
    cout << "base A" << endl;
}
baseA::~baseA()
{
    cout << "~ base A" << endl;
}
baseB::baseB()
{
    cout << "base B" << endl;
}
baseB::~baseB()
{
    cout << "~ base B" << endl;
}
derivedA::derivedA()
{
    cout << "derived A" << endl;
}
derivedA::~derivedA()
{
    cout << "~ derived A" << endl;
}
derivedB::derivedB()
{
    cout << "derived B" << endl;
}
derivedB::~derivedB()
{
    cout << "~ derived B" << endl;
}
C::C()
{
    cout << "C" << endl;
}
C::~C()
{
    cout << "~ C" << endl;
}

//
//  main.cpp
//  C++
//
//  Created by 李天培 on 16/2/25.
//  Copyright © 2016年 lee. All rights reserved.
//
#include <iostream>
//#include "Inheritance.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
//***此处与原题不一样，为了在return0前析构对象，加入了大括号的作用域
int main()
{
    int token;
    cin >> token;
    {
        cout << "test token: " << token << endl;
        cout << "\ncreat base A" << endl;
        baseA ba;
        cout << "\ncreat base B" << endl;
        baseB bb;
        cout << "\ncreat derived A" << endl;
        derivedA da;
        cout << "\ncreat derived B" << endl;
        derivedB db;
        cout << "\ncreat C" << endl;
        C c;
        cout << "\ndestructor" << endl;
    }
    return 0;
}
/*
Task
Finish header file of the Inheritance class.

Hints
1. All function is finished.
2. You need write inheritance relation between 5 class so that it can print right message.

A Sample
Input
6590
Output
test token: 6590

creat base A
base A

creat base B
base B

creat derived A
base A
derived A

creat derived B
base A
base B
derived B

creat C
base A
derived A
base A
base B
derived B
C

destructor
~ C
~ derived B
~ base B
~ base A
~ derived A
~ base A
~ derived B
~ base B
~ base A
~ derived A
~ base A
~ base B
~ base A
*/