#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
    freopen("a.out","w",stdout);
    for(int i=1;i<=100;i++){
        cout<<i<<"   ";
        int num=i/10+4;
        for(int j=0;j<num;j++){
            cout<<(char)(i%10+'A');
        }
        cout<<endl;
    }
    return 0;
}