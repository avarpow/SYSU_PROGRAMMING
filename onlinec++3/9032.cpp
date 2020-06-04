#ifndef STACK_HPP
#define STACK_HPP
#include <stddef.h>
class Stack
{
    struct node
    {
        int num;
        node *next;
        node()
        {
            num = 0;
            next = NULL;
        }
        node(int n, node *p = NULL)
        {
            num = n;
            next = p;
        }
    };

    node *data;

public:
    Stack();              // 构造一个空栈
    Stack(const Stack &); // 深拷贝
    ~Stack();             // 注意内存回收

    void push(int);     // 入栈
    void pop();         // 出栈
    int top() const;    // 查看栈顶元素，若栈为空，返回0
    bool empty() const; // 判断栈是否为空
    void clear();       // 清空栈
};
#endif
//#include "Stack.hpp"
Stack::Stack()
{
    data = new node();
} // 构造一个空栈
Stack::Stack(const Stack &x)
{
    data = new node();
    if (x.data->next == NULL)
        return;
    else
    {
        node *pre = data;
        node *now = x.data->next;
        while (now->next != NULL)
        {
            pre->next = new node(now->num);
            pre = pre->next;
            now = now->next;
        }
        pre->next = new node(now->num);
    }
} // 深拷贝
Stack::~Stack()
{
    clear();
    delete data;
} // 注意内存回收

void Stack::push(int x)
{
    node *now = data;
    while (now->next != NULL)
    {
        now = now->next;
    }
    now->next = new node(x);
} // 入栈
void Stack::pop()
{
    node *pre, *now;
    if (data->next == NULL)
        return;
    else
    {
        pre = data;
        now = data->next;
        while (now->next != NULL)
        {
            pre = now;
            now = now->next;
        }
        delete now;
        pre->next = NULL;
    }
} // 出栈
int Stack::top() const
{
    if (data->next == NULL)
    {
        return 0;
    }
    else
    {
        node *now = data;
        while ((now->next != NULL))
        {
            now = now->next;
        }
        return now->num;
    }
} // 查看栈顶元素，若栈为空，返回0
bool Stack::empty() const
{
    return top() == 0;
} // 判断栈是否为空
void Stack::clear()
{
    int k;
    while (top() != 0)
    {
        pop();
    }
    data->next = NULL;
} // 清空栈