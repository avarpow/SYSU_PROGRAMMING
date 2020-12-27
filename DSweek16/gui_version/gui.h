
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
    //站点全局编号
    int num;
    //站点所属线路编号
    int line;
    //站点中文名称
    string name;
    //站点汉语拼音 无声调
    string pinyin;
    //站点所属线路的名称
    string line_name;
};
struct subway_line
{
    //线路全局编号
    int num;
    //线路名称
    string name;
    //线路起始站点的全局编号
    int start_station_num;
    //线路终末站点的全局编号
    int end_station_num;
};
struct edge
{
    //边的起始站点编号
    int from;
    //边的终止站点编号
    int to;
    //边的权重， 根据情况有可能是站点的数量，有可能是站点的换乘数
    int weight;
};
class subway_query
{
    //储存地铁图的邻接表
    vector<vector<edge>> g;
    //储存地铁总共有多少条地铁站点
    int stations_num;
    //储存地铁总共有多少条地铁线路
    int lines_num;
    //储存各个地铁站店的站点信息
    vector<station> stations;
    //储存各个地铁线路的线路信息
    vector<subway_line> lines;

public:
    //初始化
    void init_subway();
    //清除图中的边
    void clear_edge();
    //添加换乘的站点，权值计算方式为站点数量
    void add_cross_station();
    //添加同一条线路上的站点,权值计算方式为站点数量
    void add_normal_station();
    //添加换乘的站点，权值计算方式为换乘数量
    void add_huancheng_cross_station();
    //添加同一条线路上的站点,权值计算方式为换乘数量
    void add_huancheng_normal_station();
    //按照最小途径站点数量获取最短路径，返回站点序列
    vector<station> get_shortest_path(string station_a, string station_b);
    //按照最小途径站点数量获取最短路径的一个重载
    vector<station> get_shortest_path(int station_a, int station_b);
    //按照最小换乘数量获取最短路径，返回站点序列
    vector<station> get_huancheng_shortest_path(string station_a, string station_b);
    //按照最小换乘数量获取最短路径的一个重载
    vector<station> get_huancheng_shortest_path(int station_a, int station_b);
    //创建返回给gui类的最短路结果的字符串对象，逻辑与现实分离
    string creat_result_path(vector<station> path);
    //创建返回给gui类的线路信息查询字符串对象，逻辑与现实分离
    string get_line_message(int line_num);
    //根据string查询对应的站点全局编号接口
    int getIndexByString(string station_string);
    //根据模糊的汉语拼音查询对应的站点全局编号接口
    vector<station> sta_mohu_query(string py);
};



class GUI
{
    //内部的查询结构
    subway_query t;

public:
    //初始化gui
    void GUIinit();
    //gui主循环
    void GUImain();
    //展示主页面菜单
    void showMainMenu();
    //展示线路信息查询页面菜单
    void show_line_queryMenu();
    //展示站点信息查询页面菜单
    void show_station_queryMenu();
    //清空当前页面显示的内容
    void clearMenu();
    //进入地铁线路信息查询页面
    void subway_line_query();
    //输出地铁线路信息查询
    void print_line_query_message(int line_num);
    //进入地铁站点-站点查询页面
    void subway_station_query();
    //暂停函数
    void delay();
    //打印错误信息
    void wrong_message();
    //根据站点的模糊汉语拼音查询
    void mohu_query();
    //根据站点编号查询
    void code_query();
    //根据线路的精确名称查询
    void name_query();
    //输出string信息到展示页面的接口
    void gui_print_msg(string);
    //从对话框获取输入的数字
    int get_int_input(string);
    //从对话框获取输入的字符串
    string get_string_input(string);
    //获取模糊选择的线路全局编号
    int mohu_select();
};