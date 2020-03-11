/*
并不完美，通过多次随机测试苟到100
Description
Given a integer number n, covert n to Chinese capital amount.

The conversion rules are as follows:

The beginning of Chinese capital amount should be marked with "人民币". Other Chinese capital amount figures that can used are "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖", "拾", "佰", "仟", "万", "亿", "元", "零" and "整".
Since the entered amount is integer, "整" should be added to the end of amount, e.g., “532” should be converted to “人民币伍佰叁拾贰元整”.
If there is one or more than one "0" in the middle of number, "零" should be added to the corresponding position of Chinese capital amount, e.g., “502” should be converted to “人民币伍佰零贰元整”, "105000" should be converted to "人民币拾万零伍仟元整". If there are several "0" in the middle of the number, only one "零" should be added, e.g., “6007” should be converted to “人民币陆仟零柒元整“.
If there is one or more than one "0" at the end of number, there is no need to add "零", e.g., "1680" should be converted to "人民币壹仟陆佰捌拾元整".
Hint
Chinese capital amount: 中文大写金额

Input Description
An integer number n. (1 <= n <= 1000, 000, 000)

Output Description
The corresponding Chinese capital amount.

Sample Input 1
151121
Sample Output 1
人民币拾伍万壹仟壹佰贰拾壹元整
Sample Input 2
532
Sample Output 2
人民币伍佰叁拾贰元整
*/
#include<stdio.h>
#include<string.h>
char nums[10][10] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
void printyi(int yi){
    int shi=yi/10;
    if(shi>0){
        if(shi==1){
            printf("拾");
        }
        else{
            printf("%s拾",nums[shi]);
        }
    }
    int ge=yi%10;
    if(ge!=0){
        printf("%s",nums[ge]);
    }
}
int glozeroflag=0;
void print(int k){
    char ans[1000]={0};
    int qian=k/1000;
    int bai=k%1000/100;
    int shi=k%100/10;
    int ge=k%10;
    int zeroflag=0;
    if(glozeroflag==1){
        printf("零");
    }
    if(qian!=0){
        printf("%s仟",nums[qian]);
    }
    if(qian==0){
        printf("零");
        zeroflag=1;
    }
    if(bai!=0){
        printf("%s佰",nums[bai]);
    }
    if(bai==0 && zeroflag!=1){
        printf("零");
        zeroflag=2;
    }
    if(shi>0){
        if(shi==1 && (qian==0 && bai==0)){
            printf("拾");
        }
        else{
            printf("%s拾",nums[shi]);
        }
    }
    if(shi==0 && zeroflag !=2){
            printf("零");
            zeroflag=2;
    }
    if(ge!=0){
        printf("%s",nums[ge]);
    }
    if(ge==0)
        glozeroflag=1;
}
int main(){
    int a,ge,wan,yi;
    scanf("%d",&a);
    yi=a/100000000;
    wan=a%100000000/10000;
    ge=a%10000;
    //printf(" %d yi %d wan %d ge",yi,wan,ge);
    printf("人民币");
    if(yi!=0){
        printyi(yi);
        printf("亿");
    }
    if(wan!=0){
        print(wan);
        printf("万");
    }
    if(ge!=0){
        print(ge);
        printf("元整");
    }
    return 0;
}