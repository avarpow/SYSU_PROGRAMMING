#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand((unsigned)time(NULL));
    int n = 100000,k=100;
    freopen("in.txt", "w", stdout);
    printf("%d %d\n",n,k);
    for (int i = 0; i < n;i++){
        printf("%d ", i%10000);
    }
    printf("\n");
    return 0;
}