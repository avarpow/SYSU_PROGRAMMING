#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
    freopen("delete.txt","w",stdout);
    int t=3;
    for(int i=0;i<30;i++){
        cout<<t;
        t+=3;
        cout<<endl;
    }
    return 0;
}