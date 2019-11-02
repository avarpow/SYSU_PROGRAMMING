/*
http://soj.acmm.club/show_problem.php?pid=1002&cid=2824
*/
#include<stdio.h>
int a[200000];
int t[200000];
long long ans = 0;
void merge(int l,int r){
    int pos1 = l, pos2 = (l+r) / 2 + 1,count=l;
    long long cc = 0;
    while(pos1<=(l+r)/2 && pos2<=r){
        if(a[pos1]<=a[pos2]){
            t[count++] = a[pos1];
            pos1++;
        }
        else{
            t[count++] = a[pos2];
            cc += (l+r)/2-pos1+1;
            pos2++;
        }
    }
    while(pos1<=(l+r)/2){
        t[count++] = a[pos1];
        pos1++;
    }
    while(pos2<=r){
        t[count++] = a[pos2];
        pos2++;
    }
    for (int i = l; i <= r;i++){
        a[i] = t[i];
    }
    ans += cc;
    //printf("l=%d r=%d cc=%d ans=%d \n", l, r, cc, ans);
}
void mergesort(int l, int r) {
    if (r - l < 1)
        return;
    else {
        mergesort(l, (l+r) / 2);
        mergesort((l+r) / 2 + 1, r);
    }
    merge(l, r);
}
int main() {
    int n;
    freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(0, n - 1);
    printf("%lld", ans);
    return 0;
}