/*
http://soj.acmm.club/show_problem.php?cid=2825&pid=1000
*/
#include <bits/stdc++.h>
using namespace std;
stack<int> pre,post;
int sum[1000006]={0};
int maxsum[1000006]={0};
int main(){
    int n,t,v,tt,tot=1;
    scanf("%d", &n);
    for (int i = 0; i < 1000006;i++){
        maxsum[i] = -999999999;
    }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &t);
            if (t == 1)
            {
                scanf("%d", &v);
                pre.push(v);
                sum[tot] = sum[tot - 1] + v;
                maxsum[tot] = max(maxsum[tot - 1], sum[tot]);
                tot++;
            }
            else if (t == 2)
            {
                if (pre.size() > 0)
                {
                    pre.pop();
                    tot--;
                }
            }
            else if (t == 3)
            {
                if (pre.size() > 0)
                {
                    tt = pre.top();
                    post.push(tt);
                    pre.pop();
                    tot--;
                }
            }
            else if (t == 4)
            {
                if (post.size() > 0)
                {
                    tt = post.top();
                    pre.push(tt);
                    sum[tot] = sum[tot - 1] + tt;
                    maxsum[tot] = max(maxsum[tot - 1], sum[tot]);
                    post.pop();
                    tot++;
                }
            }
            else if (t == 5)
            {
                scanf("%d", &v);
                printf("%d\n", maxsum[v]);
            }
        }
    return 0;
}