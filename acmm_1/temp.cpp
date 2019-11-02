#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110,Inf=0x7fffffff;
int n,m,k,ans,a[N][M]={};
void init()
{
    ans=Inf;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
}
void work()
{
    for(int i=1;i<=min(m,k+1);++i)
    {
        int s=0;
        for(int k=1;k<=m;++k)
        {
            int s1=0,s2=0;
            for(int j=1;j<=n;++j)
                a[j][i]==a[j][k] ? ++s1 : ++s2;
            s+=min(s1,s2);
        }
        ans=min(ans,s);
    }
}
void calc(int base)
{
    int s=base;
    for(int i=2;i<=n;++i)
    {
        int s1=0,s2=0;
        for(int j=1;j<=m;++j)
            a[1][j]==a[i][j] ? ++s1 : ++s2;
        s+=min(s1,s2);
    }
    ans=min(s,ans);
}
void tryy(int row,int t)
{
    if(row>m)
    {
        calc(t);
        return;
    }
    tryy(row+1,t);
    a[1][row]=!a[1][row];
    tryy(row+1,t+1);
    a[1][row]=!a[1][row];
}
int main()
{    
    int T=1;
    freopen("in.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d",&T);
    while(T--)
    {
        init();
        m>k ? work() : tryy(1,0);
        printf("%d\n",(ans>k ? -1 : ans));
    }
    return 0;
}