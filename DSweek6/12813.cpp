#include<string>
#include<iostream>
#include<map>
#include<stack>
using namespace std;
bool cal(char op,bool a,bool b=false){
    if(op == '+'){
        return a||b;
    }
    if(op == '-'){
        return !a;
    }
    if(op == '*'){
        return a&&b;
    }
    else return false;
}
bool eval_BE(const string & exp, map<char, bool> f){
    stack<bool> t;
    for(const char &i:exp){
        if(i=='0'){
            t.push(false);
        }
        else if(i=='1'){
            t.push(true);
        }
        else if(i=='+'){
            bool a=t.top();
            t.pop();
            bool b=t.top();
            t.pop();
            t.push(cal('+',a,b));
        }
        else if(i=='-'){
            bool a=t.top();
            t.pop();
            t.push(cal('-',a));
        }
        else if(i=='*'){
            bool a=t.top();
            t.pop();
            bool b=t.top();
            t.pop();
            t.push(cal('*',a,b));
        }
        else {
            t.push(f[i]);
        }      
    }
    return t.top();
}
int main(){
    string exp;
    map<char, bool> f;
    f['a']=true;
    f['b']=true;
    cin>>exp;
    cout<<eval_BE(exp,f)<<endl;
}
