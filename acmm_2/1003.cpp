/*
http://soj.acmm.club/show_problem.php?pid=1003&cid=2824
*/
//必须在输入后就除以n才能过？？？？？？？
#include<bits/stdc++.h>
using namespace std;
struct ppp{
    double value;
    int order;
};
int cmp(const struct ppp a,const struct ppp b){
    return a.value < b.value;
}
ppp a[110000];
int n;
int main(){
    double time = 0;
    scanf("%d",&n);
    for (int i = 0; i < n;i++){
        scanf("%lf", &a[i].value);
        a[i].value /= n;
        a[i].order = i + 1;
    }
    sort(a, a + n,cmp);
    for (int i = 0; i < n;i++){
        time += (n - i) * a[i].value;
        printf("%d%s", a[i].order,i==n-1?"\n":" ");
    }
    printf("%.2lf\n", time);
    return 0;
}