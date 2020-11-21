#ifndef BAG_H
#define BAG_H

#include <iostream>
using namespace std;

typedef int T;

class Bag
{
public:
   virtual size_t size() const = 0;             //returns the number of items in the bag.
   virtual bool empty() const = 0;              //returns true if it is empty, returns false otherwise.
   virtual bool contains(const T &x) const = 0; //returns true if x is in the bag, returns false otherwise.
   virtual void insert(const T &x) = 0;         //insert x even if x is in the bag
   virtual void erase(const T &x) = 0;          //erase x if x is in the bag.
   virtual void display() const = 0;            //print all elements to standard output in ascending order, and leave a space after every element.
   virtual T min() const = 0;                   //returns a reference to the smallest item if it is not empty.
   virtual T max() const = 0;                   //returns a reference to the biggest item if it is not empty.
   virtual void clear() = 0;                    //make an empty bag
   void print() const                           //don't override this method!
   {
      cout << "size:" << size() << endl;
      cout << "elements:";
      display();
      cout << endl;
   }
};

#endif
struct bagNode
{
   int val;
   int count;
};

class MyBag : public Bag
{
private:
   int sizes;
   int kinds;

public:
   MyBag();
   size_t size() const;             //returns the number of items in the bag.
   bool empty() const;              //returns true if it is empty, returns false otherwise.
   bool contains(const T &x) const; //returns true if x is in the bag, returns false otherwise.
   void insert(const T &x);         //insert x even if x is in the bag
   void erase(const T &x);          //erase x if x is in the bag.
   void display() const;            //print all elements to standard output in ascending order, and leave a space after every element.
   T min() const;                   //returns a reference to the smallest item if it is not empty.
   T max() const;                   //returns a reference to the biggest item if it is not empty.
   void clear();                    //make an empty bag
private:
   bagNode v[100000];
};
MyBag::MyBag()
{
   sizes = 0;
   kinds = 0;
}
size_t MyBag::size() const
{
   return sizes;
}
bool MyBag::empty() const
{
   return sizes == 0;
}
bool MyBag::contains(const T &x) const
{
   int flag = 0;
   bool ret = false;
   for (int i = 0; i < kinds; i++)
   {
      if (v[i].val == x && v[i].count > 0)
      {
         ret = true;
         break;
      }
   }
   return ret;
}
void MyBag::insert(const T &x)
{
   for (int i = 0; i < kinds; i++)
   {
      if (v[i].val == x)
      {
         v[i].count++;
         return;
      }
   }
   int pos=0;
   while(pos<kinds && v[pos].val<x)pos++;
   for(int i=kinds-1;i>=pos;i--){
      v[i+1]=v[i];
   }
   v[pos].val=x;
   v[pos].count=1;
   kinds++;
   sizes++;
}
void MyBag::erase(const T &x){
   for (int i = 0; i < kinds; i++)
   {
      if (v[i].val == x && v[i].count > 0)
      {
         v[i].count--;
         sizes--;
         return;
      }
   }
}
void MyBag::display() const{
   for(int i=0;i<kinds;i++){
      for(int j=0;j<v[i].count;j++){
         cout<<v[i].val<<" ";
      }
   }
}
T MyBag::min() const{
   int pos=0;
   while(pos<kinds && v[pos].count==0)pos++;
   return v[pos].val;
}
T MyBag::max() const{
   int pos=kinds-1;
   while(pos>0 && v[pos].count==0)pos--;
   return v[pos].val;
}
void MyBag::clear(){
   sizes=0;
   kinds=0;
}

int main(){
   MyBag t;
   t.insert(1);
   t.insert(5);
   t.insert(3);
   t.insert(2);
   t.insert(1);
   t.insert(10);
   t.insert(10);
   t.insert(7);
   t.insert(7);
   t.insert(6);
   t.print();
   t.erase(6);
   t.erase(6);
   t.erase(7);
   t.erase(7);
   t.erase(1);
   t.erase(1);
   t.erase(3);
   t.erase(2);
   t.print();
   return 0;
}