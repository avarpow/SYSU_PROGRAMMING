/*
http://soj.acmm.club/show_problem.php?pid=1004&cid=2823
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,cell[60][60];
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        int x, y,ans=0,start_x,start_y;
        scanf("%d%d", &x, &y);
        for (int i = 0; i < x;i++){
            for (int j = 0; j < y;j++){
                scanf("%c", &cell[i][j]);
                if(cell[i][j]!='S' && cell[i][j]!='.' && cell[i][j]!='#')
                    j--;
                if(cell[i][j]=='S'){
                    start_x = i;
                    start_y = j;
                }
            }
        }
        for (int i = start_x; i >= 0;i--){
            if(cell[i][start_y]=='#')
                ans = 999;
        }
        for (int i = start_x; i < x;i++){
            if(cell[i][start_y]=='#')
                ans = 999;
        }
        for (int i = start_y; i >= 0;i--){
            if(cell[start_x][i]=='#')
                ans = 999;
        }
        for (int i = start_y; i < y;i++){
            if(cell[start_x][i]=='#')
                ans = 999;
        }
        if(ans<start_x + start_y + x - start_x - 1 + y - start_y - 1)
            ans = start_x + start_y + x - start_x - 1 + y - start_y - 1;
        /*if(ans<start_y)
            ans = start_y + x - start_x - 1;
        if(ans<x-start_x-1)
            ans = x - start_x - 1 + y - start_y - 1;
        if(ans<y-start_y-1)
            ans = start_x + y - start_y - 1;*/
        if(ans==999)
            printf("-1\n");
        else{
            printf("%d\n", ans);
        }
    }
    return 0;
}