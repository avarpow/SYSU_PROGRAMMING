//quque.hpp
#include <iostream>
typedef struct Node
{
    Node *next;
    int ele;
} Node;
class Queue
{
public:
    Queue()
    {
        this->size = 0;
        this->tail = this->head = NULL;
    }
    void push(const int &ele);
    void pop();
    int front();
    int back();
    void clear();
    int Size()
    {
        return this->size;
    }
    ~Queue()
    {
        clear();
    }

private:
    int size;
    Node *head;
    Node *tail;
};
//quque.cpp
void Queue::push(const int &ele)
{
    auto node = new Node();
    node->ele = ele;
    node->next = NULL;
    if (this->size == 0)
    {
        this->head = node;
        this->tail = node;
    }
    else
    {
        node->next = this->head;
        this->head = node;
    }
    this->size++;
}
void Queue::pop()
{
    if (size != 0)
    {
        if (this->size == 1)
        {
            delete this->head;
            this->head = this->tail = NULL;
        }
        else
        {
            auto pre = this->head;
            auto now = pre->next;
            while (now != this->tail)
            {
                pre = now;
                now = now->next;
            }
            delete now;
            pre->next = NULL;
            this->tail = pre;
        }
        this->size--;
    }
}
int Queue::front()
{
    if (this->size == 0)
    {
        return -1;
    }
    else
    {
        return this->tail->ele;
    }
}

int Queue::back()
{
    if (this->size == 0)
    {
        return -1;
    }
    else
    {
        return this->head->ele;
    }
}
void Queue::clear()
{
    if (this->size != 0)
    {
        auto pre = this->head;
        auto now = pre->next;
        for (int i = 0; i < this->size - 1; i++)
        {
            delete pre;
            pre = now;
            now = now->next;
        }
        delete pre;
        this->head = this->tail = NULL;
        this->size = 0;
    }
}

//main.cpp

//#include "Queue.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    Queue q1;

    int size;
    cin >> size;
    int ele;
    for (int i = 0; i < size; i++)
    {
        cin >> ele;
        q1.push(ele);
        cout << q1.back() << " ";
    }
    cout << endl;
    cout << "The size of Queue is : " << q1.Size() << endl;
    for (int i = 0; i < size; i++)
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
    cout << "The size of Queue is : " << q1.Size() << endl;
    cout << q1.front() << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ele;
        q1.push(ele);
        cout << q1.back() << " ";
    }
    cout << endl;
    q1.clear();
    cout << q1.back() << endl;
    cout << "The size of Queue is : " << q1.Size() << endl;
    return 0;
}
/*
Intro.
Two weeks ago, you have implemented a class of stack, which is very similar to the queue. But they also have differences. For the stack, the element satisfies the principle of 'Last In First Out'. But in the queue, the principle changes into 'First In First Out'. We can regard these two data structure as containers that store elements. For a queue, the arrangement of the elements can be regarded as a sequential mode. You can look up for more detailed information of the queue via Web and then use the pointer to implement a queue class.

Some tips
void push(const int & ele); // push a element to the queue
void pop(); // pop a element from the queue(do nothing if empty)
int front();  // return the front of the queue(return -1 if empty)
int back();  // return the back of the queue(return -1 if empty)
void clear();  // clear the queue
// All the input interger will be greater than 0
Sample input
3
1 2 3
4 5 6
Sample output
1 2 3 
The size of Queue is : 3
1 2 3 
The size of Queue is : 0
-1
4 5 6 
-1
The size of Queue is : 0
*/