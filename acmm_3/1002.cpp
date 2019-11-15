/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2825
*/
#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
int main(){
    long long n,ans=0;
    scanf("%lld", &n);
    for (int i = 0; i < n;i++){
        long long t;
        scanf("%lld", &t);
        q.push(-t);
    }
    while(q.size()>=2){
        long long t1 = q.top();
        q.pop();
        long long t2 = q.top();
        q.pop();
        ans = ans + t1 + t2;
        q.push(t1 + t2);
    }
    printf("%lld", -ans);
    return 0;
}