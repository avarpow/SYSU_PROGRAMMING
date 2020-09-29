#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "input format wrong" << endl;
        return 0;
    }
    string inputFileStr, ouputFileStr;
    inputFileStr = argv[1];
    ouputFileStr = argv[2];
}