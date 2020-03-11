#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

int hasRing(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL && slow->next != NULL)
    {
        fast = fast->next->next, slow = slow->next;
        if (fast != NULL && fast->val == slow->val)
        {
            return 1;
        }
    }
    return 0;
}

int entryVal(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL && slow != NULL)
    {
        fast = fast->next->next, slow = slow->next;
        if (fast->val == slow->val)
            break;
    }
    while (fast->val != head->val)
    {
        fast = fast->next, head = head->next;
    }
    return fast->val;
}

int nodeNumber(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL && slow->next != NULL)
    {
        fast = fast->next->next, slow = slow->next;
        if (fast->val == slow->val)
            break;
    }
    while (fast->val != head->val)
    {
        fast = fast->next, head = head->next;
    }
    int count = 1;
    fast = fast->next;
    while (fast->val != head->val)
    {
        fast = fast->next;
        count++;
    }
    return count;
}
void print(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("null\n");
}
int main()
{
    ListNode *a, *b, *c;
    ListNode *aa, *bb, *cc, *dd;
    a = (ListNode *)malloc(sizeof(ListNode));
    aa = (ListNode *)malloc(sizeof(ListNode));
    b = (ListNode *)malloc(sizeof(ListNode));
    bb = (ListNode *)malloc(sizeof(ListNode));
    c = (ListNode *)malloc(sizeof(ListNode));
    cc = (ListNode *)malloc(sizeof(ListNode));
    dd = (ListNode *)malloc(sizeof(ListNode));
    a->val = 0, b->val = 1, c->val = 2;
    aa->val = 3, bb->val = 4;
    a->next = b, b->next = c, c->next = aa;
    aa->next = NULL, bb->next = NULL;
    printf("hasRing%d\n", hasRing(a));
    printf("entryVa%d\n", entryVal(a));
    printf("nodeNumbe%d\n", nodeNumber(a));
    return 0;
}
/*
链表的环
描述
小统有一条链表，这根链表有时会缠起来，变成一个有环的链表
小统想知道这个链表是不是有环，假如有环，就找到环的入口结点，请你帮帮他

你需要实现三个函数：

//假如有环就返回1
//没有就返回0
int hasRing(ListNode* head);

//返回链表中环入口结点的值
//该函数只有在链表有环的情况下才会被调用
int entryVal(ListNode* head);

//返回链表中环结点的数量
//该函数只有在链表有环的情况下才会被调用
int nodeNumber(ListNode* head);
链表中结点的值都是唯一的，不会出现两个值相同的结点。

输入
0->1->2->3->1
输出
true    //hasRing
1       //entryVal
3       //nodeNumber
*/