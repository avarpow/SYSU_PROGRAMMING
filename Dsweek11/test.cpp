#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> a{1,3,5,7,9,11,13,15};
    vector<int>::iterator it=upper_bound(a.begin(),a.end(),1);
    a.reserve(a.size()*2);
    for(auto &i:a){
        cout<<i<<" ";
    }
    return 0;
    
}