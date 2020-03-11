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

void sort(StaticLinkedList *, struct memoryManager *);

#endif //SOURCE_H
//main.c
#include "source.h"
#include "test.h"

bool fun_0(const Node *node)
{
    return node->value % 2 == 0;
}
bool fun_1(const Node *node)
{
    return node->value % 3 == 0;
}
bool fun_2(const Node *node)
{
    return node->value % 5 == 0;
}

int main()
{
    struct memoryManager myManager;
    StaticLinkedList List1, List2;
    iniManager(&myManager);
    iniList(&List1);
    iniList(&List2);

    if (true)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            int value, position;
            scanf("%d", &value);
            scanf("%d", &position);
            insert(&List1, &myManager, value, position);
            insert(&List2, &myManager, 2 * value, position / 2);
        }
        show(&List1, &myManager);
        show(&List2, &myManager);

        Pointer p = List1.head;

        sort(&List1, &myManager);
        sort(&List2, &myManager);
        show(&List1, &myManager);
        show(&List2, &myManager);

        testSwap(p, &myManager);
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
    if (myMemoryManager->Manager->restSize > 0)
    {
        myMemoryManager->Manager->restSize--;
        for (int i = 0; i < MaxSize; i++)
        {
            if (myMemoryManager->Manager->used[i] == 0)
            {
                myMemoryManager->Manager->used[i] = 1;
                return i;
            }
        }
    }
    else
        return NullPtr;
}

void iniList(StaticLinkedList *myStaticLinkedList)
{
    myStaticLinkedList->size = 0;
    myStaticLinkedList->head = NullPtr;
}
bool insert(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager, ValueType val, Position index)
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
                (myMemoryManager->Memory)[temp].next =
                    myStaticLinkedList->head;
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
Pointer erase(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager, Position index)
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
bool pushBack(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager, ValueType val)
{
    return insert(myStaticLinkedList, myMemoryManager, val, myStaticLinkedList->size);
}
bool popBack(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager)
{
    return !(erase(myStaticLinkedList, myMemoryManager, myStaticLinkedList->size - 1) == -1);
}
void show(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager)
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

void reverse(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager)
{
    if (myStaticLinkedList->size == 0 || myStaticLinkedList->size == 1)
    {
        return;
    }
    Pointer temp = myStaticLinkedList->head;
    myStaticLinkedList->head = reversehead(myMemoryManager, myStaticLinkedList->head);
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
        Pointer ret = reversehead(myMemoryManager, get(myMemoryManager, head)->next);
        get(myMemoryManager, get(myMemoryManager, head)->next)->next = head;
        return ret;
    }
}
int remove_if(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager, bool fun(const Node *))
{
    int ret = 0;
    int cur = 0;
    int now = myStaticLinkedList->head;
    //printf("ori  2 %s 3 %s 5%s\n--------------------\n", fun(&t[0]) == 0 ? "Y" : "N", fun(&t[1]) == 0 ? "Y" : "N", fun(&t[2]) == 0 ? "Y" : "N");
    //show(myStaticLinkedList, myMemoryManager);
    while (now != NullPtr)
    {
        if (fun(get(myMemoryManager, now)))
        {
            now = get(myMemoryManager, now)->next;
            erase(myStaticLinkedList, myMemoryManager, cur);
            ret++;
            //show(myStaticLinkedList, myMemoryManager);
            continue;
        }
        now = get(myMemoryManager, now)->next;
        cur++;
        //show(myStaticLinkedList, myMemoryManager);
    }
    //printf("---------------------\n");
    return ret;
}
void sort(StaticLinkedList *myStaticLinkedList, struct memoryManager *myMemoryManager)
{
    //printf("\n---------------------------\n");
    for (int i = myStaticLinkedList->size - 1; i > 0; i--)
    {
        //show(myStaticLinkedList, myMemoryManager);
        Position now = myStaticLinkedList->head;
        Position cur = 0;
        for (int j = 0; j < i; j++)
        {
            //printf("\n**************************\n");

            if (get(myMemoryManager, now)->value > get(myMemoryManager, get(myMemoryManager, now)->next)->value)
            {
                ValueType val = get(myMemoryManager, now)->value;
                now = get(myMemoryManager, now)->next;
                erase(myStaticLinkedList, myMemoryManager, cur);
                insert(myStaticLinkedList, myMemoryManager, val, cur + 1);
            }
            now = get(myMemoryManager, now)->next;
            cur++;
            //show(myStaticLinkedList, myMemoryManager);

            //printf("\n**********************\n");
        }
    }
    //printf("\n---------------------------\n");
}
/*
Introduction
不知道你是否顺利实现了简单静态链表。在那个题目中，我们只是实现了很简单的增删操作。这次，让我们来再完善几个功能让他变得更强大吧！

Description
你需要在简单静态链表已经完成的基础上再实现以下函数：

void sort(StaticLinkedList*, struct memoryManager*);
你需要对链表进行排序，默认升序排列

排序时若需要进行交换操作则应该交换节点，而不应该直接交换节点值，因为这会在某些时候带来难以发现的错误。

Hint
testSwap 函数是用来检查你是否是只改变了节点值，具体实现不用在意
*/