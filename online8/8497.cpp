//source.h
#ifndef SOURCE_H
#define SOURCE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MaxSize 30
#define NullPtr -1

typedef int ValueType;
typedef int Pointer;
typedef int Position;
typedef int Index;
typedef unsigned int SizeType;

typedef struct node
{
    ValueType value;
    Pointer next;
} Node;
struct manager;
struct memoryManager
{
    Node Memory[MaxSize];
    struct manager *Manager;
};
typedef struct staticLinkedList
{
    Pointer head;
    SizeType size;
} StaticLinkedList;

void iniManager(struct memoryManager *);
void releaseManager(struct memoryManager *);

void iniList(StaticLinkedList *);
bool insert(StaticLinkedList *, struct memoryManager *, ValueType, Position);
Pointer erase(StaticLinkedList *, struct memoryManager *, Position);
bool pushBack(StaticLinkedList *, struct memoryManager *, ValueType);
bool popBack(StaticLinkedList *, struct memoryManager *);
void show(StaticLinkedList *, struct memoryManager *);

#endif //SOURCE_H
//main.c
#include "source.h"
#include "frequency.h"

#define Insert 1
#define Push 2
#define Erase 3
#define Pop 4

int main()
{
    struct memoryManager myManager;
    StaticLinkedList List1, List2;
    iniManager(&myManager);
    iniList(&List1);
    iniList(&List2);

    srand((unsigned)time(NULL));

    if (true)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            int op;
            scanf("%d", &op);
            switch (op)
            {
            case Insert:
            {
                int value, position;
                scanf("%d", &value);
                scanf("%d", &position);
                if (insert(&List1, &myManager, value, position))
                    monitor(&List1, &myManager, position);
                if (insert(&List2, &myManager, 2 * value, position / 2))
                    monitor(&List2, &myManager, position / 2);
                break;
            }
            case Push:
            {
                int value;
                scanf("%d", &value);
                if (pushBack(&List1, &myManager, value))
                    monitor(&List1, &myManager, List1.size - 1);
                if (pushBack(&List2, &myManager, 2 * value))
                    monitor(&List2, &myManager, List2.size - 1);
                break;
            }
            case Erase:
            {
                int position;
                scanf("%d", &position);
                erase(&List1, &myManager, position);
                erase(&List2, &myManager, position / 2);
                break;
            }
            case Pop:
            {
                popBack(&List1, &myManager);
                popBack(&List2, &myManager);
                break;
            }
            }
        }
        show(&List1, &myManager);
        show(&List2, &myManager);
        evaluate();
    }
    releaseManager(&myManager);

    return 0;
}
//source.c
#include "source.h"
#ifndef MAN_H
#define MAN_H
typedef struct manager
{
    int restSize;
    int used[MaxSize];
} Manager;
#endif
Node *get(struct memoryManager *memoryManager, Pointer p)
{
    return &((memoryManager->Memory)[p]);
}

void iniManager(struct memoryManager *myMemoryManager)
{
    myMemoryManager->Manager = (Manager *)calloc(sizeof(Manager), 1);
    myMemoryManager->Manager->restSize = MaxSize;
    return;
}
void releaseManager(struct memoryManager *myMemoryManager)
{
    free(myMemoryManager->Manager);
    return;
}
void freed(struct memoryManager *myMemoryManager, Pointer index)
{
    myMemoryManager->Manager->restSize++;
    myMemoryManager->Manager->used[index] = 0;
}
Position allocated(struct memoryManager *myMemoryManager)
{
    static int k = 0;
    if (myMemoryManager->Manager->restSize > 0)
    {
        myMemoryManager->Manager->restSize--;
        while (myMemoryManager->Manager->used[k] == 1)
        {
            k++;
            if (k == MaxSize)
                k = 0;
        }
        myMemoryManager->Manager->used[k] = 1;
        return k;
    }
    else
        return NullPtr;
}

void iniList(StaticLinkedList *myStaticLinkedList)
{
    myStaticLinkedList->size = 0;
    myStaticLinkedList->head = NullPtr;
}
bool insert(StaticLinkedList *myStaticLinkedList,
            struct memoryManager *myMemoryManager, ValueType val,
            Position index)
{
    if (myStaticLinkedList->size == MaxSize)
    {
        return 0;
    }
    if (myStaticLinkedList->size < index)
    {
        return 0;
    }
    else
    {
        Position temp = allocated(myMemoryManager);
        if (temp == NullPtr)
        {
            return 0;
        }
        (myMemoryManager->Memory)[temp].next = NullPtr;
        (myMemoryManager->Memory)[temp].value = val;
        if (index == 0)
        {
            if (myStaticLinkedList->size == 0)
            {
                myStaticLinkedList->head = temp;
            }
            else
            {
                (myMemoryManager->Memory)[temp].next = myStaticLinkedList->head;
                myStaticLinkedList->head = temp;
            }
        }
        else
        {
            Position cur = 0;
            Pointer now = myStaticLinkedList->head;
            while (cur < index - 1)
            {
                now = (myMemoryManager->Memory)[now].next;
                cur++;
            }
            (myMemoryManager->Memory)[temp].next =
                (myMemoryManager->Memory)[now].next;
            (myMemoryManager->Memory)[now].next = temp;
        }
        myStaticLinkedList->size++;
        return 1;
    }
}
Pointer erase(StaticLinkedList *myStaticLinkedList,
              struct memoryManager *myMemoryManager, Position index)
{
    if (myStaticLinkedList->size <= index)
    {
        return 0;
    }
    else
    {
        if (index == 0)
        {
            if (myStaticLinkedList->size == 1)
            {
                freed(myMemoryManager, myStaticLinkedList->head);
                myStaticLinkedList->head = NullPtr;
                myStaticLinkedList->size--;
            }
            else
            {
                Pointer temp = (myMemoryManager->Memory)[myStaticLinkedList->head].next;
                Pointer ret = myStaticLinkedList->head;
                freed(myMemoryManager, myStaticLinkedList->head);
                myStaticLinkedList->head = temp;
                myStaticLinkedList->size--;
                return ret;
            }
        }
        else
        {
            Position cur = 0;
            Pointer now = myStaticLinkedList->head;
            while (cur < index - 1)
            {
                now = (myMemoryManager->Memory)[now].next;
                cur++;
            }
            Position del = (myMemoryManager->Memory)[now].next;
            Position next = (myMemoryManager->Memory)[del].next;
            (myMemoryManager->Memory)[now].next = next;
            freed(myMemoryManager, del);
            myStaticLinkedList->size--;
            return del;
        }
    }
}
bool pushBack(StaticLinkedList *myStaticLinkedList,
              struct memoryManager *myMemoryManager, ValueType val)
{
    return insert(myStaticLinkedList, myMemoryManager, val,
                  myStaticLinkedList->size);
}
bool popBack(StaticLinkedList *myStaticLinkedList,
             struct memoryManager *myMemoryManager)
{
    return !(erase(myStaticLinkedList, myMemoryManager,
                   myStaticLinkedList->size - 1) == -1);
}
void show(StaticLinkedList *myStaticLinkedList,
          struct memoryManager *myMemoryManager)
{
    Pointer now = myStaticLinkedList->head;
    while (now != NullPtr)
    {
        printf("%d -> ", (myMemoryManager->Memory)[now].value);
        now = (myMemoryManager->Memory)[now].next;
    }
    printf("Null\n");
    printf("The size of this list is %d\n", myStaticLinkedList->size);
}

void reverse(StaticLinkedList *myStaticLinkedList,
             struct memoryManager *myMemoryManager)
{
    if (myStaticLinkedList->size == 0 || myStaticLinkedList->size == 1)
    {
        return;
    }
    Pointer temp = myStaticLinkedList->head;
    myStaticLinkedList->head =
        reversehead(myMemoryManager, myStaticLinkedList->head);
    get(myMemoryManager, temp)->next = NullPtr;
}

Pointer reversehead(struct memoryManager *myMemoryManager, Position head)
{
    if (get(myMemoryManager, head)->next == NullPtr)
    {
        return head;
    }
    else
    {
        Pointer ret =
            reversehead(myMemoryManager, get(myMemoryManager, head)->next);
        get(myMemoryManager, get(myMemoryManager, head)->next)->next = head;
        return ret;
    }
}
int remove_if(StaticLinkedList *myStaticLinkedList,
              struct memoryManager *myMemoryManager, bool fun(const Node *))
{
    int ret = 0;
    int cur = 0;
    int now = myStaticLinkedList->head;
    // printf("ori  2 %s 3 %s 5%s\n--------------------\n", fun(&t[0]) == 0 ? "Y"
    // : "N", fun(&t[1]) == 0 ? "Y" : "N", fun(&t[2]) == 0 ? "Y" : "N");
    // show(myStaticLinkedList, myMemoryManager);
    while (now != NullPtr)
    {
        if (fun(get(myMemoryManager, now)))
        {
            now = get(myMemoryManager, now)->next;
            erase(myStaticLinkedList, myMemoryManager, cur);
            ret++;
            // show(myStaticLinkedList, myMemoryManager);
            continue;
        }
        now = get(myMemoryManager, now)->next;
        cur++;
        // show(myStaticLinkedList, myMemoryManager);
    }
    // printf("---------------------\n");
    return ret;
}
/*
Introduction
不知道你是否顺利实现了简单静态链表。在那个题目中，我们只是实现了很简单的增删操作。这次，让我们来再完善几个功能让他变得更强大吧！

Description
这个附加题有点不太一样，让我们先基于简单静态链表来看下面的这一系列操作：

pushBack(&List, &Manager, value);
popBack(&List, &Manager);
pushBack(&List, &Manager, value);
popBack(&List, &Manager);
pushBack(&List, &Manager, value);
popBack(&List, &Manager);
............
考虑一下，在这样不断pop和push的过程中，你的Manager实现是否是不断地对同一个下标值进行赋值与释放？

事实上，如果真的是在管理内存的话，不断对不变的一处内存进行读写，同时其余范围的内存一直闲置，不仅损失性能，从系统安全角度来说，也会有一定的风险。

因此，你是否能想个办法，让Manager的分配无论在什么情况下，都可以平均地利用到每处内存？

放心，这个任务远比它的描述看上去简单，某种 Manager 实现可以原封不动将简单静态链表的代码copy过来。

程序会监控每个位置被使用的情况，你需要做的就是使得整个程序运行下来，每个位置被申请的次数基本相同。

某种实现方法会以极低概率出现非酋附体的情况而导致无法通过。如果确定自己是这种实现方法的话，可以尝试多次提交（太多次过不去就还是回去查一下代码吧）
*/