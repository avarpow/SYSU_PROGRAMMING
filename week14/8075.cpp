#include <stdio.h>
int main(){
    int t,num;
    scanf("%d", &t);
    while(t-- && scanf("%d", &num))
        printf("%s\n", num % 3 ? "dalao win!" : "xinpang win!");
    return 0;
}