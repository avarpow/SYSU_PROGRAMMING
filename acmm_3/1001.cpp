/*
http://soj.acmm.club/show_problem.php?pid=1001&cid=2825
*/
#include <bits/stdc++.h>
using namespace std;
int a[100003];
int h[100003];
int c = 0;
void dd(){
    for (int i = 1; i < 10;i=i*2){
        for (int j = 0; j < i;j++){
            printf("%d ",h[i + j]);
        }
        cout << endl;
    }
    cout << endl;
}
int bro(int now){
    if(now%2==0){
        if(now+1<=c){
            return now + 1;
        }
        else{
            return now;
        }
    }
    else{
        return now - 1;
    }
}
void delh(){
    swap(h[1], h[c]);
    h[c] = 0;
    c--;
    int now = 1;
    while(now*2<=c||now*2+1<=c){
        if(now*2+1<=c){
            if(h[now]<h[now*2+1] && h[now]<h[now*2]){
                break;
            }
            if(h[now*2+1]<h[now*2]){
                swap(h[now], h[now * 2 + 1]);
                now = now * 2 + 1;
            }
            else{
                swap(h[now], h[now * 2] );
                now = now * 2 ;                
            }
        }
        else{
            if(h[now*2]<h[now]){
                swap(h[now], h[now * 2] );
                now = now * 2 ;
            } 
            else{
                break;
            }           
        }
    }
}
void addh(int n){
    c++;
    int now = c;
    h[c] = n;
    while(now>1){
        if(h[now]>h[now/2])
            break;
        if(h[now]<=h[bro(now)]){
            swap(h[now], h[now / 2]);
        }
        else{
            swap(h[bro(now)], h[now / 2]);
        }
        now = now / 2;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i < n;i++){
        scanf("%d", &a[i]);
        addh(a[i]);
    }
    for (int i = 0; i < n;i++){
        printf("%d ", h[1]);
        delh();
    }
    return 0;
}
