//Object.h
#ifndef OBJECT_H_
#define OBJECT_H_
#include <iostream>
using namespace std;
class Object
{
public:
    Object(int i)
    {
        id = i;
        count++;
        cout << "Object " << id << " is created, we've got " << count << " object(s) now!" << endl;
    }
    ~Object()
    {
        count--;
        cout << "Object " << id << " is deleted, we've got " << count << " object(s) now!" << endl;
    }

private:
    int id;
    static int count;
};
int Object::count = 0;
#endif
//Object.cpp
void TestObjects()
{
    Object *o1 = new Object(1);
    Object *o2 = new Object(2);
    Object *o3 = new Object(3);
    delete o3;
    delete o2;
    Object *o4 = new Object(4);
    delete o4;
    delete o1;
}

//main.cpp
#include <iostream>
using namespace std;

extern void TestObjects();

int main()
{
    TestObjects();
    return 0;
}
/*
Week2 Constructor and destructor 实时评测
 2020-04-18 19:40
 1000 ms
 32 MB
 周玉飞 (18340232)
Description
Given the following Object class implemetation, write a function to produce the desired output. No changes should be made with the Object class.

class Object {
public:
    Object(int i) {
        id = i;
        count++;
        cout<<"Object "<<id<<" is created, we've got "<<count<<" object(s) now!"<<endl;
    }
    ~Object() { 
        count--;
        cout<<"Object "<<id<<" is deleted, we've got "<<count<<" object(s) now!"<<endl;
    }
private:
    int id;
    static int count;
};
int Object::count = 0;


 int main()
{
    TestObjects();
    return 0;
}
Output
Output should just be produced by the constructor and destructor of the Object class.

Sample Output
Object 1 is created, we've got 1 object(s) now!
Object 2 is created, we've got 2 object(s) now!
Object 3 is created, we've got 3 object(s) now!
Object 3 is deleted, we've got 2 object(s) now!
Object 2 is deleted, we've got 1 object(s) now!
Object 4 is created, we've got 2 object(s) now!
Object 4 is deleted, we've got 1 object(s) now!
Object 1 is deleted, we've got 0 object(s) now!
*/