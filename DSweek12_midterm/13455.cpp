#include<iostream>
#include<vector>
using namespace std;
int getf(vector<int> &f,int k){
    if(f[k]==k){
        return k;
    }
    else{
        f[k]=getf(f,f[k]);
        return f[k];
    }
}
void join(vector<int> &f,int a,int b){
    f[b]=a;
}
void add(vector<int> &f,int a,int b){
    int fa=getf(f,a);
    int fb=getf(f,b);
    if(fa!=fb){
        join(f,fa,fb);
    }
}
void solve(){
    vector<int> f;
    int n,m;
    cin>>n>>m;
    f.resize(n+1);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        add(f,a,b);
    }
    if(m<n-1){
        cout<<"NO"<<endl;
        return;
    }
    int check=getf(f,1);
    int flag=0;
    for(int i=1;i<=n;i++){
        if(getf(f,i)!=check){
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        solve();
    }
}