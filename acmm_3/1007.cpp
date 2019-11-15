/*
http://soj.acmm.club/show_problem.php?cid=2825&pid=1007
这题着实把👴写口区了
取模为正写成 (x+k)%k属实脑残
*/
#include <bits/stdc++.h>
using namespace std;
int dis[100005] = {0}, fa[100005] = {0}, ans = 0; //0
int find(int x)
{
	if (x != fa[x])
	{
		int i = fa[x];
		fa[x] = find(fa[x]);
		dis[x] =dis[x]+ dis[i];
	}
	return fa[x];
}
 
void make(int i,int j){
    find(i);
    find(j);
    if(fa[i]!=fa[j]){
        int jdis = dis[j];
        int idis = dis[i];
        dis[fa[j]] = -jdis+idis;
        fa[fa[j]] = fa[i];

    }
    else{
        if ((dis[i] - dis[j]) % 3 != 0)
        {
            ans++;
        }
    }
}
void eat(int i, int j){
    find(i);
    find(j);
    if(fa[i]!=fa[j]){
        int jdis = dis[j];
        int idis = dis[i];
        dis[fa[j]] = -jdis+idis+1;
        fa[fa[j]] = fa[i]; 
    }
    else{
        int ijdis = dis[j] - dis[i];
        if ((ijdis % 3  + 3) % 3 != 1 )//wdnmd 写成(ijdis + 3) % 3 debug一小时
        { 
            ans++;
        }
    }
}
int main(){
    int n, k,op,a,b;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
    for (int i = 0; i < k;i++){
        scanf("%d %d %d", &op,&a,&b);
        cout <<"i="<<i+1<< "  ans "<<ans << endl;
        if(a>n||b>n){
            ans++;
        }
        else if(op==1){
            make(a,b);
        }
        else if(op==2){
            if(a==b){
                ans++;
            }
            else{
                eat(a, b);
            }
        }
    }
    printf("%d\n", ans);
    cin>>op>>a>>b;
    return 0;
}