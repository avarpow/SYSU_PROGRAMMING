#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
    vector<InNode *> childs;
    vector<Key> keys;
    InNode *next;
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
    void insertInNode(Key key, InNode* &root, InNode* &child);
    void removeInNode(Key key, InNode* &root, InNode* &child);
    InNode * &getParent(InNode *root, InNode *child);

public:
    BPlusTree(int l, int m);
    void insert(Key key, Store store);
    void search(Key key);
    void remove(Key key);
    void display(InNode *root);
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
        cout << "root create " << endl;
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
            now->keys.insert(now->keys.begin()+pos,key);
            now->stores.insert(now->stores.begin()+pos,store);
            cout<<"insert key "<<key<<" ok"<<endl;
        }
        else{
            //overflow
            vector<Key> tempKeys(now->keys);
            vector<Store> tempStores(now->stores);
            int pos;
            pos = upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            tempKeys.insert(tempKeys.begin()+pos,key);
            tempStores.insert(tempStores.begin()+pos,store);

            InNode* newNode =new InNode();
            newNode->isleave = true;

            swap(now->next,newNode->next);
            
            now->keys.resize((LeaveNum) / 2 +1);//check +1 or not while partitioning
            now->stores.resize((LeaveNum) / 2 +1);
            for (int i = 0; i <= (LeaveNum) / 2; i++) {
                now->keys[i] = tempKeys[i];
                now->stores[i] = tempStores[i];
            }

            for (int i = (LeaveNum) / 2 + 1; i < tempKeys.size(); i++) {
                newNode->keys.push_back(tempKeys[i]);
                newNode->stores.push_back(tempStores[i]);
            }

            if (now == root) {
                /*
					If cursor is root node we create new node
				*/

                InNode* newRoot = new InNode();
                newRoot->keys.push_back(newNode->keys[0]);
                newRoot->childs.push_back(now);
                newRoot->childs.push_back(newNode);
                root = newRoot;
                cout << "Created new Root!" << endl;
            } else {
                // Insert new key in the parent
                insertInNode(newNode->keys[0], last, newNode);
            }
        }
    }
}
void BPlusTree::insertInNode(Key key,InNode* &last, InNode* &newNode){
        if (last->keys.size() < MiddleNum - 1) {
        /*
			If cursor is not full find the position for the new key.
		*/

        int pos = upper_bound(last->keys.begin(), last->keys.end(), key) - last->keys.begin();
        last->keys.insert(last->keys.begin()+pos,key);
        last->childs.insert(last->childs.begin()+pos+1,newNode);

        cout << "Inserted key in the internal node :)" << endl;
    } else {  
        //splitting
        cout << "Inserted Node in internal node successful" << endl;
        cout << "Overflow in internal:( HAIYAA! splitting internal nodes" << endl;

        vector<int> tempKeys(last->keys);
        vector<InNode*> tempchilds(last->childs);

        int pos=upper_bound(last->keys.begin(), last->keys.end(), key) - last->keys.begin();
        tempKeys.insert(tempKeys.begin()+pos,key);                                                                   // to create space
        tempchilds.insert(tempchilds.begin()+pos+1,newNode); 


        int halfKey;                     //exclude middle element while splitting
        int halfIndex = (tempKeys.size() / 2);
        halfKey = tempKeys[halfIndex];  //right biased

        //resizing and copying the keys & TreePtr to OldNode
        last->keys.resize(halfIndex);
        last->childs.resize(halfIndex + 1);
        for (int i = 0; i < halfIndex; i++) {
            last->keys[i] = tempKeys[i];
        }

        for (int i = 0; i < halfIndex + 1; i++) {
            last->childs[i] = tempchilds[i];
        }

        InNode* newNode = new InNode();
        //Pushing new keys & TreePtr to NewNode
        for (int i = halfIndex + 1; i < tempKeys.size(); i++) {
            newNode->keys.push_back(tempKeys[i]);
        }
        for (int i = halfIndex + 1; i < tempchilds.size(); i++) {  // because only key is excluded not the pointer
            newNode->childs.push_back(tempchilds[i]);
        }

        if (last == root) {
            /*
				If cursor is a root we create a new Node
			*/
            InNode* newRoot = new InNode();
            newRoot->keys.push_back(halfKey);
            newRoot->childs.push_back(last);
            //// now, newRoot->ptr2TreeOrData.ptr2Tree is the active member of the union
            newRoot->childs.push_back(newNode);
            root = newRoot;
            cout << "Created new ROOT!" << endl;
        } else {
            /*
				::Recursion::
			*/
            insertInNode(halfKey, getParent(root, last), newNode);
        }
    }
}
void BPlusTree::remove(Key key)
{
    if (!ready)
        return;
    if (root == NULL) {
		cout << "B+ Tree is Empty" << endl;
		return;
	}
    
    InNode* now = root;
	InNode* parent;
	int leftSibling, rightSibling;



    
}
void BPlusTree::display(InNode *root)
{
    if (!ready)
        return;
    /*
        Level Order Display
    */
    if (root == NULL) return;
    queue<InNode*> q;
    q.push(root);
    while (!q.empty()) {
        int layelsize = q.size();
        for (int i = 0; i < layelsize; i++) {
            InNode* qfront = q.front(); q.pop();
            //printing keys in self
            for (int val : qfront->keys)
                cout << val << " ";
            cout << "|| ";//to seperate next adjacent nodes
            if (qfront->isleave != true) {
                for (InNode* v : qfront->childs) {
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
    if (root == NULL) {
        cout << "NO key yet" << endl;
        return;
    } 
    else {
        InNode* now = root;
        while (now->isleave == false) {
            /*
				upper_bound returns an iterator pointing to the first element in the range
				[first,last) which has a value greater than �val�.(Because we are storing the
				same value in the right node;(STL is doing Binary search at back end)
			*/
            int pos = std::upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            now = now->childs[pos];  //upper_bound takes care of all the edge cases
        }

        int pos = std::lower_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();  //Binary search

        if (pos == now->keys.size() || now->keys[pos] != key) {
            cout << "Key NOT FOUND" << endl;
            return;
        }

        /*
			We can fetch the data from the disc in main memory using data-ptr
			using cursor->dataPtr[pos]
		*/
        cout<<"Find stored data : ";
        cout<<now->stores[pos].data;
        cout << endl;
    }
}