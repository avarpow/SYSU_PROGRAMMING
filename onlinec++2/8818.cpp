//fun.h
#include <string>
using std::string;
int Plus(int &a, int &b)
{
    cout << "It's from int!" << endl;
    return a + b;
}
double Plus(double &a, double &b)
{
    cout << "It's from double!" << endl;
    return a + b;
}
string Plus(string &a, string &b)
{
    cout << "It's from string!" << endl;
    return a + b;
}
//main.cpp
#include <iostream>
using namespace std;
int main()
{
    int i1, i2;
    cin >> i1 >> i2;
    cout << Plus(i1, i2) << endl;
    double d1, d2;
    cin >> d1 >> d2;
    cout << Plus(d1, d2) << endl;
    string s1, s2;
    cin >> s1 >> s2;
    cout << Plus(s1, s2) << endl;
    return 0;
}
