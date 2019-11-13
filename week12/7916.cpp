/*
Description
桌子上有一叠牌，从第一张牌（即位于顶面的牌）开始从上往下依次编号为1~n。当至少剩下两张牌时进行以下操作：把第一张牌扔掉，然后把新的第一张牌放到整叠牌的最后。输入n，输出每次扔掉的牌，以及最后剩下的牌。

Input
第一行为一个整数t（0<t<20），表示测试用例个数。以下t行每行包含一个整数n（0<n<40）,为一个测试用例的牌数。 如： 1 7

Output
为每个测试用例单独输出一行，该行中依次输出每次掷出的牌的编号以及最后剩下牌的编号，每个牌编号后跟着一个空格。 如： 1 3 5 7 4 2 6(空格)
*/
#include<stdio.h>
int main()
{
    int n,t;
    scanf("%d", &t);
    for (int i = 0; i < t;i++){
        int sum = 0, index = 1,c=1;
        int a[55] = {0};
        scanf("%d", &n);
        while(sum!=n){
            index == n + 1 ? index = 1 : 0;
            if(a[index]==0){
                if(c==1){
                    printf("%d ", index);
                    a[index] = 1;
                    c = 0;
                    sum++;
                }
                else{
                    c = 1;
                }
            }
            index++;
        }
        printf("\n");
    }
    return 0;
}