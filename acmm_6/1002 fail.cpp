/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2828
*/
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
int cmp(int a,int b){
    return a > b;
}
#define N 10
int n, a[N], b[N],ac[N],bc[N],ab[N],bb[N];
vector<int> find1[2];
long long ans = 0,minans=0;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
        ac[i] = a[i];
    }
    for (int i = 0; i < n;i++){
        scanf("%d", &b[i]);
        bc[i] = b[i];
    }
    sort(a, a + n);
    sort(b, b + n,cmp);
    if(b[n-1]>=a[n-1]){
        minans = 0;
    }
    else if(a[0]>=b[0]){
        minans = 0;
    }
    else{
//----------------------------------------------------
        int fen=-1,af,bf,acount=0,bcount=0;
        for (int i = 0; i < n;i++){
            if(a[i]>=b[i]){
                af = a[i - 1];
                bf = b[i - 1];
                fen = i;
                break;
            }
        }
        for (int i = 0; i < n;i++){
            if(ac[i]<=af && acount<fen){
                ab[i] = 1;
                acount++;
            }
            else{
                ab[i] = 0;
            }
        }
        for (int i = 0; i < n;i++){
            if(bc[i]>=bf && bcount<fen){
                bb[i] = 1;
                bcount++;
            }
            else{
                bb[i] = 0;
            }
        }

        for (int i = 0; i < n;i++){
            if(ab[i]==1){
                find1[0].push_back(i);
            }
            if(bb[i]==1){
                find1[1].push_back(i);
            }
        }
        for (int i = 0; i < fen;i++){
            ans += abs(find1[0][i] - find1[1][i]);
        }
        minans = ans;
        //-----------------------------------------------------------------
        ans = 0;
        fen=-1,af,bf,acount=0,bcount=0;
        for (int i = n-1; i >= 0;i--){
            if(a[i]<=b[i]){
                af = a[i + 1];
                bf = b[i + 1];
                fen = n - 1 - i;
                break;
            }
        }
        for (int i = 0; i < n;i++){
            if(ac[i]>=af && acount<fen){
                ab[i] = 1;
                acount++;
            }
            else{
                ab[i] = 0;
            }
        }
        for (int i = 0; i < n;i++){
            if(bc[i]<=bf && bcount<fen){
                bb[i] = 1;
                bcount++;
            }
            else{
                bb[i] = 0;
            }
        }

        for (int i = 0; i < n;i++){
            if(ab[i]==1){
                find1[0].push_back(i);
            }
            if(bb[i]==1){
                find1[1].push_back(i);
            }
        }
        for (int i = 0; i < fen;i++){
            ans += abs(find1[0][i] - find1[1][i]);
        }        
        if(ans<minans){
            minans = ans;
        }
    }
    printf("%lld\n", minans);
    return 0;
}