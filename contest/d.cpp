#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int flag = 0;
    if (x1 == x2 && y1 == y2)
    {
        if ((x3 == x4 && y3 == y4))
        {
            if (x1 == x3 && y1 == y3)
            {
                flag = 1;
            }
        }
        else
        {
            if ((x1 - x4) * (y1 - y3) - (y1 - y4) * (x1 - x3) == 0)
            {
                flag = 1;
            }
        }
    }
    else if (x3 == x4 && y3 == y4)
    {
        if ((x3 - x2) * (y3 - y1) - (y3 - y2) * (x3 - x1) == 0)
        {
            flag = 1;
        }
    }
    else
    {
        long long s1 = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
        long long s2 = (x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1);
        if (s1 == 0 || s2 == 0)
        {
            flag = 1;
        }
        else if (s1 > 0 && s2 < 0)
        {
            flag = 1;
        }
        else if (s1 < 0 && s2 > 0)
        {
            flag = 1;
        }
    }

    printf("%s\n", flag ? "yes" : "no");
    return 0;
}