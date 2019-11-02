/*
http://soj.acmm.club/show_problem.php?pid=1004&cid=2824
*/
#include<bits/stdc++.h>
using namespace std;
int n,t;
priority_queue<int, vector<int>, greater<int> > s;
priority_queue <int> b;
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n;i++){
        scanf("%d", &t);
        s.push(t);
        b.push(t);
    }
    for (int i = 0; i < n;i++){
        if(i%2){
            printf("%d ", s.top());
            s.pop();
        }
        else{
            printf("%d ", b.top());
            b.pop();
        }
    }
    return 0;
}