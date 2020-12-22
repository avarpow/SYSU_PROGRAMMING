#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <Windows.h>
using namespace std;
struct station
{
    int num;
    int line;
    string name;
    string pinyin;
    string line_name;
};
struct line
{
    int num;
    string name;
    int start_station_num;
    int end_station_num;
};
struct edge
{
    int from;
    int to;
    int weight;
};
class subway_query
{
    vector<vector<edge>> g;
    int stations_num;
    int lines_num;
    vector<station> stations;
    vector<line> lines;

public:
    void init_subway();
    void add_cross_station();
    void add_normal_station();
    vector<station> get_shortest_path(string station_a, string station_b);
    string creat_result_path(vector<station> path);
    string get_line_message(int line_num);
    int getIndexByString(string station_string);
};

string subway_query::get_line_message(int line_num)
{
    string ret;
    line t_line = lines[line_num];
    ret += t_line.name;
    ret += "\n";
    int c = 1;
    for (int i = t_line.start_station_num; i <= t_line.end_station_num; i++)
    {
        station t_sta = stations[i];
        ret += "全局编号： ";
        ret += to_string(i);
        ret += "  线路编号： ";
        ret += to_string(c);
        ret += ": ";
        ret += t_sta.name;
        ret += "\n";
        c++;
    }
    return ret;
}
int subway_query::getIndexByString(string station_string)
{
    for (int i = 1; i <= stations_num; i++)
    {
        if (stations[i].name == station_string)
        {
            return i;
        }
    }
    return -1;
}

vector<station> subway_query::get_shortest_path(string station_a, string station_b)
{
    //todo dijkstar
    vector<int> vis;
    vector<int> dis;
    vector<int> pre;
    int start = getIndexByString(station_a);
    int end = getIndexByString(station_b);
    cerr << "start " << start << " end " << end << endl;
    vis.resize(stations_num + 1, 0);
    pre.resize(stations_num + 1, 0);
    dis.resize(stations_num + 1, 0x3f3f3f3f);
    vis[start] = 0;
    dis[start] = 0;
    pre[start] = -1;
    //int last_station=0;
    for (int i = 0; i < stations_num; i++)
    {
        //选取最近的点
        int now_station = 0;
        int now_mindis = 0x3f3f3f3f;
        for (int j = 1; j <= stations_num; j++)
        {
            if (vis[j] == 0 && dis[j] < now_mindis)
            {
                now_station = j;
                now_mindis = dis[j];
            }
        }
        if (now_station == 0)
        {
            cerr << "now_station == 0 exit" << endl;
            break; //完成
        }
        //已经确认 优化
        vis[now_station] = 1;
        cerr << "solve now_station = " << now_station << endl;
        for (int j = 0; j < g[now_station].size(); j++)
        {
            edge temp = g[now_station][j];
            if (dis[now_station] + temp.weight < dis[temp.to])
            {
                cerr << "optimize  from" << temp.from << " to " << temp.to << " dis " << dis[now_station] + temp.weight << endl;
                pre[temp.to] = now_station;
                dis[temp.to] = dis[now_station] + temp.weight;
            }
        }
    }
    int now_sta = end;
    vector<station> ret;
    while (now_sta != start)
    {
        ret.push_back(stations[now_sta]);
        now_sta = pre[now_sta];
    }
    // 反向
    for (int i = 0, j = ret.size() - 1; i < j; i++, j--)
    {
        swap(ret[i], ret[j]);
    }
    for (auto &i : ret)
    {
        cerr << i.name << " ";
    }
    cerr << endl;
    return ret;
}
string creat_result_path(vector<station> path)
{
}
void subway_query::add_normal_station()
{
    edge temp;
    for (auto &line : lines)
    {
        for (int i = line.start_station_num; i < line.end_station_num; i++)
        {
            temp.from = i;
            temp.to = i + 1;
            temp.weight = 1;
            g[temp.from].push_back(temp);
            temp.from = i + 1;
            temp.to = i;
            temp.weight = 1;
            g[temp.from].push_back(temp);
        }
    }
}
void subway_query::add_cross_station()
{
    edge temp;
    for (int i = 1; i <= stations_num; i++)
    {
        for (int j = i + 1; j < stations_num; j++)
        {
            if (stations[i].name == stations[j].name)
            {
                temp.from = i;
                temp.to = j;
                temp.weight = 0;
                g[temp.from].push_back(temp);
                temp.from = j;
                temp.to = i;
                temp.weight = 0;
                g[temp.from].push_back(temp);
                cerr << "connect cross " << i << " " << j << " " << stations[i].name << endl;
            }
        }
    }
}
void subway_query::init_subway()
{
    ifstream in_file;
    in_file.open("data_in");
    if (!in_file.is_open())
    {
        throw "file no open";
        return;
    }
    in_file >> this->stations_num;
    in_file >> this->lines_num;
    stations.resize(stations_num + 1);
    lines.resize(lines_num + 1);
    g.resize(stations_num + 1);
    int t_station_num;
    int t_line_num;
    string t_sta_name;
    string t_line_name;
    int last_line_num = 0;
    int last_station_num = 0;
    int now_station_num = 0;
    for (int i = 0; i < stations_num; i++)
    {
        in_file >> t_station_num >> t_sta_name >> t_line_num >> t_line_name;
        stations[t_station_num].num = t_station_num;
        stations[t_station_num].name = t_sta_name;
        stations[t_station_num].line = t_line_num;
        stations[t_station_num].line_name = t_line_name;
        lines[t_line_num].name = t_line_name;
        lines[t_line_num].num = t_line_num;
        now_station_num++;
        if (last_line_num != t_line_num)
        {
            lines[last_line_num].start_station_num = last_station_num;
            lines[last_line_num].end_station_num = now_station_num - 1;
            last_line_num = t_line_num;
            last_station_num = now_station_num;
        }
    }
    lines[t_line_num].start_station_num = last_station_num;
    lines[t_line_num].end_station_num = now_station_num;
    for (auto &i : stations)
    {
        cerr << i.num << " " << i.name << " " << i.line << " " << i.line_name << endl;
    }
    for (auto &i : lines)
    {
        cerr << i.num << " " << i.name << " " << i.start_station_num << " " << i.end_station_num << endl;
    }
    //todo add edge
    add_cross_station();
    add_normal_station();
}
class GUI
{
    subway_query t;

public:
    void GUIinit();
    void GUImain();
    void showMainMenu();
    void show_line_queryMenu();
    void show_station_queryMenu();
    void clearMenu();
    void subway_line_query();
    void print_line_query_message(int line_num);
    void subway_station_query();
    void delay();
};
void GUI::delay()
{
    system("pause");
}
void GUI::print_line_query_message(int line_num)
{
    string ret = t.get_line_message(line_num);
    cout << ret;
    delay();
}
void GUI::subway_station_query()
{
    int opcode = 0;
    while (opcode != -1)
    {
        show_station_queryMenu();
        int t;
        cin >> t;
        if (t == 1)
        {

        }
        if (t == 2)
        {

        }
        if (t == 3)
        {

        }
        if (t == 4)
        {
            opcode = -1;
        }
        else
        {
            opcode = 0;
        }
    }
}
void GUI::subway_line_query()
{
    int opcode = 0;
    while (opcode != -1)
    {
        show_line_queryMenu();
        int t;
        cin >> t;
        if (t == 17)
        {
            opcode = -1;
        }
        else
        {
            print_line_query_message(t);
        }
    }
}
void GUI::show_station_queryMenu()
{
    cout << "---------------------------广州地铁站点-站点查询------------------------\n"
            "                          1.模糊查询                       \n"
            "                          2.线路编号查询                       \n"
            "                          3.精确站点名称查询                       \n"
            "                          4.退出                       \n"
            "--------------------------------------------------------------\n";
}
void GUI::show_line_queryMenu()
{
    clearMenu();
    cout << "---------------------------广州地铁线路查询------------------------\n"
            "                          1.1号线                       \n"
            "                          2.2号线                       \n"
            "                          3.3号线                       \n"
            "                          4.3号线二期                       \n"
            "                          5.4号线                       \n"
            "                          6.5号线                       \n"
            "                          7.6号线                       \n"
            "                          8.7号线                       \n"
            "                          9.8号线                       \n"
            "                          10.9号线                       \n"
            "                          11.13号线                       \n"
            "                          12.14号线                       \n"
            "                          13.14号线二期                       \n"
            "                          14.21号线                       \n"
            "                          15.APM线                       \n"
            "                          16.广佛线                       \n"
            "                          17.退出                       \n"
            "--------------------------------------------------------------\n";
}
void GUI::GUImain()
{
    int opcode = 0;
    while (opcode != -1)
    {
        showMainMenu();
        int t;
        cin >> t;
        if (t == 1)
        {
            subway_line_query();
        }
        if (t == 2)
        {
            subway_station_query();
        }
        if (t == 3)
        {
            opcode = -1;
        }
        else
        {
            opcode = 0;
        }
    }
}
void GUI::GUIinit()
{
    t.init_subway();
}
void GUI::clearMenu()
{
    //system("cls");
}
void GUI::showMainMenu()
{
    clearMenu();
    cout << "---------------------------广州地铁查询------------------------\n"
            "                          1.地铁线路查询                       \n"
            "                          2.站点-站点查询                      \n"
            "                          3.退出                              \n"
            "--------------------------------------------------------------\n";
}
int main()
{
    GUI g;
    g.GUIinit();
    g.GUImain();

    // string a,b;
    // cin>>a;
    // cout<<a;
    // cin>>b;
    // cout<<b;
    // t.get_shortest_path(a,b);
}