//#include "BT.h"
#include <iostream>
using namespace std;

struct BinaryNode
{
  string name;

  BinaryNode *left;
  BinaryNode *right;

  BinaryNode( const string & n = "", BinaryNode *lt =NULL, BinaryNode *rt =NULL )
: name(n), left( lt ), right( rt ) { };
};

//return the tree.
BinaryNode* foo(){
    BinaryNode* a=new BinaryNode("is");
    BinaryNode* b=new BinaryNode("simple");
    BinaryNode* ret=new BinaryNode("This",a,b);
    return ret;
}
int main(){
    BinaryNode* t=foo();
    cout<<t->name;
    cout<<endl;
    cout<<t->left->name;
    cout<<endl;
    cout<<t->right->name;
    cout<<endl;
    return 0;
}
