//如果想要复制更方便可以看https://paste.ubuntu.com/p/vCyT6Q3tc7/
//key文件格式：各个单词之间用任意非英文以及数字字符隔开 如see, trees, bloom, roses, world
//index.cpp
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <regex>
using namespace std;
typedef list<pair<string, list<int>>> INDEX_TYPE;
typedef pair<string, list<int>> RESULT_TYPE;


void addWord(INDEX_TYPE &m, string word,int line_count)
{
    auto i = m.begin();
    while (i != m.end() && word > i->first)
    {
        i++;
    }
    if (i != m.end() && (i->first == word))
    {
        auto j=i->second.begin();
        while(j!=i->second.end()){
            j++;
        }
        if(j!=i->second.end() && *j!= line_count || j==i->second.end()){
            i->second.insert(j,line_count);
        }
        //else number already exist
    }
    //else is not in the key list ignored
}
void addKey(INDEX_TYPE &m, string word)
{
    auto i = m.begin();
    while (i != m.end() && word > i->first)
    {
        i++;
    }
    if (i != m.end() && (i->first == word))
    {
        return;
    }
    else
    {
        //插入有空列表的key
        m.insert(i, make_pair(word,list<int>()));
    }
}
void generateKeys(INDEX_TYPE &m, string filename)
{
    regex wordPattern("([a-z]|[A-Z]|[0-9])+");
    smatch now;
    string line_text;
    fstream key_file;
    key_file.open(filename, ios::in);
    if (!key_file.is_open())
    {
        cout << "Open key_file fail EXIT!" << endl;
        return;
    }
    while (key_file.peek() != EOF)
    {
        getline(key_file, line_text);
        for (sregex_iterator it = sregex_iterator(line_text.begin(), line_text.end(), wordPattern);
             it != sregex_iterator(); it++)
        {
            smatch match;
            match = *it;
            addKey(m, match.str());
        }
    }
}
void generateIndex(INDEX_TYPE &m, string filename)
{
    regex wordPattern("([a-z]|[A-Z]|[0-9])+");
    smatch now;
    string line_text;
    fstream in_file;
    int line_count=1;
    in_file.open(filename, ios::in);
    if (!in_file.is_open())
    {
        cout << "Open file fail EXIT!" << endl;
        return;
    }
    while (in_file.peek() != EOF)
    {
        getline(in_file, line_text);
        for (sregex_iterator it = sregex_iterator(line_text.begin(), line_text.end(), wordPattern);
             it != sregex_iterator(); it++)
        {
            smatch match;
            match = *it;
            addWord(m, match.str(),line_count);
        }
        line_count++;
    }
}
void stroeResult(INDEX_TYPE &m, string filename)
{
    fstream out_file;
    out_file.open(filename, ios::out);
    if (!out_file.is_open())
    {
        return;
    }
    for (auto &i : m)
    {
        out_file<<left<<setw(7)<<i.first<<" ";
        cout<<left<<setw(7)<<i.first<<" ";
        string temp;
        for(auto &k:i.second){
            temp+=k+'0';
            temp+=',';
        }
        temp.erase(temp.end()-1);
        cout<<temp<<endl;
        out_file<<temp<<endl;
    }
    return;
}
int inputCommand(int argc, char *argv[], string &inputFileStr, string &keyFileStr, string &ouputFileStr)
{
    if (argc != 4)
    {
        cout << "input format wrong" << endl;
        return -1;
    }
    inputFileStr = argv[1];
    keyFileStr = argv[2];
    ouputFileStr = argv[3];
    return 0;
}
int main(int argc, char *argv[])
{
    string inputFileStr, ouputFileStr, keyFileStr;
    if(inputCommand(argc, argv, inputFileStr, keyFileStr, ouputFileStr)){
        return 0;
    }
    INDEX_TYPE result_list;
    generateKeys(result_list, keyFileStr);
    generateIndex(result_list, inputFileStr);
    stroeResult(result_list, ouputFileStr);
    return 0;
}
