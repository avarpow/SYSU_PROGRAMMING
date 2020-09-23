#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeKLists(vector<vector<int>> &lists)
{
    // TODO: 优先完成这个函数
    vector<int> return_list;
    int now[lists.size()];
    for (int i = 0; i < lists.size(); i++)
    {
        now[i] = 0;
    }
    int return_flag = 0;
    while (return_flag == 0)
    {
        int minx = 999999999;
        int minindex = -1;
        for (int i = 0; i < lists.size(); i++)
        {
            if (now[i] < lists[i].size() && lists[i][now[i]] < minx)
            {
                minx = lists[i][now[i]];
                minindex = i;
            }
        }
        if (minindex == -1)
        {
            return_flag = 1;
        }
        else
        {
            return_list.push_back(minx);
            now[minindex]++;
        }
    }
    return return_list;
}

int main()
{
    vector<vector<int>> a;
    for (int i = 0; i < 3; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int tempint;
            cin >> tempint;
            temp.push_back(tempint);
        }
        a.push_back(temp);
    }
    vector<int> b = mergeKLists(a);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i];
    }
    return 0;
}

