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
//#include "source.h"

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

        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            int position;
            scanf("%d", &position);
            erase(&List1, &myManager, position);
            erase(&List2, &myManager, position / 2);
        }
        show(&List1, &myManager);
        show(&List2, &myManager);

        int t;
        scanf("%d", &t);
        for (int i = 0; i < t; ++i)
        {
            int value, position;
            scanf("%d", &value);
            scanf("%d", &position);
            insert(&List1, &myManager, value, position);
            insert(&List2, &myManager, 2 * value, position / 2);
        }
        if (t)
        {
            show(&List1, &myManager);
            show(&List2, &myManager);
        }

        pushBack(&List1, &myManager, n);
        pushBack(&List2, &myManager, m);
        show(&List1, &myManager);
        show(&List2, &myManager);

        popBack(&List1, &myManager);
        popBack(&List2, &myManager);
        show(&List1, &myManager);
        show(&List2, &myManager);
    }
    releaseManager(&myManager);

    return 0;
}
//source.c
//#include "source.h"
typedef struct manager
{
    int restSize;
    int used[MaxSize];
} Manager;
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
/*
Introduction
你前两天一定非常享受和链表一起度过的时光吧！那么今天，我们来做点特别的。我们将实现一个叫做 Static Linked List 的不太一样的链表。

经过前两天的代码训练，你一定已经清楚地知道，链表本质上是动态的（在运行时不断申请内存）。那么你一定会想，链表能不能被静态实现呢？答案是肯定的！

静态链表（Static Linked List）在条件合适（即能确定所需空间上限）的情况下，能避免很多动态内存申请带来的麻烦，并且还有不差的性能，甚至在一些特殊情况下，具有比链表更好的查找效率。

Description
在一般的链表中，节点 Node 结构体有两个成员变量，分别是int value和int* next。而静态链表则会在一开始会建立一个确定大小的数组，并且用数组下标值作为 next 值，遍历时通过访问数组对应下标来找到后继节点——也就是利用数组下标来模拟指针。

整个任务可以被分成两个部分。

类型定义请看源文件

第一部分：链表
这部分工作旨在对链表功能进行实现。

你需要实现以下函数：

注意，几乎每个函数都需要牵扯到第二部分的“内存”管理部分。

void iniList(StaticLinkedList*)
初始化工作，给一些重要的成员变量赋初始值
bool insert(StaticLinkedList*,struct memoryManager*,ValueType,Position)
在对应位置插入元素，返回是否成功插入：
1 -> 3 -> NULL
insert(&List, &Manager, 0, 0);
0 -> 1 -> 3 -> Null
Pointer erase(StaticLinkedList*,struct memoryManager*,Position)
在对应位置删除元素，返回被删除节点所指向的位置
0 -> 1 -> 3 -> Null
erase(&List, &Manager, 0);
1 -> 3 -> Null
bool pushBack(StaticLinkedList*,struct memoryManager*,ValueType)
在尾端插入元素
bool popBack(StaticLinkedList*,struct memoryManager*)
删除尾端元素
void show(StaticLinkedList*,struct memoryManager*)
打印链表，需要同时包含元素和尺寸信息：每个元素之间用“ -> ”链接，并且最后指向“Null”并换行打印尺寸信息，最后也有换行。
show(&List, &Manager);
1 -> 2 -> Null
The size of this list is 2
第二部分：“内存”管理
这部分工作是旨在对提前申请好的节点数组进行管理。

你首先需要实现 struct manager 的定义

接下来，你可能会需要实现以下函数：

注意，除了个别函数外，大部分函数可以按照自己的想法进行规划，参数列表可以不同，返回值可以不同，也可以不实现，只要保证最终功能正确就好了。

void iniManager(struct memoryManager*)
初始化工作，给一些重要的成员变量赋初始值，这个函数必须实现
void releaseManager(struct memoryManager*);
释放工作，程序结束前的收尾工作，这个函数可以空实现
void freed(struct memoryManager*, Pointer)
将空闲下来的位置记录下来
bool allocated(struct memoryManager*)
外部申请了一个位置，返回是否申请成功
提示
如果你现在还是一头雾水，那么我们来稍微举个例子。既然是静态的，那么必然要用数组。然而想基于数组实现链表，那么就必须有一个什么玩意，记下来数组中哪些元素是没被使用的，那些是被使用的。这就是我们的 memoryManager 。在一开始，还没有链表的时候，数组内所有位置都是空闲的。当开始insert或者 pushBack 的时候，就需要从 memoryManager 那里申请空闲位置并获得其下标，然后将 value 存进去，同时 memoryManager 也需要“记住”这个位置已经被申请走了。

可能到这里你还是会有点迷茫，到底应该用“什么玩意”来实现这个 memoryManager 呢？事实上，这个问题没有确定的答案，你可以有很多方法实现。最暴力的想法可能就是用两个和申请空间长度相同的下标数组，一个存空闲的下标，一个存不空闲的下标。但是这样不仅代码写起来不优雅，还会同时带来时间和空间的浪费。

不过，这部分还是留给聪明的你来思考，设计出自己的实现方法！

Hint
不要觉得简单就直接上手开始实现，提前规划好整个代码的结构。由于C语言特性，的确可以一个函数同时对链表进行操作同时维护 Memory ，但这会导致一旦出错难以排查；不仅如此，如果后期想改变某个实现，会非常非常难以改变（高耦合）。具体概念详见“耦合”、“接口”

事实上，这个工作可能并不会很轻松，你需要专注的思考，将其与指针进行类比

善用调试器（debugger）

手边最好能准备纸笔，随手画一些图示，有助于理清自己的思路

Something More
先谈一个你们可能会很熟悉也很困惑的问题，这个问题的来源是你们的程序设计理论题：数组越界和访问野指针的错误类型，到底是段错误（segmentation fault）还是未定义行为（undefined behavior）呢？答案是：都有可能。

两者的区别仅在于严重程度的不同：段错误是非常严重的操作系统级别的报错，而未定义行为只不过是在灰色地带行走罢了。

用我们今天实现的静态链表来帮助思考就会很好理解：假设MaxSize是30；正常运行情况下，你是不应该通过；当你访问 memoryManager 中被认为是空闲的位置（意味着这个节点内的数据是无意义的垃圾值）（在收回节点时候，）的时候，这种行为就类似于前文所说的未定义行为；然而，当你访问下标为31的数组元素的时候，这就是前文所说的段错误了。

事实上，每个程序开始的时候，都会和计算机要“一块”内存，这就相当于我们的Memory[MaxSize]，当你在运行过程中需要的内存总量超过一开始要到的内存时，便需要进一步进行内存的分配。但无论如何，出于效率的考虑，计算机不会像挤牙膏一样给你一点点挤内存（甚至是从不同的牙膏棒里各挤一点点）。无论是程序开始还是后续进一步申请，计算机是很大方的给你一整条牙膏（也有可能给一倍的牙膏数），任你发挥。因此，你在申请来的内存上做任何事情，计算机都不会认为你在胡闹。而未定义行为就发生在这个时候。可一旦访问了不属于你申请来的地方，计算机就会报错。因为这个地方的数据不仅对你来说没有意义，并且这个地方的数据有可能是其他程序的数据！

上述都只是很笼统地一些描述，今天的工作也只是捎带的让你体验一下内存的管理（简化了很多很多很多……）。

如果想对这个问题研究更深，比如两者比较明确的界限在哪里？可能需要你到高年级之后，了解扇区，系统位数之类的定义与意义后，就会更为清楚了。

关于这个问题，有一个非常棒的实验可以让你更直观的理解：传送门

通过这次的作业，你可能会很深刻的认识到，其实指针在某种意义上，就是一种“下标”，只不过这个“下标”对应的“数组”开的特别大，并且只有计算机能看到“它的全貌”。每个程序就像一个StaticLinkedList，只有着一部分的内存，不同的程序就像不同的StaticLinkedList，相互不能交叉，不能影响。

作为程序设计课，结构体，或者说数据结构，是非常重要的。而链表可以说是所有后面数据结构的基础，对这部分还有兴趣的同学，可以考虑自行尝试双向链表甚至双向循环链表的实现（功能只需要简单的插入删除查找）。
*/