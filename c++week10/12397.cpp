//stack.hpp
template <typename ElementType> //genericStack.h
class Stack
{
public:
    Stack();
    ~Stack();
    void push(ElementType obj);
    void pop();
    ElementType getTop() const;
    bool isEmpty() const;

private:
    struct Node // 栈结点类型
    {
        ElementType element; // 结点中存放的元素
        Node *next;          // 指向下一结点的指针
    };
    Node *top; // 栈顶
};
template <typename ElementType>
Stack<ElementType>::Stack()
{
    top = nullptr;
}
template <typename ElementType>
Stack<ElementType>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}
template <typename ElementType>
void Stack<ElementType>::pop()
{
    if (top != nullptr)
    {
        Node *nxt = top->next;
        delete top;
        top = nxt;
    }
}
template <typename ElementType>
void Stack<ElementType>::push(ElementType obj)
{
    Node *temp = new Node();
    temp->element = obj;
    temp->next = nullptr;
    if (top == nullptr)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}
template <typename ElementType>
ElementType Stack<ElementType>::getTop() const
{
    return top->element;
}
template <typename ElementType>
bool Stack<ElementType>::isEmpty() const
{
    return top == nullptr;
}

//main.cpp
#include <iostream>
using namespace std;

int main() //程序EX6_4.cpp
{
    Stack<int> stack; // 实例化一个保存int型元素的栈

    for (int i = 1; i < 9; i++) // 向栈中压入8个元素
        stack.push(i);

    while (!stack.isEmpty())
    {                                  // 栈不为空时循环
        cout << stack.getTop() << " "; // 显示栈顶元素
        stack.pop();                   // 弹出栈顶元素
    }
    return 0;
}
