/*
http://soj.acmm.club/show_problem.php?pid=1000&cid=2825
*/
#include <bits/stdc++.h>
using namespace std;
struct g{
    int cost, good;
	friend bool operator <(g a,g b)
	{
		//<为从大到小排列，>为从小到大排列
		return a.cost>b.cost;
	}

};
inline void Read( int &x ) {
    x = 0; char ch = getchar();
    for( ; ch < '0' || ch > '9'; ch = getchar() );
    for( ; ch >= '0' && ch <= '9'; ch = getchar() )
        x = x * 10 + ch - '0';
    return;
}
int cmp(g a,g b){
    if(a.good!=b.good){
        return a.good > b.good;
    }
    else{
        return a.cost < b.cost;
    }
}
int n,m,a[100005],vis[100005]={0};
long long ans = 0;
g gift[100005];
priority_queue<g> gs;
int main(){
    Read(n);
    Read(m);
    for (int i = 0; i < n;i++){
        Read(a[i]);
    }
    sort(a, a + n, greater<int>());
    for (int i = 0; i < m;i++){
        scanf("%d %d", &gift[i].cost, &gift[i].good);
    }
    sort(gift, gift + m, cmp);
    if (gift[0].good < a[0])
    {
        printf("-1\n");
        return 0;
    }
    else{
        int pos = 0;
        for (int i = 0; i < n;i++){
            int nowgood = a[i];
            while(pos<m && a[i]<=gift[pos].good){
                gs.push(gift[pos]);
                pos++;
            }
            if(gs.size()>0){
                ans += (gs.top()).cost;
                gs.pop();
            }
            else{
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
