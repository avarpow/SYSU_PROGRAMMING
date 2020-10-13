#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Set;
Set setIntersection(const Set A, const Set B){
    Set ret;
    for(auto &a:A){
        int flag=0;
        for(auto &b:B){
            if(a==b){
                flag=1;
                break;
            }
        }
        if(flag==1){
            ret.push_back(a);
        }
    }
    return ret;
}
Set mysetIntersection(const Set A, const Set B){
    Set ret;
    for(auto &a:A){
        int flag=0;
        for(auto &b:B){
            if(a==b){
                flag=1;
                break;
            }
        }
        if(flag==1){
            ret.push_back(a);
        }
    }
    return ret;
}
//#include "setIntersection.h"
int mytest(){
	Set a,b;
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	cin>>t;
	for(int i=0;i<t;i++){
		int temp;
		cin>>temp;
		b.push_back(temp);
	}
	Set c=setIntersection(a,b);
    Set d=mysetIntersection(a,b);
    for(auto &i:c){
        cout<<" "<<i;
    }
    cout<<endl;
    if(c.size()!=d.size()){
        return 0;
    }
    for(int i=0;i<c.size();i++){
        if(c[i]!=d[i]){
            return 0;
        }
    }
    return 1;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(mytest()==1){
			cout<<"OK"<<endl;
		}
		else{
			cout<<"OBS"<<endl;
		}
	}	
	return 0;
} 
/*
3

2
1 2
2
1 3

3
3 4 5
2
4 5

0
0





*/