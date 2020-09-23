#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int matches(string s)
{
    char stack[1000];
    int size = 0;
    for (auto &i : s)
    {
        switch (i)
        {
        case '[':
        case '{':
        case '(':
            stack[size++] = i;
            break;
        case '}':
            if (size == 0)
            {
                return 3;
            }
            else if (stack[size - 1] != '{')
            {
                return 1;
            }
            size--;
            break;
        case ']':
            if (size == 0)
            {
                return 3;
            }
            else if (stack[size - 1] != '[')
            {
                return 1;
            }
            size--;
            break;
        case ')':
            if (size == 0)
            {
                return 3;
            }
            else if (stack[size - 1] != '(')
            {
                return 1;
            }

            size--;
            break;
        default:
            break;
        }
    }
    if (size == 0)
        return 0;
    else
        return 2;
}
int main()
{
    string s;
    cin >> s;
    cout << matches(s) << endl;
}