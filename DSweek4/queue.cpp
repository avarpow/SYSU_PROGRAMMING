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
    int size
        s int top;
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
    Queue<T> t;
    t.sizes = rhs.sizes;
    t.top = rhs.top;
    t.end = rhs.end;
    for (int i = 0; i < 100; i++)
    {
        (t.a)[i] = (rhs.a)[i];
    }
    return t;
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
    if (empty())
    {
        return -1;
    }
    else
    {
        return a[top];
    }
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
    for (int i = 0; i < 200; i++)
    {
        cout << "push test " << s.push(2000 + i) << "  " << 2000 + i << "  "
             << "  size  " << s.size() << endl;
        cout << "push test " << s.push(1000 + i) << "  " << 1000 + i << "  "
             << "  size  " << s.size() << endl;
        cout << "front test " << s.front() << "  size  " << s.size() << endl;
        cout << "pop test " << s.pop() << "  size  " << s.size() << endl;
        cout << "front test " << s.front() << "  size  " << s.size() << endl;
    }
    return 0;
}