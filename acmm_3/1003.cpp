/*
http://soj.acmm.club/show_problem.php?pid=1003&cid=2825
*/
#include <bits/stdc++.h>
using namespace std;
int c, t, e, tot = 0, dir = 0;
deque<int> shell;
stack<int> bot;
void in(int e){
    if(tot<c){
        shell.push_back(e);
    }
    else{
        if(dir==0){
            shell.push_back(e);
            bot.push(shell.front());
            shell.pop_front();
        }
        else{
            shell.push_front(e);
            bot.push(shell.back());
            shell.pop_back();
        }
    }
    tot++;
}
void out(){
    if(tot==0){
        printf("Error: the stack is empty!\n");
        return;
    }
    if(tot<=c){
        printf("%d\n", shell.back());
        shell.pop_back();
    }
    else{
        if (dir==0)
        {
            printf("%d\n", shell.back());
            shell.pop_back();
            shell.push_front(bot.top());
            bot.pop();
        }
        else{
            printf("%d\n", shell.front());
            shell.pop_front();
            shell.push_back(bot.top());
            bot.pop();
        }
    }
    tot--;
}
void rev(){
    if(tot<c){
        printf("Error: less than %d elements in the stack!\n",c);
        return;
    }
    else{
        if(dir==1)
            dir = 0;
        else
            dir = 1;
    }
}
int main(){
    scanf("%d", &c);
    while(scanf("%d",&t),t!=0){
        if(t==1){
            scanf("%d", &e);
            in(e);
        }
        else if(t==2){
            out();
        }
        else if(t==3){
            rev();
        }
    }
}
