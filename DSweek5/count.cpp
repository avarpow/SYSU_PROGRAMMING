//count.cpp
//如果想要更方便复制请https://paste.ubuntu.com/p/PWTYqfcZbC/
#include <iostream>
#include <fstream>
#include <list>
#include <regex>
using namespace std;
void addWord(list<pair<string, int>> &m, string word){
    auto i=m.begin();
    while(i!=m.end() && word > i->first){
        i++;
    }
    if(i!=m.end() &&( i->first == word)){
        i->second++;
    }
    else{
        m.insert(i,make_pair(word,1));
    }
}
void generateIndex(list<pair<string, int>> &m, string filename)
{
    regex wordPattern("([a-z]|[A-Z]|[0-9])+");
    smatch now;
    string line_text;
    fstream in_file;
    in_file.open(filename,ios::in);
    if(!in_file.is_open()){
        cout<<"Open file fail EXIT!"<<endl;
        return;
    }
    while (in_file.peek()!=EOF)
    {
        getline(in_file, line_text);
        for (sregex_iterator it = sregex_iterator(line_text.begin(), line_text.end(), wordPattern);
             it != sregex_iterator(); it++)
        {
            smatch match;
            match = *it;
            addWord(m,match.str());
        }
    } 
}
void stroeResult(list<pair<string, int>> &m, string filename)
{
    fstream out_file;
    out_file.open(filename,ios::out);
    if(!out_file.is_open()){
        return;
    }
    for (auto &i : m)
    {
        out_file << i.first << " " << i.second << endl;
        cout << i.first << " " << i.second << endl;
    }
    return;
}
void print()
{
}
int inputCommand(int argc, char *argv[], string &inputFileStr, string &ouputFileStr)
{
    if (argc != 3)
    {
        cout << "input format wrong" << endl;
        return -1;
    }
    inputFileStr = argv[1];
    ouputFileStr = argv[2];
    return 0;
}
int main(int argc, char *argv[])
{
    string inputFileStr, ouputFileStr;
    if(inputCommand(argc, argv, inputFileStr, ouputFileStr)){
        return 0;
    }
    list<pair<string, int>>  result_list;
    generateIndex(result_list, inputFileStr);
    stroeResult(result_list, ouputFileStr);
    return 0;
}
