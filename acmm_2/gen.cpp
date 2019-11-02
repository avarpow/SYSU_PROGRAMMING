#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand((unsigned)time(NULL));
    int n = 100000;
    freopen("in.txt", "w", stdout);
    printf("%d\n",n);
    for (int i = 0; i < n;i++){
        printf("%d ", 100000 - i);
    }
    printf("\n");
    return 0;
}