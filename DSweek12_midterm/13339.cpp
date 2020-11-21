#include<vector>
using namespace std;
bool binary_search(vector<int> list, int bot, int top, int target){
    if(top>bot)
        return false;
    if(top==bot)
        return list[top]==target;
    int mid=(bot+top)/2;
    if(list[mid]==target){
        return true;
    }
    else if(list[mid]<target){
        return binary_search(list,mid+1,top,target);
    }
    else{
        return binary_search(list,bot,mid-1,target);
    }
    
}
