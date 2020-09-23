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
/*
括号匹配 实时评测
 2020-09-23 18:00
 1000 ms
 32 MB
 乔海燕 (qiaohy@mail.sysu.edu.cn)
给定一个表达式e，包含各种字符，如字母数字运算符标点空格和括号()[]{}等, 判断其中括号是否匹配，如是，则返回0, 否则根据错误类型返回1-3:

int matches(string e)

错误类型包括1、2、3类型： 类型1：左右括号不匹配，如"(]", "(((]))))", "((}","let {x=a[0)*(b+c); y=b}" 类型2: 发现有左括号不存在与之匹配的右括号，如"(", "(([]", "()([()" 类型3：发现右括号不存在与之匹配的左括号，如")", "())","(())]()"
*/