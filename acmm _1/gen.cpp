#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand((unsigned)time(NULL));
    freopen("in.txt", "w", stdout);
    printf("10\n");
    for (int i = 0; i < 10;i++){
        int n, m, k;
        n= rand() % 20+1;
        m = rand() % 20+1;
        k = 10;
        printf("%d %d %d \n", n, m, k);
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                int t;
                t = rand() % 2;
                printf("%d ", t);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}