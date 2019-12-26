/*
Description
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

Hint
    1 <= stones.length <= 30
    1 <= stones[i] <= 1000
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int dp[2][100000]={0};//-50000-49999
int lastStoneWeight(int *a,int n){
    int **dp=(int **)malloc(2*sizeof(int*));
    dp[0] = (int *)malloc(100000 * sizeof(int));
    dp[1] = (int *)malloc(100000 * sizeof(int));
    //memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 100000;i++){
        dp[0][i] = -1;
        dp[1][i] = -1;
    }
        dp[0][50000] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j < 100000;j++){
            if(dp[0][j]==i-1){
                dp[1][j - a[i-1]] = i;
                dp[1][j + a[i-1]] = i;
            }
        }
        for (int i = 0; i < 100000;i++){
            dp[0][i] = dp[1][i];
        }
    }
    for (int i = 50000; i < 100000;i++){
        if(dp[0][i]==n){
            return i-50000;
        }
    }
    return -200;
}
int main(){
	int size;
	int stones[31];
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &stones[i]);
	}
	int last_stone_weight = lastStoneWeight(stones, size);
	printf("%d\n", last_stone_weight);
	return 0;
}