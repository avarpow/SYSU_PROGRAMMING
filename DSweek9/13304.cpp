#include "md5.h"
#include <iostream>
#include <vector>
using namespace std;
struct password_store
{
    string name, md5;
};
vector<password_store> st;
void store(int n)
{
    for (int i = 0; i < n; i++)
    {
        password_store t;
        cin >> t.name;
        cin >> t.md5;
        st.push_back(t);
    }
}
void test(int n)
{
    for (int i = 0; i < n; i++)
    {
        string name, password;
        cin >> name;
        cin >> password;
        string result = MD5(password).hexdigest();
        bool flag=true;
        for (auto &t : st)
        {
            if (name == t.name)
            {
                flag=false;
                cout << name;
                if (result == t.md5)
                {
                    cout << ":OK" << endl;
                }
                else
                {
                    cout << ":Invalid user name or password" << endl;
                }
            }
        }
        if(flag){
            cout<<name<<":Invalid user name or password"<<endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    store(3);
    cin >> n;
    test(n);
    return 0;
}