#include<vector>
#include<queue>
using namespace std;
typedef int T;
struct BinaryNode{
  T elem;
  BinaryNode *left;
  BinaryNode * right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode *r=NULL):elem(d),left(l),right(r){};
};

vector<int> level_traversal(const BinaryNode* root)
{
    vector<int> ret;
    if(root == NULL){
        return ret;
    }
    queue<BinaryNode*> q;
    q.push((BinaryNode*)root);
    while(!q.empty()){
        BinaryNode* t=q.front();
        q.pop();
        ret.push_back(t->elem);
        if(t->left!=NULL)
            q.push(t->left);
        if(t->right!=NULL)
            q.push(t->right);
    }
    return ret;
}