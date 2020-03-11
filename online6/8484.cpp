//list.
#include <stdio.h>
#include <stdlib.h>

//val>0
typedef struct Node
{
    int val;
    struct Node *next;
} List;

//Create linked list
List *creatList();

//Get the node by subscript, the subscript of the head node is 1
//If the node value is successfully obtained, the value is returned
//If it fails, return 0
int getValue(List *myList, int index);

//Add a node at the head
void addAtHead(List *myList, int val);

//Add a node at the end
void addAtTail(List *myList, int val);

//Add a node at subscript
//Add success returns 1.Add failure returns 0
int addAtIndex(List *myList, int index, int val);

//Delete head node
//Delete success returns 1.Delete failure returns 0
int deleteAtHead(List *myList);

//Delete subscript node
//Delete success returns 1.Delete failure returns 0
int deleteAtIndex(List *myList, int index);

//Reverse linked list
void reverseList(List *myList);

//Print linked list
//list:0  1  2  3  4  5
//form:0->1->2->3->4->5->null
void printList(List *myList);

//Free linked list
void freeList(List *myList);

//list.c
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
List *creatList()
{
    List *ret = (List *)malloc(sizeof(List));
    ret->next = NULL;
    return ret;
}

// Get the node by subscript, the subscript of the head node is 1
// If the node value is successfully obtained, the value is returned
// If it fails, return 0
int getValue(List *myList, int index)
{
    if (myList == NULL)
        return 0;
    int cur = 0;
    List *now = myList->next;
    while (cur < index)
    {
        if (now->next == NULL)
        {
            return 0;
        }
        else
        {
            now = now->next;
            cur++;
        }
    }
    return now->val;
}

// Add a node at the head
void addAtHead(List *myList, int val)
{
    if (myList == NULL)
        return;
    List *head = myList->next;
    List *temp = (List *)malloc(sizeof(List));
    temp->val = val;
    temp->next = head;
    myList->next = temp;
}

// Add a node at the end
void addAtTail(List *myList, int val)
{
    if (myList == NULL)
        return;
    else if (myList->next == NULL)
    {
        addAtHead(myList, val);
        return;
    }
    List *end = myList->next;
    while (end->next != NULL)
    {
        end = end->next;
    }
    List *temp = (List *)malloc(sizeof(List));
    temp->val = val;
    temp->next = NULL;
    end->next = temp;
}

// Add a node at subscript
// Add success returns 1.Add failure returns 0
int addAtIndex(List *myList, int index, int val)
{
    if (myList == NULL)
        return 0;
    if (index <= 0)
        return 0;
    if (index == 1)
    {
        addAtHead(myList, val);
        return 1;
    }
    else
    {
        int cur = 1;
        if (myList->next == NULL)
            return 0;
        List *now = myList->next;
        while (cur < index - 1)
        {
            if (now->next == NULL)
            {
                return 0;
            }
            else
            {
                now = now->next;
                cur++;
            }
        }
        List *temp = (List *)malloc(sizeof(List));
        temp->val = val;
        temp->next = now->next;
        now->next = temp;
        return 1;
    }
}

// Delete head node
// Delete success returns 1.Delete failure returns 0
int deleteAtHead(List *myList)
{
    if (myList == NULL)
        return 0;
    if (myList->next == NULL)
    {
        return 0;
    }
    if (myList->next->next == NULL)
    {
        free(myList->next);
        myList->next = NULL;
        return 1;
    }
    else
    {
        List *temp = myList->next;
        myList->next = myList->next->next;
        free(temp);
        return 1;
    }
}

// Delete subscript node
// Delete success returns 1.Delete failure returns 0
int deleteAtIndex(List *myList, int index)
{
    if (myList == NULL)
        return 0;
    if (index <= 0)
        return 0;

    if (index == 1)
    {
        return deleteAtHead(myList);
    }
    else
    {
        int cur = 1;
        if (myList->next == NULL)
            return 0;

        List *now = myList->next;
        while (cur < index - 1)
        {
            if (now->next == NULL)
            {
                return 0;
            }
            else
            {
                now = now->next;
                cur++;
            }
        }
        List *second = now->next;
        if (second != NULL)
        {
            now->next = second->next;
            free(second);
            return 1;
        }
        else
            return 0;
    }
}
List *reversemyList(List *myList)
{
    if (myList->next == NULL)
    {
        return myList;
    }
    else
    {
        List *ret = reversemyList(myList->next);
        myList->next->next = myList;
        return ret;
    }
}
// Reverse linked list
void reverseList(List *myList)
{
    if (myList == NULL || myList->next == NULL)
        return;
    List *temp = myList->next;
    myList->next = reversemyList(myList->next);
    temp->next = NULL;
}

// Print linked list
// list:0  1  2  3  4  5
// form:0->1->2->3->4->5->null
void printList(List *myList)
{
    if (myList != NULL)
    {
        List *cur = myList->next;
        while (cur != NULL)
        {
            printf("%d->", cur->val);
            cur = cur->next;
        }
        printf("null\n");
    }
    else
    {
        printf("null\n");
    }
}

// Free linked list
void freeList(List *myList)
{
    List *cur = myList;
    while (cur != NULL)
    {
        List *last = cur;
        cur = cur->next;
        free(last);
    }
}
/*
设计链表
描述
小统是学校的一名学生，现在他没有链表，但是他想要一个链表。
因为小统不懂什么是链表，所以需要懂链表的你帮他设计一个。

小统昨晚梦到链表和它的的结点应该是这样的：

//val>0
typedef struct Node{
    int val;
    struct Node* next;
}List;
而且链表应该具有一些功能，所以你要帮小统实现一些函数：

//创建链表
List* creatList();

//通过下标获得结点，头结点的下标是1
//如果成功获取结点值，返回该值
//如果失败，返回0
int getValue(List* myList,int index);

//在头部添加结点
void addAtHead(List* myList,int val);

//在尾部添加结点
void addAtTail(List* myList,int val);

//在下标添加结点
//添加成功返回1，添加失败返回0
int addAtIndex(List* myList,int index,int val);

//删除头部结点
//删除成功返回1，删除失败返回0
int deleteAtHead(List* myList);

//删除下标结点
//删除成功返回1，删除失败返回0
int deleteAtIndex(List* myList,int index);

//反转链表
//请用常数的额外辅助空间
void reverseList(List* myList);

//打印链表
//链表:0  1  2  3  4  5
//格式:0->1->2->3->4->5->null
void printList(List* myList);

//释放链表空间
void freeList(List* myList);
你只需实现链表功能就可以，小统会帮你调用的。不用谢(main函数被隐藏)

main函数中可能这样调用list.h中的函数：

List* myList=creatList();
addAtHead(myList,val);
deleteAtHeada(myList);
reverseList(myList);
printList(myList);
freeList(myList);
样例输入
addHead
1
deleteHead
deleteHead
printList
freeList
样例输出
Added successfully.
Deleted successfully.
Deleted failed.
null
Freed successfully.
*/
