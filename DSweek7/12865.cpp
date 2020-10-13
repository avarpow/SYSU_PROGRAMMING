#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>


using namespace std;


typedef int T;
struct BinaryNode{
  T data;
  BinaryNode *left, *right;
  BinaryNode(T d, BinaryNode *l=NULL, BinaryNode* r=NULL):data(d), left(l), right(r) {};
};

int height(BinaryNode* root);
int height(BinaryNode* root){
    if(root==NULL){
        return -1;
    }
    else{
        return max(height(root->left)+1,height(root->right)+1);
    }
}
int main(){
    BinaryNode* a=new BinaryNode(0);
    BinaryNode* b=new BinaryNode(1);
    BinaryNode* c=new BinaryNode(2);
    BinaryNode* d=new BinaryNode(3);
    d->left=a;
    a->left=b;
    d->right=c;

    cout<<height(d)<<endl;
    cout<<height(NULL)<<endl;
    return 0;
}