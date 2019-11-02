/*
http://soj.acmm.club/show_problem.php?pid=1005&cid=2823
*/
#include<bits/stdc++.h>
using namespace std;
int table[105][105] = {0};
double copytable[105][105] = {0};
int n, m, k;
void addc(int jia,int beijia,double factor){
    for (int i = 0; i < m;i++){
        copytable[beijia][i] += copytable[jia][i] * factor;
    }
}
void addr(int jia,int beijia,double factor){
    for (int i = 0; i < n;i++){
        copytable[i][beijia] += copytable[i][jia] * factor;
    }
}
int noteql0(double i){
    if(i<0.5 && i>-0.5)
        return 0;
    else
        return 1;
}
void debug(){
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            printf("%5.2f", copytable[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int calcrank(){
    int count = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(noteql0(copytable[i][j])){
                count++;
                if(count>=11)
                    return count;
                for (int g = 0; g < n;g++){
                    if(g==i)
                        continue;
                    if(noteql0(copytable[g][j])){
                        double factor = -copytable[g][j] / copytable[i][j];
                        addc(i, g, factor);
                    }
                }
                //debug();
                for (int g = 0; g < m;g++){
                    if(g==j)
                        continue;
                    else{
                        copytable[i][g] = 0;
                    }
                }
                //debug();
            }
        }
    }
    return count;
}
void solver(){
    int min = 999;
    for (int i = 0; i < n;i++){
        int ans = 0;
        for (int j = 0; j < n;j++){
            int count = 0;
            for (int k = 0; k < m;k++){
                if(table[j][k]!=table[i][k]){
                    count++;
                }
            }
            if(count>m-count)
                count = m - count;
            ans += count;
        }
        if(ans<min){
            min = ans;
        }
    }
    for (int i = 0; i < m;i++){
        int ans = 0;
        for (int j = 0; j < m;j++){
            int count = 0;
            for (int k = 0; k < n;k++){
                if(table[k][j]!=table[k][i]){
                    count++;
                }
            }
            if(count>n-count)
                count = n - count;
            ans += count;
        }
        if(ans<min){
            min = ans;
        }
    }
    if(min>k)
        printf("-1\n");
    else
        printf("%d\n", min);
}
void solve(){
    scanf("%d%d%d", &n, &m,&k);
    int rank=0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            scanf("%d", &table[i][j]);
            if(table[i][j]==0)
                table[i][j] = -1;
            copytable[i][j] = table[i][j];
        }
    }
    //rank = calcrank();
    //printf("rank:%d\n", calcrank());
    if(n>=11 && m>=11){
        rank = calcrank();
    }
    if(rank>=11){
        printf("-1\n");
    }
    else{
        solver();
    }
}
int main()
{
    int a;
    freopen("in.txt", "r", stdin);
    freopen("1.txt", "w", stdout);
    scanf("%d", &a);
    for (int i = 0; i < a;i++){
        solve();
    }
    return 0;
}