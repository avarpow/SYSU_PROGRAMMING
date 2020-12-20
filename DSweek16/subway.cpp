#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct color{
    uint8_t r,g,b;
};
struct line{
    string name;
    color color;
    vector<int> stations;
    vector<int> crossing_stations;

};
struct time{
    int hour,min;
};
struct station{
    string name;
    int number;
    bool isCrossingStation;
    vector<int> lines;
    time startTime,endTime;
};
struct graph{
    int v;
    vector<vector<station>> edges;
};
class train_map{
    private:

    public:
        vector<line> lines;
        vector<station> stations;
        graph g;

};

