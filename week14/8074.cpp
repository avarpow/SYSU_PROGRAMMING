#include <stdio.h>
int ring(int, int);
int main(){
    int n, m;
    while(1){
    scanf("%d%d", &n, &m);
    printf("%d\n", ring(n, m)+1);
    }
    return 0;
    }
int ring(int n,int m){
    if(n==1)
        return 0;
    return (ring(n - 1, m) + m) % n ;
}