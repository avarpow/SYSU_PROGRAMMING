/*
中缀表达式转换后缀表达式
⑴ 初始化两个栈：运算符栈s1和储存中间结果的栈s2；

⑵ 从左至右扫描中缀表达式；

⑶ 遇到操作数时，将其压s2；

⑷ 遇到运算符时，比较其与s1栈顶运算符的优先级：

① 如果s1为空，或栈顶运算符为左括号“(”，则直接将此运算符入栈；

② 否则，若优先级比栈顶运算符的高，也将运算符压入s1；

③ 否则，将s1栈顶的运算符弹出并压入到s2中，再次转到①与s1中新的栈顶运算符相比较；

⑸ 遇到括号时：

① 如果是左括号“(”，则直接压入s1；

② 如果是右括号“)”，则依次弹出s1栈顶的运算符，并压入s2，直到遇到左括号为止，此时将这一对括号丢弃；

⑹ 重复步骤⑵至⑸，直到表达式的最右边；

⑺ 将s1中剩余的运算符依次弹出并压入s2；

⑻ 依次弹出s2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式
*/
#include <stdio.h>
#include <string.h>
#define N 100005
char s[N] = {0}, s1[N] = {0}, s2[N] = {0};
int i1[N] = {0}, i2[N] = {0};
int size1 = 0, size2 = 0;
int level(char op)
{
    switch (op)
    {
    case '&':
        return 3;
    case '^':
        return 2;
    case '|':
        return 1;
    case '+':
        return 5;
    case '-':
        return 5;
    case '*':
        return 6;
    case '/':
        return 6;
    }
}
int cal(int a, int b, int op)
{
    switch (op)
    {
    case '&':
        return (a & b);
    case '^':
        return (a ^ b);
    case '|':
        return (a | b);
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        return (a / b);
    }
}
int main()
{
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i <= len; i++)
    {
        if (i == len)
        {
            while (size1)
            {
                s2[size2++] = s1[size1 - 1];
                size1--;
            }
            s2[size2] = '\0';
        }
        if (s[i] <= '9' && s[i] >= '1')
        {
            s2[size2++] = s[i];
        }
        else if (s[i] == '(')
        {
            s1[size1++] = '(';
        }
        else if (s[i] == ')')
        {
            while (s1[size1 - 1] != '(')
            {
                s2[size2++] = s1[size1 - 1];
                size1--;
            }
            size1--;
        }
        else
        {
            while (1)
            {
                if (size1 == 0)
                {
                    s1[size1++] = s[i];
                    break;
                }
                else if (s1[size1 - 1] == '(')
                {
                    s1[size1++] = s[i];
                    break;
                }
                else if (level(s1[size1 - 1]) < level(s[i]))
                {
                    s1[size1++] = s[i];
                    break;
                }
                else
                {
                    s2[size2++] = s1[size1 - 1];
                    size1--;
                }
            }
        }
    }
    //printf("%s\n", s2);
    size1 = 0;
    len = strlen(s2);
    for (int i = 0; i < len; i++)
    {
        if (s2[i] >= '0' && s2[i] <= '9')
        {
            i2[i] = s2[i] - '0';
        }
        else
        {
            i2[i] = s2[i];
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (i2[i] >= 0 && i2[i] <= 9)
        {
            i1[size1++] = i2[i];
        }
        else
        {
            int a = i1[size1-- - 1];
            int b = i1[size1-- - 1];
            i1[size1++] = cal(b, a, i2[i]);
        }
    }
    printf("%d", i1[0]);
    return 0;
}
/*
Background Story
出题人一行赶到，打败了魔兽，出题人还解开了蕾姆的心结，蕾姆幸福地依偎在出题人怀里。

王选即将进行，艾米莉亚等人将要再次前往王都，出题人也想跟着去，但是艾米莉亚不同意，出题人苦苦相求，答应在路上辅导艾米莉亚学程设，这才被同意一同前往王都。

到了王都，一切都是那么的熟悉，出题人又遇见了卖苹果的大叔。

艾米莉亚怕出题人捣乱，嘱咐出题人留在宾馆，但是出题人心切，十分担心艾米莉亚。

Description
艾米莉亚没有办法，只好给出题人留了一道题，让他在宾馆里有事做。这道题是这样的：

现在有一个合法的二进制表达式，请计算出该表达式的值。

Input
​ 输入一行字符串，表示一个二进制表达式。长度不超过 100,000 。

Ouput
​ 输出表达式的值。

Example
Input	Output
(0&1^0|1)|1&0^1	1
Hint
​ 一个二进制表达式s是合法的，当且仅当以下任一条件成立：

s=0

s=1

存在一个合法的表达式t，使得s=(t)
存在两个合法的表达式a和b，使得s=a&b
存在两个合法的表达式a和b，使得s=a|b
存在两个合法的表达式a和b，使得s=a^b
*/