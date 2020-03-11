#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;
ListNode *reverse(ListNode *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    ListNode *sec = head->next;
    ListNode *temp = reverse(head->next);
    sec->next = head;
    return temp;
}
ListNode *listAdd(ListNode *list1, ListNode *list2)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->val = list1->val + list2->val;
        if (head->next == NULL)
        {
            head->next = temp;
        }
        else
        {
            temp->next = head->next;
            head->next = temp;
        }
        list1 = list1->next, list2 = list2->next;
    }
    while (list1 == NULL && list2 != NULL)
    {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->val = list2->val;
        if (head->next == NULL)
        {
            head->next = temp;
        }
        else
        {
            temp->next = head->next;
            head->next = temp;
        }
        list2 = list2->next;
    }
    while (list1 != NULL && list2 == NULL)
    {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->val = list1->val;
        if (head->next == NULL)
        {
            head->next = temp;
        }
        else
        {
            temp->next = head->next;
            head->next = temp;
        }
        list1 = list1->next;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    ListNode *t = head->next;
    head->next = reverse(head->next);
    t->next = NULL;
    ListNode *head2 = head->next;
    while (head2->next != NULL)
    {
        ListNode *sec = head2->next;
        int j = head2->val / 10;
        sec->val += j;
        head2->val %= 10;
        head2 = head2->next;
    }
    if (head2->val >= 10)
    {
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->next = NULL;
        temp->val = head2->val / 10;
        head2->val %= 10;
        head2->next = temp;
    }
    ListNode *ret = head->next;
    free(head);
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
    a->val = 1, b->val = 1, c->val = 1;
    aa->val = 9, bb->val = 9;
    a->next = b, b->next = c, c->next = NULL;
    aa->next = bb, bb->next = NULL;
    print(a);
    print(aa);
    ListNode *ans = listAdd(a, aa);
    print(ans);
    return 0;
}
/*
描述
小统在路上遇到了一个数学老师，数学老师出了一道加法题
小统看了一下竟然不会，幸好他有链表
他准备用链表算出来这个加法题
难道用链表他就会这个加法题吗？也不是，但是他知道用链表来算同学们会帮他

请大家用链表做加法：
例：

100用链表表示: 0->0->1
99用链表表示: 9->9
156用链表表示: 6->5->1
null(空链表)代表0
实现函数：

ListNode* listAdd(ListNode* list1,ListNode* list2); 
要求，函数返回的链表里每一个结点都是新建的，不是list1和list2中的结点。

输入
1->null
2->1>null
输出
3->1->null
*/