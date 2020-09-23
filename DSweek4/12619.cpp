//
template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    Queue(const Queue &rhs);
    const Queue &operator=(const Queue &rhs);
    bool empty() const;
    bool full() const;
    int size() const;
    bool push(const T &x);
    bool pop();
    const T &front() const;

private:
    int sizes;
    int top;
    int end;
    T a[100];
};
//
template <typename T>
Queue<T>::Queue()
{

    sizes = 0;
    top = 0;
    end = 0;
}
template <typename T>
Queue<T>::~Queue()
{
}
template <typename T>
Queue<T>::Queue(const Queue &rhs)
{

    sizes = rhs.sizes;
    top = rhs.top;
    end = rhs.end;
    for (int i = 0; i < 100; i++)
    {
        a[i] = (rhs.a)[i];
    }
}
template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
    sizes = rhs.sizes;
    top = rhs.top;
    end = rhs.end;
    for (int i = 0; i < 100; i++)
    {
        a[i] = (rhs.a)[i];
    }
    return *this;
}

template <typename T>
bool Queue<T>::empty() const
{
    return sizes == 0;
}
template <typename T>
bool Queue<T>::full() const
{
    return sizes == 100;
}
template <typename T>
int Queue<T>::size() const
{
    return sizes;
}
template <typename T>
bool Queue<T>::push(const T &x)
{

    if (full())
        return false;
    else
    {
        sizes++;
        a[end++] = x;
        if (end >= 100)
            end = 0;
        return true;
    }
}
template <typename T>
bool Queue<T>::pop()
{

    if (sizes == 0)
        return false;
    else
    {
        sizes--;
        top++;
        if (top >= 100)
            top = 0;
        return true;
    }
}
template <typename T>
const T &Queue<T>::front() const
{

        return a[top];

}
#include <string>
using std::string;
template <typename T>
string fun( Queue<T> &s){
    s.push(123);
    return string("fun exec");
}

#include <iostream>
using namespace std;
int main()
{
    Queue<int> s;
    cout << "empty test " << s.empty() << "  size  " << s.size() << endl;
    cout << "push test " << s.push(100) << "  size  " << s.size() << endl;
    cout << "empty test " << s.empty() << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "push test " << s.push(90) << "  size  " << s.size() << endl;
    cout << "front test " << s.front() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
    cout << "front test " << s.front() << "  size  " << s.size() << endl;
    cout << "empty test " << s.empty() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
    cout << "empty test " << s.empty() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
    cout << "empty test " << s.empty() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
    cout << "pop test " << s.pop() << "  size  " << s.size() << endl;

    //cout << "front test " << s.front() << "  size  " << s.size() << endl;
    Queue<int> s2,s3;
    //s2=s;
    s3=s2=s;
    cout << "front test dwdd   " << s.front() << "  size  " << s.size() << endl;
    cout << "front test iiii   " << s2.front() << "  size  " << s2.size() << endl;
    cout << "front test kkkkk   " << s3.front() << "  size  " << s3.size() << endl;
    
    return 0;
}
/*
队列的循环数组实现 实时评测
 2020-09-23 18:00
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
用循环数组实现队列，定义见Queue.h。

注意：

不可使用除数组和链表外的任何标准库工具如stack, queue,deque,vector和list等。
可以使用长度为100的静态数组。 3 . 请提交整个实现，包括模板类的定义和实现。
*/