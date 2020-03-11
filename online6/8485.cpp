//func.h
#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *creatList(char *fileName);

void printList(ListNode *head);

void freeList(ListNode *head);
//main.c
//#include "func.h"

int main()
{
    char fileName[20];
    scanf("%s", fileName);
    ListNode *head = creatList(fileName);
    printList(head);
    freeList(head);
    return 0;
}
//func.h
//#include <func.h>

ListNode *creatList(char *fileName)
{
    ListNode *ret;
    FILE *f = fopen(fileName, "r");
    if (f == NULL)
    {
        return NULL;
    }
    int n, t;
    ListNode *temp, *last;
    fscanf(f, "%d", &n);
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(f, "%d", &t);
            temp = (ListNode *)malloc(sizeof(ListNode));
            temp->next = NULL;
            temp->val = t;
            if (i == 0)
            {
                ret = temp;
                last = temp;
            }
            else
            {
                last->next = temp;
                last = temp;
            }
        }
        return ret;
    }
    else
        return NULL;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("null");
    return;
}

void freeList(ListNode *head)
{
    ListNode *last = head;
    while (head != NULL)
    {
        head = head->next;
        free(last);
        last = head;
    }
    return;
}
/*
打印链表
描述
在同学们给小统创造好链表后，把它放到了一个文件里。
小统想拿出来，但是他不会。
他想让同学们帮帮忙，实现一些函数，打印一下链表。

有关链表的数据放在文件里，同学们要先把数据从文件读出来，创造一个链表，然后再打印。

结点的结构：

typedef struct ListNode{
    int val;
    struct ListNode* next;
}ListNode;
需要实现的函数:

//从文件中读取数据生成链表
//输入文件的路径，输出根据文件内容创建的链表
//打开失败返回NULL
//打开成功文件里有两行数据：
//第一行是链表结点的数目
//第二行是链表结点的值，值与值中间用空格分隔
ListNode* creatList(char* fileName);

//打印链表
void printList(ListNode* head);

//释放链表
void freeList(ListNode* head);
样例输入
in0.txt
//文件内容:
//6
//1 3 5 0 2 4
样例输出
1->3->5->0->2->4->null
*/
