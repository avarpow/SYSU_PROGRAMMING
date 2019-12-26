#include<stdio.h>
#include<string.h>
struct stu{
    int a[6];
    char na[100];
} Stu[100];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%s", Stu[i].na);
    }
    for (int i = 0; i < 6;i++){
        for (int j = 0; j < n;j++){
            scanf("%d", &Stu[j].a[i]);
        }
    }
    int t;
    char name[100];
    scanf("%d", &t);
    for (int i = 0;i<t;i++){
        scanf("%s", &name);
        for (int i = 0; i < n;i++){
            if(strcmp(name,Stu[i].na)==0){
                int c = 0;
                for (int k = 0; k < 6;k++){
                    printf("%d%s", Stu[i].a[k],k==5?"\n":" ");
                    c += Stu[i].a[k];
                }
                printf("%d\n", c / 6);
                break;
            }
        }
    }
    return 0;
}