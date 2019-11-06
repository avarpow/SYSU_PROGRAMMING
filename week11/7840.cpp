/*
Description
3位水仙花数指个位、十位、百位的立方和等于这个数本身的3位数.给出一个3位数，求不大于这个数的最大的3位水仙花数，若不存在，输出"Doesn't exist"。

Input
一个3位正整数

Output
不大于这个数的最大的3位水仙花数 或 "Doesn't exist"。

Sample Input
998

Sample Output
407

若不存在，返回－1
*/
#include <stdio.h>
int getRightNum(int n){
    int ans = -1;
    for (int i = n; i >= 111;i--){
        if((i/100)*(i/100)*(i/100)+(i/10%10)*(i/10%10)*(i/10%10)+(i%10)*(i%10)*(i%10)==i){
            ans = i;
            break;
        }
    }
    return ans;
}
int main(void) {
    int num;
    scanf("%d", &num);
    int after = getRightNum(num);
    if(after == -1)
        printf("Doesn't exist\n");
    else 
        printf("%d\n", after);
    return 0;
}