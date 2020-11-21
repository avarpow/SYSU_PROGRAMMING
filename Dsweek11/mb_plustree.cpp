#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <time.h>
using namespace std;
typedef int Key;
typedef char Data;
class Store
{
public:
    Data data[40];
};
class InNode
{
public:
    //储存子节点的指针
    vector<InNode *> childs;
    //储存当前节点的key
    vector<Key> keys;
    //如果为叶子节点，则通过next直接到下一节点
    InNode *next;
    //判断当前节点是否是叶子节点
    bool isleave;
    //储存内存空间中的值
    vector<Store> stores; // leaveNode storeage
};
class BPlusTree
{
public:
    //返回树根
    InNode *getRoot();
    //初始化并设置L值和M值
    BPlusTree(int l, int m);
    //通过key插入值
    void insert(Key key, Store store);
    //通过key查找储存
    void search(Key key);
    //通过key移除
    void remove(Key key);
    //按照层次遍历输出元素
    void display(InNode *root);

private:
    int LeaveNum;  //B+树的L值
    int MiddleNum; //B+树的M值
    bool ready;    //B+树是否初始化完成
    InNode *root;  //B+树的根
    //添加内部节点
    void insertInNode(Key key, InNode *&root, InNode *&child);
    //添加节点情况下溢出L值的处理
    void insertOverflow(Key key, InNode *parent, InNode *child);
    //移除内部节点
    void removeInNode(Key key, InNode *root, InNode *child);
    //移除根节点
    void removeRoot(Key key, InNode *root);
    //从左邻树取得节点
    void removeStealleftSibling(InNode *parent, InNode *child, int leftSibling);
    //从右邻树取得节点
    void removeStealrightSibling(InNode *parent, InNode *child, int rightSibling);
    //从右邻树合并节点
    void removeByMergeleftSibling(InNode *parent, InNode *child, int leftSibling);
    //从左邻树合并节点
    void removeByMergerightSibling(InNode *parent, InNode *child, int rightSibling);
    //找到节点的父级节点
    InNode *&findParent(InNode *cursor, InNode *child);
};
//InNode **getParent(InNode *root, InNode *child);

int delaytime;
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
InNode *BPlusTree::getRoot()
{
    return root;
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
    }
    else
    {
        InNode *now = root;
        InNode *last = NULL;
        while (now->isleave != true)
        {
            last = now;
            int pos = 0;
            pos = upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            now = now->childs[pos];
        }

        if (now->keys.size() < LeaveNum)
        {
            int pos = 0;
            pos = upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            now->keys.insert(now->keys.begin() + pos, key);
            now->stores.insert(now->stores.begin() + pos, store);
            cout << "insert key " << key << " Success" << endl;
        }
        else
        {
            vector<Key> tempKeys(now->keys);
            vector<Store> tempStores(now->stores);
            int pos;
            pos = upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            tempKeys.insert(tempKeys.begin() + pos, key);
            tempStores.insert(tempStores.begin() + pos, store);

            InNode *newNode = new InNode();
            newNode->isleave = true;

            swap(now->next, newNode->next);

            now->keys.resize((LeaveNum) / 2 + 1); 
            now->stores.resize((LeaveNum) / 2 + 1);
            for (int i = 0; i <= (LeaveNum) / 2; i++)
            {
                now->keys[i] = tempKeys[i];
                now->stores[i] = tempStores[i];
            }

            for (int i = (LeaveNum) / 2 + 1; i < tempKeys.size(); i++)
            {
                newNode->keys.push_back(tempKeys[i]);
                newNode->stores.push_back(tempStores[i]);
            }
            if (now == root)
            {
                InNode *newRoot = new InNode();
                newRoot->keys.push_back(newNode->keys[0]);
                newRoot->childs.push_back(now);
                newRoot->childs.push_back(newNode);
                root = newRoot;
            }
            else
            {
                insertInNode(newNode->keys[0], last, newNode);
            }
        }
    }
}
void BPlusTree::insertInNode(Key key, InNode *&last, InNode *&newNode)
{
    if (last->keys.size() < MiddleNum - 1)
    {
        int pos = upper_bound(last->keys.begin(), last->keys.end(), key) - last->keys.begin();
        last->keys.insert(last->keys.begin() + pos, key);
        last->childs.insert(last->childs.begin() + pos + 1, newNode);
    }
    else
    {


        vector<int> tempKeys(last->keys);
        vector<InNode *> tempchilds(last->childs);

        int pos = upper_bound(last->keys.begin(), last->keys.end(), key) - last->keys.begin();
        tempKeys.insert(tempKeys.begin() + pos, key); 
        tempchilds.insert(tempchilds.begin() + pos + 1, newNode);

        int halfKey; 
        int halfIndex = (tempKeys.size() / 2);
        halfKey = tempKeys[halfIndex]; 

        last->keys.resize(halfIndex);
        last->childs.resize(halfIndex + 1);
        for (int i = 0; i < halfIndex; i++)
        {
            last->keys[i] = tempKeys[i];
        }

        for (int i = 0; i < halfIndex + 1; i++)
        {
            last->childs[i] = tempchilds[i];
        }

        InNode *newNode = new InNode();
        for (int i = halfIndex + 1; i < tempKeys.size(); i++)
        {
            newNode->keys.push_back(tempKeys[i]);
        }
        for (int i = halfIndex + 1; i < tempchilds.size(); i++)
        {
            newNode->childs.push_back(tempchilds[i]);
        }

        if (last == root)
        {
            InNode *newRoot = new InNode();
            newRoot->keys.push_back(halfKey);
            newRoot->childs.push_back(last);
            newRoot->childs.push_back(newNode);
            root = newRoot;
        }
        else
        {
            insertInNode(halfKey, findParent(root, last), newNode);
        }
    }
}
void BPlusTree::remove(Key key)
{
    if (!ready)
        return;
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return;
    }

    InNode *now = root;
    InNode *parent;
    int leftSibling, rightSibling;
    //查找到叶子节点
    while (now->isleave != true)
    {
        for (int i = 0; i < now->keys.size(); i++)
        {
            parent = now;
            leftSibling = i - 1;  
            rightSibling = i + 1; 
            if (key < now->keys[i])
            {
                now = now->childs[i];
                break;
            }
            if (i == now->keys.size() - 1)
            {
                leftSibling = i;
                rightSibling = i + 2; 
                now = now->childs[i + 1];
                break;
            }
        }
    }

    int pos = 0;
    bool exist = false;
    for (pos = 0; pos < now->keys.size(); pos++)
    {
        if (now->keys[pos] == key)
        {
            exist = true;
            break;
        }
    }
    vector<Key>::iterator itr = lower_bound(now->keys.begin(), now->keys.end(), key);
    int num = itr - now->keys.begin();
    if (itr == now->keys.end())
    {
        cout << "Key Not Found" << endl;
        return;
    }

    //delete
    char deletefile[10] = "Deleted";
    delaytime += 20;
    strcpy(now->stores[num].data, deletefile);

    for (int i = pos; i < now->keys.size() - 1; i++)
    {
        now->keys[i] = now->keys[i + 1];
        now->stores[i] = now->stores[i + 1];
    }
    int prev_size = now->keys.size();
    now->keys.resize(prev_size - 1);
    now->stores.resize(prev_size - 1);
    //删除根节点
    if (now == root)
    {
        if (now->keys.size() == 0)
        {
            root = nullptr;
        }
    }
    cout << "Deleted " << key << " Success" << endl;
    if (now->keys.size() >= (LeaveNum + 1) / 2)
    {
        return;
    }
    //从左边子树借
    if (leftSibling >= 0)
    {
        InNode *leftNode = parent->childs[leftSibling];
        if (leftNode->keys.size() >= (LeaveNum + 1) / 2 + 1)
        {
            int maxIdx = leftNode->keys.size() - 1;
            now->keys.insert(now->keys.begin(), leftNode->keys[maxIdx]);
            now->stores.insert(now->stores.begin(), leftNode->stores[maxIdx]);
            leftNode->keys.resize(maxIdx);
            leftNode->stores.resize(maxIdx);
            parent->keys[leftSibling] = now->keys[0];
            return;
        }
    }

    //从右边子树借
    if (rightSibling < parent->childs.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        if (rightNode->keys.size() >= (LeaveNum + 1) / 2 + 1)
        {
            int minIdx = 0;
            now->keys.push_back(rightNode->keys[minIdx]);
            now->stores.push_back(rightNode->stores[minIdx]);

            rightNode->keys.erase(rightNode->keys.begin());
            rightNode->stores.erase(rightNode->stores.begin());

            parent->keys[rightSibling - 1] = rightNode->keys[0];
            return;
        }
    }

    if (leftSibling >= 0)
    {
        InNode *leftNode = parent->childs[leftSibling];
        for (int i = 0; i < now->keys.size(); i++)
        {
            leftNode->keys.push_back(now->keys[i]);
            leftNode->stores.push_back(now->stores[i]);
        }
        leftNode->next = now->next;
        removeInNode(parent->keys[leftSibling], parent, now); 
    }
    else if (rightSibling <= parent->keys.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        for (int i = 0; i < rightNode->keys.size(); i++)
        {
            now->keys.push_back(rightNode->keys[i]);
            now->stores.push_back(rightNode->stores[i]);
        }
        now->next = rightNode->next;
        removeInNode(parent->keys[rightSibling - 1], parent, rightNode); 
    }

    if (leftSibling >= 0)
    { 
        InNode *leftNode = parent->childs[leftSibling];
        for (int i = 0; i < now->keys.size(); i++)
        {
            leftNode->keys.push_back(now->keys[i]);
            leftNode->stores
                .push_back(now->stores[i]);
        }
        leftNode->next = now->next;
        removeInNode(parent->keys[leftSibling], parent, now); 
    }
    else if (rightSibling <= parent->keys.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        for (int i = 0; i < rightNode->keys.size(); i++)
        {
            now->keys.push_back(rightNode->keys[i]);
            now->stores.push_back(rightNode->stores[i]);
        }
        now->next = rightNode->next;
        removeInNode(parent->keys[rightSibling - 1], parent, rightNode);
    }
}
void BPlusTree::removeInNode(Key key, InNode *cursor, InNode *child)
{
    InNode *temproot = root;
    if (cursor == temproot)
    {
        if (cursor->keys.size() == 1)
        {
            if (cursor->childs[1] == child)
            {
                root = cursor->childs[0];
                return;
            }
            else if (cursor->childs[0] == child)
            {
                root = cursor->childs[1];
                return;
            }
        }
    }

    // Deleting key x from the parent
    int pos;
    for (pos = 0; pos < cursor->keys.size(); pos++)
    {
        if (cursor->keys[pos] == key)
        {
            break;
        }
    }
    for (int i = pos; i < cursor->keys.size() - 1; i++)
    {
        cursor->keys[i] = cursor->keys[i + 1];
    }
    cursor->keys.resize(cursor->keys.size() - 1);

    // Now deleting the ptr2tree
    for (pos = 0; pos < cursor->childs.size(); pos++)
    {
        if (cursor->childs[pos] == child)
        {
            break;
        }
    }

    for (int i = pos; i < cursor->childs.size() - 1; i++)
    {
        cursor->childs[i] = cursor->childs[i + 1];
    }
    cursor->childs.resize(cursor->childs.size() - 1);

    if (cursor->keys.size() >= (MiddleNum + 1) / 2 - 1)
    {
        return;
    }

    if (cursor == temproot)
    {
        return;
    }

    //InNode **p1 = findParent(temproot, cursor);
    InNode *parent = findParent(temproot, cursor);
    ;

    int leftSibling, rightSibling;

    for (pos = 0; pos < parent->childs.size(); pos++)
    {
        if (parent->childs[pos] == cursor)
        {
            leftSibling = pos - 1;
            rightSibling = pos + 1;
            break;
        }
    }

    if (leftSibling >= 0)
    {
        InNode *leftNode = parent->childs[leftSibling];
        if (leftNode->keys.size() >= (MiddleNum + 1) / 2)
        {

            int maxIdxKey = leftNode->keys.size() - 1;
            cursor->keys.insert(cursor->keys.begin(), parent->keys[leftSibling]);
            parent->keys[leftSibling] = leftNode->keys[maxIdxKey];

            int maxIdxPtr = leftNode->childs.size() - 1;
            cursor->childs.insert(cursor->childs.begin(), leftNode->childs[maxIdxPtr]);

            leftNode->keys.resize(maxIdxKey);
            leftNode->stores.resize(maxIdxPtr);

            return;
        }
    }
    if (rightSibling < parent->childs.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        if (rightNode->keys.size() >= (MiddleNum + 1) / 2)
        {
            int maxIdxKey = rightNode->keys.size() - 1;
            cursor->keys.push_back(parent->keys[pos]);
            parent->keys[pos] = rightNode->keys[0];
            rightNode->keys.erase(rightNode->keys.begin());

            cursor->childs.push_back(rightNode->childs[0]);
            cursor->childs.erase(cursor->childs.begin());
            return;
        }
    }
    if (leftSibling >= 0)
    {
        InNode *leftNode = parent->childs[leftSibling];
        leftNode->keys.push_back(parent->keys[leftSibling]);
        for (int val : cursor->keys)
        {
            leftNode->keys.push_back(val);
        }
        for (int i = 0; i < cursor->childs.size(); i++)
        {
            leftNode->childs.push_back(cursor->childs[i]);
            cursor->childs[i] = NULL;
        }
        cursor->childs.resize(0);
        cursor->keys.resize(0);
        removeInNode(parent->keys[leftSibling], parent, cursor);
    }
    else if (rightSibling < parent->childs.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        cursor->keys.push_back(parent->keys[rightSibling - 1]);
        for (int val : rightNode->keys)
        {
            cursor->keys.push_back(val);
        }
        for (int i = 0; i < rightNode->childs.size(); i++)
        {
            cursor->childs
                .push_back(rightNode->childs[i]);
            rightNode->childs[i] = NULL;
        }
        rightNode->childs.resize(0);
        rightNode->keys.resize(0);
        removeInNode(parent->keys[rightSibling - 1], parent, rightNode);
    }
}
    //找父节点
InNode *&BPlusTree::findParent(InNode *cursor, InNode *child)
{
    static InNode *parent = nullptr;
    if (cursor->isleave || cursor->childs[0]->isleave)
    {
        parent = nullptr;
        return parent;
    }

    for (int i = 0; i < cursor->childs.size(); i++)
    {
        if (cursor->childs[i] == child)
        {
            parent = cursor;
        }
        else
        {
            InNode *tmpCursor = cursor->childs[i];
            findParent(tmpCursor, child);
        }
    }

    return parent;
}
    //展示b+树
void BPlusTree::display(InNode *root)
{
    if (!ready)
        return;
    if (root == NULL)
        return;
    queue<InNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int layelsize = q.size();
        for (int i = 0; i < layelsize; i++)
        {
            InNode *qfront = q.front();
            q.pop();
            for (int val : qfront->keys)
                cout << val << " ";
            cout << "|| "; 
            if (qfront->isleave != true)
            {
                for (InNode *v : qfront->childs)
                {
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
}
void BPlusTree::search(Key key)
{
    if (!ready)
        return;
    if (root == NULL)
    {
        return;
    }
    else
    {
        InNode *now = root;
        while (now->isleave == false)
        {
            int pos = std::upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            now = now->childs[pos];
        }
        int pos = std::lower_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
        if (pos == now->keys.size() || now->keys[pos] != key)
        {
            cout << "Key NOT FOUND" << endl;
            return;
        }
        delaytime += 20;
        cout << "Find stored data : ";
        cout << now->stores[pos].data;
        cout << endl;
    }
}

void insertTest(BPlusTree *bPlusTree)
{
    fstream file;
    file.open("insert.txt");
    int n;
    file >> n;
    Store t;
    Key key;
    for (int i = 0; i < n; i++)
    {
        file >> key >> t.data;
        bPlusTree->insert(key, t);
    }
    bPlusTree->display(bPlusTree->getRoot());
}
void searchTest(BPlusTree *bPlusTree)
{
    fstream file;
    file.open("search.txt");
    int n;
    file >> n;
    Key key;
    for (int i = 0; i < n; i++)
    {
        file >> key;
        cout << "key " << key << "  ";
        bPlusTree->search(key);
    }
}
void removeTest(BPlusTree *bPlusTree)
{
    fstream file;
    file.open("delete.txt");
    int n;
    file >> n;
    Key key;
    for (int i = 0; i < n; i++)
    {
        file >> key;
        bPlusTree->remove(key);
    }
    bPlusTree->display(bPlusTree->getRoot());
}

int main()
{
    clock_t start,end;
    start=clock();

    bool flag = true;
    int option;

    int LeaveNum = 4, MiddleNum = 3;

    BPlusTree *bPlusTree = new BPlusTree(LeaveNum, MiddleNum);
    delaytime = 0;
    insertTest(bPlusTree);
    searchTest(bPlusTree);
    removeTest(bPlusTree);
    end=clock();
    int excutetime=(end-start);
    cout<<endl;
    cout<<"progeamme excute time: "<<excutetime<<" ms"<<endl;
    cout << "storage delay time: " << delaytime << " ms" << endl;
    return 0;
}
