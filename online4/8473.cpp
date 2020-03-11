/*
任何一个正整数都可以用2的幂次方表示。例如：

137=27+23+20
同时约定次方用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：2(7)+2(3)+2(0)

进一步：7=2(2)+2+2(0)，3=2+2(0)

所以最后137可表示为：2(2(2)+2+2(0))+2(2+2(0))+2(0)

输入
一个正整数n(n<=20000)

输出
一行，符合约定的n的0,2表示（在表示中不能有空格）

样例输入
137
样例输出
2(2(2)+2+2(0))+2(2+2(0))+2(0)
*/
#include<stdio.h>
#include<string.h>
void solve(int n){
    if(n==0){
        printf("0");
    }
    else if(n==2){
        printf("2");
    }
    else {
        int b=2,wei=1,flag=0;
        while(b<n){
            b<<=1;
            wei++;
            }
        while(wei>=0){
            if((n&b)!=0){
                if(flag==1){
                        printf("+");
                }
                if(wei==0){
                    printf("2(0)");
                }
                else if(wei==1){
                    printf("2");
                }
                else if(wei==2){
                    printf("2(2)");                    
                }
                else{
                    printf("2(");
                    solve(wei);
                    printf(")");
                }
                flag = 1;
            }
            wei--;
            b>>=1;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}