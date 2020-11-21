#include <iostream>
#include <map>
using namespace std;
map<string, string> m;
void record()
{
    int n;
    cin >> n;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        int pos = temp.find(',');
        string name(temp.begin(), temp.begin() + pos);
        string phone(temp.begin() + pos + 1, temp.end());
        m.insert(make_pair(name, phone));
    }
}
void search()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        auto it = m.find(name);
        if (it != m.end())
        {
            cout << name << ":" << it->second << endl;
        }
        else
        {
            cout << name << ":"
                 << "NO" << endl;
        }
    }
}
int main()
{
    record();
    search();
}