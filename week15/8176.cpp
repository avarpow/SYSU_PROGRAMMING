#include <stdio.h>
#include <string.h>
char a[300]={0},b[300]={0},c[305]={0};
void init(){
    int lena = strlen(a);
    int lenb = strlen(b);
    for (int i = 0; i < lena;i++){   
        if(i<lena-1-i){
            int t=a[i];
            a[i] = a[lena - 1 - i];
            a[lena - 1 - i] = t;
        }
    }
    for (int i = 0; i < lenb;i++){   
        if(i<lenb-1-i){
            int t=b[i];
            b[i] = b[lenb - 1 - i];
            b[lenb- 1 - i] = t;
        }
    }
    for (int i = 0; i < lena;i++){
        a[i] = a[i] - '0';
    }
}
int main(){
    scanf("%s", a);
    scanf("%s", b);
    init();
    int lena = strlen(a);
    int lenb = strlen(b);
    for (int i = 0; i < lenb;i++){
        b[i] = b[i] - '0';
    }
    for (int i = 0; i < 300;i++){
        c[i] = c[i]+a[i] + b[i];
        if(c[i]>9){
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    int lenc = 300;
    while(c[lenc]==0)
        lenc--;
    for (int i = lenc; i >= 0;i--){
        printf("%d", c[i]);
    }
        return 0;
}