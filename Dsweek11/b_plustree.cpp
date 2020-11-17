#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
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
    bool ready;
    InNode *root;
    void insertInNode(Key key, InNode *&root, InNode *&child);
    void removeInNode(Key key, InNode *root, InNode *child);
    InNode *&findParent(InNode *cursor, InNode *child);
    InNode **getParent(InNode *root, InNode *child);

public:
    InNode *getRoot();
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
            now->keys.insert(now->keys.begin() + pos, key);
            now->stores.insert(now->stores.begin() + pos, store);
            cout << "insert key " << key << " ok" << endl;
        }
        else
        {
            //overflow
            vector<Key> tempKeys(now->keys);
            vector<Store> tempStores(now->stores);
            int pos;
            pos = upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            tempKeys.insert(tempKeys.begin() + pos, key);
            tempStores.insert(tempStores.begin() + pos, store);

            InNode *newNode = new InNode();
            newNode->isleave = true;

            swap(now->next, newNode->next);

            now->keys.resize((LeaveNum) / 2 + 1); //check +1 or not while partitioning
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
                /*
					If cursor is root node we create new node
				*/

                InNode *newRoot = new InNode();
                newRoot->keys.push_back(newNode->keys[0]);
                newRoot->childs.push_back(now);
                newRoot->childs.push_back(newNode);
                root = newRoot;
                cout << "Created new Root!" << endl;
            }
            else
            {
                // Insert new key in the parent
                insertInNode(newNode->keys[0], last, newNode);
            }
        }
    }
}
void BPlusTree::insertInNode(Key key, InNode *&last, InNode *&newNode)
{
    if (last->keys.size() < MiddleNum - 1)
    {
        /*
			If cursor is not full find the position for the new key.
		*/

        int pos = upper_bound(last->keys.begin(), last->keys.end(), key) - last->keys.begin();
        last->keys.insert(last->keys.begin() + pos, key);
        last->childs.insert(last->childs.begin() + pos + 1, newNode);

        cout << "Inserted key in the internal node :)" << endl;
    }
    else
    {
        //splitting
        cout << "Inserted Node in internal node successful" << endl;
        cout << "Overflow in internal:( HAIYAA! splitting internal nodes" << endl;

        vector<int> tempKeys(last->keys);
        vector<InNode *> tempchilds(last->childs);

        int pos = upper_bound(last->keys.begin(), last->keys.end(), key) - last->keys.begin();
        tempKeys.insert(tempKeys.begin() + pos, key); // to create space
        tempchilds.insert(tempchilds.begin() + pos + 1, newNode);

        int halfKey; //exclude middle element while splitting
        int halfIndex = (tempKeys.size() / 2);
        halfKey = tempKeys[halfIndex]; //right biased

        //resizing and copying the keys & TreePtr to OldNode
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
        //Pushing new keys & TreePtr to NewNode
        for (int i = halfIndex + 1; i < tempKeys.size(); i++)
        {
            newNode->keys.push_back(tempKeys[i]);
        }
        for (int i = halfIndex + 1; i < tempchilds.size(); i++)
        { // because only key is excluded not the pointer
            newNode->childs.push_back(tempchilds[i]);
        }

        if (last == root)
        {
            /*
				If cursor is a root we create a new Node
			*/
            InNode *newRoot = new InNode();
            newRoot->keys.push_back(halfKey);
            newRoot->childs.push_back(last);
            //// now, newRoot->ptr2TreeOrData.ptr2Tree is the active member of the union
            newRoot->childs.push_back(newNode);
            root = newRoot;
            cout << "Created new ROOT!" << endl;
        }
        else
        {
            /*
				::Recursion::
			*/
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
        cout << "B+ Tree is Empty" << endl;
        return;
    }

    InNode *now = root;
    InNode *parent;
    int leftSibling, rightSibling;

    while (now->isleave != true)
    {
        for (int i = 0; i < now->keys.size(); i++)
        {
            parent = now;
            leftSibling = i - 1;  //left side of the parent node
            rightSibling = i + 1; // right side of the parent node

            if (key < now->keys[i])
            {
                now = now->childs[i];
                break;
            }
            if (i == now->keys.size() - 1)
            {
                leftSibling = i;
                rightSibling = i + 2; // CHECK here , might need to make it negative
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
        cout << "Key Not Found in the Tree" << endl;
        return;
    }

    //delete
    char deletefile[10] = "Deleted";
    strcpy(now->stores[num].data, deletefile);

    // Shifting the keys and dataPtr for the leaf Node
    for (int i = pos; i < now->keys.size() - 1; i++)
    {
        now->keys[i] = now->keys[i + 1];
        now->stores[i] = now->stores[i + 1];
    }
    int prev_size = now->keys.size();
    now->keys.resize(prev_size - 1);
    now->stores.resize(prev_size - 1);

    // If it is leaf as well as the root node
    if (now == root)
    {
        if (now->keys.size() == 0)
        {
            // Tree becomes empty
            root = nullptr;
            cout << "Tree is Empty Now" << endl;
        }
    }

    cout << "Deleted " << key << " From Leaf Node successfully" << endl;
    if (now->keys.size() >= (LeaveNum + 1) / 2)
    {
        //Sufficient Node available for invariant to hold
        return;
    }

    //1. Try to borrow a key from leftSibling
    if (leftSibling >= 0)
    {
        InNode *leftNode = parent->childs[leftSibling];

        //Check if LeftSibling has extra Key to transfer
        if (leftNode->keys.size() >= (LeaveNum + 1) / 2 + 1)
        {

            //Transfer the maximum key from the left Sibling
            int maxIdx = leftNode->keys.size() - 1;
            now->keys.insert(now->keys.begin(), leftNode->keys[maxIdx]);
            now->stores.insert(now->stores.begin(), leftNode->stores[maxIdx]);

            //resize the left Sibling Node After Tranfer
            leftNode->keys.resize(maxIdx);
            leftNode->stores.resize(maxIdx);

            //Update Parent
            parent->keys[leftSibling] = now->keys[0];
            printf("Transferred from left sibling of leaf node\n");
            return;
        }
    }

    //2. Try to borrow a key from rightSibling
    if (rightSibling < parent->childs.size())
    {
        InNode *rightNode = parent->childs[rightSibling];

        //Check if RightSibling has extra Key to transfer
        if (rightNode->keys.size() >= (LeaveNum + 1) / 2 + 1)
        {

            //Transfer the minimum key from the right Sibling
            int minIdx = 0;
            now->keys.push_back(rightNode->keys[minIdx]);
            now->stores
                .push_back(rightNode->stores[minIdx]);

            //resize the right Sibling Node After Tranfer
            rightNode->keys.erase(rightNode->keys.begin());
            rightNode->stores.erase(rightNode->stores.begin());

            //Update Parent
            parent->keys[rightSibling - 1] = rightNode->keys[0];
            printf("Transferred from right sibling of leaf node\n");
            return;
        }
    }
    // Merge and Delete Node
    if (leftSibling >= 0)
    { // If left sibling exists
        InNode *leftNode = parent->childs[leftSibling];
        //Transfer Key and dataPtr to leftSibling and connect ptr2next
        for (int i = 0; i < now->keys.size(); i++)
        {
            leftNode->keys.push_back(now->keys[i]);
            leftNode->stores.push_back(now->stores[i]);
        }
        leftNode->next = now->next;
        cout << "Merging two leaf Nodes" << endl;
        removeInNode(parent->keys[leftSibling], parent, now); //delete parent Node Key
                                                              //delete cursor;
    }
    else if (rightSibling <= parent->keys.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        //Transfer Key and dataPtr to rightSibling and connect ptr2next
        for (int i = 0; i < rightNode->keys.size(); i++)
        {
            now->keys.push_back(rightNode->keys[i]);
            now->stores.push_back(rightNode->stores[i]);
        }
        now->next = rightNode->next;
        cout << "Merging two leaf Nodes" << endl;
        removeInNode(parent->keys[rightSibling - 1], parent, rightNode); //delete parent Node Key
                                                                         //delete rightNode;
    }

    // Merge and Delete Node
    if (leftSibling >= 0)
    { // If left sibling exists
        InNode *leftNode = parent->childs[leftSibling];
        //Transfer Key and dataPtr to leftSibling and connect ptr2next
        for (int i = 0; i < now->keys.size(); i++)
        {
            leftNode->keys.push_back(now->keys[i]);
            leftNode->stores
                .push_back(now->stores[i]);
        }
        leftNode->next = now->next;
        cout << "Merging two leaf Nodes" << endl;
        removeInNode(parent->keys[leftSibling], parent, now); //delete parent Node Key
                                                              //delete cursor;
    }
    else if (rightSibling <= parent->keys.size())
    {
        InNode *rightNode = parent->childs[rightSibling];
        //Transfer Key and dataPtr to rightSibling and connect ptr2next
        for (int i = 0; i < rightNode->keys.size(); i++)
        {
            now->keys.push_back(rightNode->keys[i]);
            now->stores.push_back(rightNode->stores[i]);
        }
        now->next = rightNode->next;
        cout << "Merging two leaf Nodes" << endl;
        removeInNode(parent->keys[rightSibling - 1], parent, rightNode); //delete parent Node Key
                                                                         //delete rightNode;
    }
}
void BPlusTree::removeInNode(int x, InNode *cursor, InNode *child)
{
    InNode *temproot = root;

    // Check if key from root is to deleted
    if (cursor == temproot)
    {
        if (cursor->keys.size() == 1)
        {
            // If only one key is left and matches with one of the
            // child Pointers
            if (cursor->childs[1] == child)
            {
                root = cursor->childs[0];
                //delete cursor;
                cout << "Wow! New Changed Root" << endl;
                return;
            }
            else if (cursor->childs[0] == child)
            {
                root = cursor->childs[1];
                //delete cursor;
                cout << "Wow! New Changed Root" << endl;
                return;
            }
        }
    }

    // Deleting key x from the parent
    int pos;
    for (pos = 0; pos < cursor->keys.size(); pos++)
    {
        if (cursor->keys[pos] == x)
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
    cursor->childs
        .resize(cursor->childs.size() - 1);

    // If there is No underflow. Phew!!
    if (cursor->keys.size() >= (MiddleNum + 1) / 2 - 1)
    {
        cout << "Deleted " << x << " from internal node successfully\n";
        return;
    }

    cout << "UnderFlow in internal Node! What did you do :/" << endl;

    if (cursor == temproot)
    {
        return;
    }

    //InNode **p1 = findParent(temproot, cursor);
    InNode *parent = findParent(temproot, cursor);;

    int leftSibling, rightSibling;

    // Finding Left and Right Siblings as we did earlier
    for (pos = 0; pos < parent->childs.size(); pos++)
    {
        if (parent->childs[pos] == cursor)
        {
            leftSibling = pos - 1;
            rightSibling = pos + 1;
            break;
        }
    }

    // If possible transfer to leftSibling
    if (leftSibling >= 0)
    {
        InNode *leftNode = parent->childs[leftSibling];

        //Check if LeftSibling has extra Key to transfer
        if (leftNode->keys.size() >= (MiddleNum + 1) / 2)
        {

            //transfer key from left sibling through parent
            int maxIdxKey = leftNode->keys.size() - 1;
            cursor->keys.insert(cursor->keys.begin(), parent->keys[leftSibling]);
            parent->keys[leftSibling] = leftNode->keys[maxIdxKey];

            int maxIdxPtr = leftNode->childs.size() - 1;
            cursor->childs
                .insert(cursor->childs.begin(), leftNode->childs[maxIdxPtr]);

            //resize the left Sibling Node After Tranfer
            leftNode->keys.resize(maxIdxKey);
            leftNode->stores.resize(maxIdxPtr);

            return;
        }
    }

    // If possible transfer to rightSibling
    if (rightSibling < parent->childs.size())
    {
        InNode *rightNode = parent->childs[rightSibling];

        //Check if LeftSibling has extra Key to transfer
        if (rightNode->keys.size() >= (MiddleNum + 1) / 2)
        {

            //transfer key from right sibling through parent
            int maxIdxKey = rightNode->keys.size() - 1;
            cursor->keys.push_back(parent->keys[pos]);
            parent->keys[pos] = rightNode->keys[0];
            rightNode->keys.erase(rightNode->keys.begin());

            //transfer the pointer from rightSibling to cursor
            cursor->childs.push_back(rightNode->childs[0]);
            cursor->childs.erase(cursor->childs.begin());
            return;
        }
    }

    //Start to Merge Now, if None of the above cases applied
    if (leftSibling >= 0)
    {
        //leftNode + parent key + cursor
        InNode *leftNode = parent->childs[leftSibling];
        leftNode->keys.push_back(parent->keys[leftSibling]);

        for (int val : cursor->keys)
        {
            leftNode->keys.push_back(val);
        }

        for (int i = 0; i < cursor->childs.size(); i++)
        {
            leftNode->childs
                .push_back(cursor->childs[i]);
            cursor->childs[i] = NULL;
        }

        cursor->childs.resize(0);
        cursor->keys.resize(0);

        removeInNode(parent->keys[leftSibling], parent, cursor);
        cout << "Merged with left sibling" << endl;
    }
    else if (rightSibling < parent->childs.size())
    {
        //cursor + parentkey +rightNode
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
        cout << "Merged with right sibling\n";
    }
}
InNode * &BPlusTree::findParent(InNode *cursor, InNode *child)
{
    /*
		Finds parent using depth first traversal and ignores leaf nodes as they cannot be parents
		also ignores second last level because we will never find parent of a leaf node during insertion using this function
	*/
    static InNode *parent = nullptr;
    if (cursor->isleave || cursor->childs[0]->isleave){
        parent= nullptr;
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
            //Commenting To Remove vector out of bound Error:
            //new (&cursor->ptr2TreeOrData.ptr2Tree) std::vector<Node*>;
            InNode *tmpCursor = cursor->childs[i];
            findParent(tmpCursor, child);
        }
    }

    return parent;
}
void BPlusTree::display(InNode *root)
{
    if (!ready)
        return;
    /*
        Level Order Display
    */
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
            //printing keys in self
            for (int val : qfront->keys)
                cout << val << " ";
            cout << "|| "; //to seperate next adjacent nodes
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
        cout << "NO key yet" << endl;
        return;
    }
    else
    {
        InNode *now = root;
        while (now->isleave == false)
        {
            /*
				upper_bound returns an iterator pointing to the first element in the range
				[first,last) which has a value greater than �val�.(Because we are storing the
				same value in the right node;(STL is doing Binary search at back end)
			*/
            int pos = std::upper_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin();
            now = now->childs[pos]; //upper_bound takes care of all the edge cases
        }

        int pos = std::lower_bound(now->keys.begin(), now->keys.end(), key) - now->keys.begin(); //Binary search

        if (pos == now->keys.size() || now->keys[pos] != key)
        {
            cout << "Key NOT FOUND" << endl;
            return;
        }

        /*
			We can fetch the data from the disc in main memory using data-ptr
			using cursor->dataPtr[pos]
		*/
        cout << "Find stored data : ";
        cout << now->stores[pos].data;
        cout << endl;
    }
}

void insertionMethod(BPlusTree *bPTree)
{
    int key;
    Store temp;

    cout << "Please provide the rollNo: ";
    cin >> key;

    cout << "\nstore ";
    cin >> temp.data;

    bPTree->insert(key, temp);
    cout << "Insertion of roll No: " << key << " Successful" << endl;
}

void searchMethod(BPlusTree *bPTree)
{
    int key;
    cout << "What's the RollNo to Search? ";
    cin >> key;
    bPTree->search(key);
}

void printMethod(BPlusTree *bPTree)
{
    bPTree->display(bPTree->getRoot());
}

void deleteMethod(BPlusTree *bPTree)
{
    cout << "Showing you the Tree, Choose a key from here: " << endl;
    bPTree->display(bPTree->getRoot());

    int key;
    cout << "Enter a key to delete: " << endl;
    cin >> key;
    bPTree->remove(key);

    //Displaying
    bPTree->display(bPTree->getRoot());
}

int main()
{
    /*
		Please have a look at the default schema to get to know about the table
		Reference - img/database.jpg
	*/

    cout << "\n***Welcome to DATABASE SERVER**\n"
         << endl;

    bool flag = true;
    int option;

    int maxChildInt = 4, maxNodeLeaf = 3;
    // cout << "Please provide the value to limit maximum child Internal Nodes can have: ";
    // cin >> maxChildInt;
    // cout << "\nAnd Now Limit the value to limit maximum Nodes Leaf Nodes can have: ";
    // cin >> maxNodeLeaf;

    BPlusTree *bPlusTree = new BPlusTree(maxChildInt, maxNodeLeaf);

    do
    {
        cout << "\nPlease provide the queries with respective keys : " << endl;
        cout << "\tPress 1: Insertion \n\tPress 2: Search \n\tPress 3: Print Tree\n\tPress 4: Delete Key In Tree\n\tPress 5: ABORT!" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            insertionMethod(bPlusTree);
            break;
        case 2:
            searchMethod(bPlusTree);
            break;
        case 3:
            printMethod(bPlusTree);
            break;
        case 4:
            deleteMethod(bPlusTree);
            break;
        default:
            flag = false;
            break;
        }
    } while (flag);

    return 0;
}
