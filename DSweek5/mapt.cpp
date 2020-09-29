#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<string, int> m;
    m["one"] = 123;
    m["two"] = 234;
    m["two"]++;
    m["three"] = 345;
    m["four"]++;
    cout << m["one"] << " " << m["two"] << " " << m["four"] << endl;
    for (auto &i : m)
    {
        cout << " " << i.first << "  " << i.second << endl;
    }
    return 0;
}