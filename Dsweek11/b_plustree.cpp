#include <iostream>
#include <vector>
using namespace std;
typedef char Data;
typedef int Key;
class Store
{
public:
    Data data[10];
};
class InNode
{
public:
    vector<InNode*> childs;
    vector<Key> keys;
    InNode *parent;
    bool isleave;
    vector<Store> stores; // leaveNode storeage
};
class BPlusTree
{
private:
    int LeaveNum;
    int MiddleNum;
    InNode *root;
    bool ready;

public:
    BPlusTree(int l, int m);
    void insert(Key key, Store store);
    void search(Key key);
    void remove(Key key);
    void display();
};

BPlusTree::BPlusTree(int l, int m)
{
    ready = false;
    root = nullptr;
    if (l <= 0 || m <= 0)
    {
        cout << "[!]less than zero" << endl;
        return;
    }
    else
    {
        LeaveNum = l;
        MiddleNum = m;
        ready = true;
    }
}
void BPlusTree::insert(Key key, Store store)
{
    if (!ready)
        return;
    //empty tree
    if (root == nullptr)
    {
        root = new InNode();
        root->isleave = true;
        root->keys.push_back(key);
        root->stores.push_back(store);
        cout<<"root create "<<endl;
    }
    else{
        InNode *now=root;
        InNode *last=NULL;
        while(now->isleave == false){
            last=now;
            int pos = 0;
            //这里没写完 先看看代码
        }
    }
}
void BPlusTree::search(Key key)
{
    if (!ready)
        return;
}
void BPlusTree::remove(Key key)
{
    if (!ready)
        return;
}
void BPlusTree::display()
{
    if (!ready)
        return;
}