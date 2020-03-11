//stack.h
#include <stdio.h>
//#include "stack.h"

void PopAndPrint(Stack *);

int main()
{
    Stack mystack;
    InitiateStack(&mystack);
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        push(&mystack, tmp);
    }
    PopAndPrint(&mystack);
    return 0;
}

void PopAndPrint(Stack *stk)
{
    printf("TOP\tSIZE\n");
    while (!empty(stk))
    {
        int tmp = top(stk);
        printf("%d\t%d\n", tmp, size(stk));
        pop(stk);
    }
    puts("");
}
//main.c
#include <stdio.h>
//#include "stack.h"

void PopAndPrint(Stack *);

int main()
{
    Stack mystack;
    InitiateStack(&mystack);
    int n, tmp;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        push(&mystack, tmp);
    }
    PopAndPrint(&mystack);
    return 0;
}

void PopAndPrint(Stack *stk)
{
    printf("TOP\tSIZE\n");
    while (!empty(stk))
    {
        int tmp = top(stk);
        printf("%d\t%d\n", tmp, size(stk));
        pop(stk);
    }
    puts("");
}
//stack.c
//#include "stack.h"
#include <stdlib.h>

void InitiateStack(Stack *s)
{
    s->size = 0;
    s->top = NULL;
}
void push(Stack *s, const int a)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = a;
    temp->next = NULL;
    if (s->size == 0)
    {
        s->top = temp;
    }
    else
    {
        temp->next = s->top;
        s->top = temp;
    }
    s->size++;
}
void pop(Stack *s)
{
    if (s->size == 0)
        return;
    else
    {
        if (s->top->next == NULL)
        {
            free(s->top);
            s->top = NULL;
        }
        else
        {
            node *newtop = s->top->next;
            free(s->top);
            s->top = newtop;
        }
    }
    s->size--;
}
int empty(const Stack *s) { return (s->size) == 0; }
int top(const Stack *s) { return s->top->val; }
int size(const Stack *s) { return s->size; }
/*
Stack with List
昨天我们帮小统实现了链表和它的基本操作，今天我们尝试使用链表来实现一个简单的栈。

栈是一种线性的数据结构，其特点是后进先出(LIFO)，一个简易的栈包含如下操作：

void InitiateStack(Stack*);        // 初始化栈
void push(Stack*, const int);    // 压栈(入栈)
void pop(Stack*);                // 弹栈(出栈)
int empty(const Stack*);         // 判断栈是否为空
int top(const Stack*);            // 获取栈顶元素
int size(const Stack*);         // 返回栈中元素数量
栈和链表节点的结构在stack.h文件中给出，请实现上述函数。

扩展
有兴趣的同学可以了解一下C++中的std::stack成员函数的调用方式和传入参数与C语言中有什么不同，体会一下类和结构体的区别。
*/