#include <iostream>
using std::cout;
using std::endl;
class Car
{
private:
public:
    Car();
    ~Car();
};

Car::Car()
{
    cout << "Construct a car" << endl;
}

Car::~Car()
{
}

class Wheel
{
private:
public:
    Wheel();
    ~Wheel();
};

Wheel::Wheel()
{
    cout << "Construct a wheel" << endl;
}

Wheel::~Wheel()
{
}

class RedCar : public Car
{
private:
    Wheel *Wheels[4];

public:
    RedCar();
    ~RedCar();
};

RedCar::RedCar()
{
    for (int i = 0; i < 4; i++)
    {
        Wheels[i] = new Wheel();
    }
    cout << "Construct a red car" << endl;
}

RedCar::~RedCar()
{
}
#include <iostream>

using namespace std;

int main()
{
    cout << "--- build Car ---" << endl;
    Car Car;
    cout << endl;

    cout << "--- build wheel ---" << endl;
    Wheel wheel;
    cout << endl;

    cout << "--- build red Car ---" << endl;
    RedCar redcar;

    return 0;
}
/*
描述
红色小汽车是一种汽车,它有四个轮子.

有三个类 Car, Wheel, RedCar. RedCar继承Car,并且有四个Wheel成员对象

三个类都有自己的默认构造函数,并且调用默认构造函数时,会输出一句话Construct a XXX

根据要求完成类的定义

输入

输出
--- build car ---
Construct a car

--- build wheel ---
Construct a wheel

--- build red car ---
Construct a car
Construct a wheel
Construct a wheel
Construct a wheel
Construct a wheel
Construct a red car
*/