#include<stdio.h>
int stairs(int n,int h){
    static int ans[100] = {1, 1};
    if(n<0)
        return 0;
    else{
        if(ans[n])
            return ans[n];
        else{
            for (int i = 1; i <= h;i++){
                ans[n] += stairs(n-i, h);
            }
            return ans[n];
        }
    }
}
int main(){
    int n, h;
    scanf("%d%d", &n, &h);
    printf("%d",stairs(n, h));
    return 0;
}