/*
Description
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数，比如7，1221，12321都是回文数，而1234不是回文数。 现在给出一些数，请你判断它们是不是回文数。

input
第一行是一个整数 n，代表数字的个数，0 < n <= 100

第二行是n个整数，是需要你判断的数，每个数的范围是[0, 100000000]

output
输出 n 行，每一行输出一个"Yes"或"No"，代表对应的数字是不是回文数

sample input
3
7
2345
12321
sample output
Yes
No
Yes
Hint
请通过取整和取余操作来进行回文数的判断。
*/
/*我懒，就不*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,flag=0;
    char t[20];
    scanf("%d", &n);
    for (int i = 0; i < n;i++,flag=0){
        scanf("%s", &t);
        int len = strlen(t);
        for (int j = len - 1, k = 0; k < j;j--,k++){
            if(t[j]!=t[k]){
                flag = 1;
                break;
            }
        }
        printf("%s\n", flag == 0 ? "Yes" : "No");
    }
    return 0;
}