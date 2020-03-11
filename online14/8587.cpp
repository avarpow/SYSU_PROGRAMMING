#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode **splitList1(ListNode *head)
{
    ListNode **ret = (ListNode **)malloc(sizeof(ListNode *) * 2);
    ListNode *fast = head, *slow = head;
    if (head == NULL)
    {
        *ret = NULL;
        *(ret + 1) = NULL;
        return ret;
    }
    while (fast != NULL && fast->next != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *nex = slow->next;
    slow->next = NULL;
    *ret = head;
    *(ret + 1) = nex;
    return ret;
}

ListNode **splitList2(ListNode *head, int k)
{
    ListNode **ret = (ListNode **)malloc(sizeof(ListNode *) * 2);
    ListNode *fast = head, *slow = head;
    if (head == NULL)
    {
        *ret = NULL;
        *(ret + 1) = NULL;
        return ret;
    }
    int count = 0;
    while (fast != NULL)
    {
        fast = fast->next;
        count++;
    }
    int index = count - k - 1;
    if (index == -1)
    {
        *ret = NULL;
        *(ret + 1) = head;
        return ret;
    }
    else
    {
        while (index--)
        {
            slow = slow->next;
        }
        ListNode *nex = slow->next;
        slow->next = NULL;
        *ret = head;
        *(ret + 1) = nex;
        return ret;
    }
}
ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {
        ListNode *temp = head->next;
        ListNode *ret = reverse(head->next);
        temp->next = head;
        return ret;
    }
}
ListNode **splitList3(ListNode *head, int x)
{
    ListNode **ret = (ListNode **)malloc(sizeof(ListNode *) * 2);
    if (head == NULL)
    {
        *ret = NULL;
        *(ret + 1) = NULL;
        return ret;
    }
    ListNode *list1, *list2;
    list1 = (ListNode *)malloc(sizeof(ListNode));
    list2 = (ListNode *)malloc(sizeof(ListNode));
    list1->next = NULL;
    list2->next = NULL;
    while (head != NULL)
    {
        ListNode *sec = head->next;
        if (head->val > x)
        {
            head->next = list1->next;
            list1->next = head;
        }
        else
        {
            head->next = list2->next;
            list2->next = head;
        }
        head = sec;
    }
    if (list1->next != NULL)
    {
        ListNode *tail1 = list1->next;
        list1->next = reverse(list1->next);
        tail1->next = NULL;
    }
    if (list2->next != NULL)
    {
        ListNode *tail2 = list2->next;
        list2->next = reverse(list2->next);
        tail2->next = NULL;
    }
    *ret = list1->next;
    *(ret + 1) = list2->next;
    free(list1);
    free(list2);
    return ret;
}
void print(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("null\n");
    return;
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
    a->val = 0, b->val = 0, c->val = 0;
    aa->val = 0, bb->val = 0;
    a->next = NULL, b->next = c, c->next = aa;
    aa->next = bb, bb->next = NULL;
    // ListNode **ret = splitList1(a);
    // print(*ret);
    // print(*(ret + 1));
    ListNode **ret1 = splitList2(a, 2);
    print(*ret1);
    print(*(ret1 + 1));
    // ListNode **ret2 = splitList3(a, -1);
    // print(*ret2);
    // print(*(ret2 + 1));
    return 0;
}
/*
链表分割
描述
小统想要把他的链表变成两段，但是他不会
需要你帮帮他

本题需要实现三个函数，以三种方式分割链表：

//该函数分割方式为:平均分割
//奇数个结点前面长度大于后面
ListNode** splitList1(ListNode* head);

//例:0->1->2->3->null  变成list1:0->1->null,list2:2->3->null   
//例:0->1->2->null     变成list1:0->1->null,list2:2->null

//该函数分割方式为:从倒数第k个结点处分割
//一定会有k个结点
ListNode** splitList2(ListNode* head,int k);
//例:0->1->2->null k=1  变成list1:0->1->null,list2:2->null
//例:0->1->2->null k=3  变成list1:null,list2:0->1->2->null

//该函数分割方式为:大于x的结点分到list1,小于等于x的结点分到list2
ListNode** splitList3(ListNode* head,int x);
//例:0->1->2->null x=1  变成list1:2->null,list2:0->1->null
//例:0->1->2->null x=2  变成list1:null,list2:0->1->2->null
提醒：各结点分割后还要保持在原链表中的顺序
提醒：请使用原链表中的结点，不要新建结点

输入
0->1->2->3->null
k=2
x=2
输出
split1: 
list1:0->1->null
list2:2->3->null

split2:
list1:0->1->null
list2:2->3->null

split3:
list1:3->null
list2:0->1->2->null
提示
大家用用头插法和双指针，很简单，都讲过
*/