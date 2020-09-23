#include <iostream>
using namespace std;

typedef string T;
struct Node
{
    T data;
    Node *next;

    Node() { next = NULL; }
    Node(T item, Node *add_on = NULL)
    {
        data = item;
        next = add_on;
    }
};

Node *foo()
{
    Node *head;
    head = new Node("fun");
    head = new Node("is", head);
    head = new Node("programming", head);
    return head;
}
int conuntNodes(Node *head)
{
    if (head == NULL)
        return 0;
    else
    {
        int ret = 1;
        while (head->next != NULL)
        {
            ret++;
            head = head->next;
        }
        return ret;
    }
}

void insertAtEnd(T data, Node *&head)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = temp;
    }
    return;
}
void clear(Node *&head)
{
    Node *thead = head;
    int c = 0;
    Node *t = thead;
    if (thead == NULL)
    {
        return;
    }
    else
    {
        while (t != NULL)
        {
            thead = thead->next;
            delete t;
            cout << c++ << " ";
            t = thead;
        }
    }
    cout << "clear all" << endl;
    head = NULL;
    return;
}
void printList(Node *head)
{
    cout << endl;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}
int main()
{
    Node *t;
    t = foo();
    printList(t);
    cout << conuntNodes(t) << endl;
    clear(t);
    insertAtEnd("insert", t);
    printList(t);
    cout << conuntNodes(t) << endl;
    clear(t);
    return 0;
}