/*
http://soj.acmm.club/show_problem.php?pid=1005&cid=2823
*/
#include<bits/stdc++.h>
using namespace std;
int table[105][105] = {0};
int vis[105][105] = {0};
vector<int> ans;
int best = -1;
int n, m,k;
void setvis(int i,int j){
        vis[i][j] = 1;
        vis[i][j+1] = 1;
        vis[i+1][j] = 1;
        vis[i+1][j+1] = 1;
}
void resetvis(int i,int j){
    vis[i][j] = 0;
    vis[i][j+1] = 0;
    vis[i+1][j] = 0;
    vis[i+1][j+1] = 0;
}
void revert(int i,int j){
    if(table[i][j]){
        table[i][j] = 0;
    }
    else{
        table[i][j] = 1;
    }
}
int checker(int i,int j){
    int count = 0;
    if((table[i][j]+table[i+1][j+1]+table[i+1][j]+table[i][j+1])%2){
        return 0;//不符合规则
    }
    else{
        return 1;
    }
}
void debug(){
    for (int i = 0; i < n;i++){
                for (int j = 0; j < m;j++){
                    printf("%d ", table[i][j]);
                }
                cout << endl;
            }
            cout << endl;
                    for (int i = 0; i < n;i++){
                for (int j = 0; j < m;j++){
                    printf("%d ", vis[i][j]);
                }
                cout << endl;
            }
            cout << endl;
                    for (vector<int>::const_iterator iter = ans.begin();iter != ans.end(); iter++) {
             cout << (*iter)<<" " ;
            }
            cout << endl;
}
int solver(int step,int c,int r){
    //printf("%d %d\n", c, r);
    //debug();
    vector<int> re;
    int min_ans = 999;
    if(step==k+1)
        return 999;
    else{
        int flag = 0;
        for (int i = 0; i < n-1 && flag==0;i++){
            for (int j = 0; j < m-1 && flag==0;j++){
                //printf("step=%d %d %d\n",step, i, j);
                if(checker(i,j)==0){
                    //printf("step=%d %d %d checked\n",step, i, j);
                    flag = 1;
                    if(i==0){
                        if(vis[i][j]==0){
                            revert(i, j);
                            setvis(i, j);
                            ans.push_back(i);
                            ans.push_back(j);
                            min_ans = min(solver(step + 1, i, j),min_ans);
                            revert(i, j);
                            resetvis(i, j);
                            ans.pop_back();
                            ans.pop_back();   
                        }
                        if(vis[i+1][j]==0){
                            revert(i+1, j);
                            setvis(i, j);
                            ans.push_back(i+1);
                            ans.push_back(j);                            
                            min_ans = min(solver(step + 1, i, j),min_ans);
                            revert(i+1, j);
                            resetvis(i, j);
                            ans.pop_back();
                            ans.pop_back();                               
                        }
                        if(vis[i][j+1]==0){
                            revert(i, j+1);
                            setvis(i, j);
                            ans.push_back(i);
                            ans.push_back(j+1);                            
                            min_ans = min(solver(step + 1, i, j),min_ans);
                            revert(i, j+1);
                            resetvis(i, j);
                            ans.pop_back();
                            ans.pop_back();                               
                        }
                        if(vis[i+1][j+1]==0){
                            revert(i+1, j+1);
                            setvis(i, j);
                            ans.push_back(i+1);
                            ans.push_back(j+1);                            
                            min_ans = min(solver(step + 1, i, j),min_ans);
                            revert(i+1, j+1);
                            resetvis(i, j);
                            ans.pop_back();
                            ans.pop_back();                               
                        }

                    }
                    else{

                        if(vis[i+1][j]==0){
                            revert(i+1, j);
                            setvis(i, j);
                            ans.push_back(i+1);
                            ans.push_back(j);                            
                            min_ans = min(solver(step + 1, i, j),min_ans);
                            resetvis(i, j);
                            revert(i+1, j);
                            ans.pop_back();
                            ans.pop_back();                            
                        }
                        if(vis[i+1][j+1]==0){
                            revert(i+1, j+1);
                            setvis(i, j);
                            ans.push_back(i+1);
                            ans.push_back(j+1);                            
                            min_ans = min(solver(step + 1, i, j),min_ans);
                            revert(i+1, j+1);
                            resetvis(i, j);
                            ans.pop_back();
                            ans.pop_back();                               
                        }
                    }
                }
                else{
                    vis[i][j] = 1;
                    vis[i][j+1] = 1;
                    vis[i+1][j] = 1;
                    vis[i+1][j+1] = 1;
                    re.push_back(i);
                    re.push_back(j);
                }
            }
        }
        if(flag==0){
            //printf("%d success\n", step);
        /*for (vector<int>::const_iterator iter = ans.begin();iter != ans.end(); iter++) {
             cout << (*iter)<<" " ;
            }2q
            cout << endl;
            for (int i = 0; i < n;i++){
                for (int j = 0; j < m;j++){
                    printf("%d", table[i][j]);
                }
                cout << endl;
            }*/
            while(!re.empty()){
                int t = re.back();
                re.pop_back();
                resetvis(t, re.back());
                re.pop_back();
            }
                return step;
        }
        else{
            while(!re.empty()){
                int t = *re.begin();
                re.pop_back();
                resetvis(t, *re.begin());
            }
            return min_ans;
        }
    }
}
void solve(){
    scanf("%d%d%d", &n, &m,&k);
    ans.clear();
    best = 999;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            scanf("%d", &table[i][j]);
            vis[i][j] = 0;
        }
    }
    int temp = solver(0, 0, 0);
    if (temp == 999)
        temp = -1;
    printf("%d\n", temp);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        solve();
    }
    scanf("%d", &n);
    return 0;
}