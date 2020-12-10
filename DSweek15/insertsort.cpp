#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> a,int left,int right){
    //确定left的位置,排序后left位置为当前区域的最小元素
    if(left<0 ||  right >=a.size() || left>=right)return;
    else{
        int ind=left;
        int val=a[left];
        for(int i=left;i<=right;i++){
            if(a[i]<val){
                ind=i;
                val=a[i];
            }
        }
        int temp=a[ind];
        a[ind]=a[left];
        a[left]=temp;
    }
}
int main(){

    return 0;
}