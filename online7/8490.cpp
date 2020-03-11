#include <stdio.h>
#include <string.h>

int main()
{
    char s[200];
    int sta[100], cur = 0, ans = 1;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        //printf("i=%d cur=%d\n",i,cur);
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            sta[cur++] = (s[i] == '(' ? (')') : (s[i] == '[' ? (']') : ('}')));
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (cur > 0)
            {
                if (sta[cur - 1] == s[i])
                {
                    cur--;
                }
                else
                {
                    ans = 0;
                    break;
                }
            }
            else
            {
                ans = 0;
                break;
            }
        }
    }
    if (cur != 0)
        ans = 0;
    printf("%s", ans ? "Yes" : "No");
}
/*现在给出一串字符串，里面的括号要不成双出现，要不就不出现，也就是括号匹配。括号的种类包括'{'、'}'、'('、')‘、'['、']'。请大家判断字符串是否括号匹配，是则输出"Yes"，反之输出"No"。字符串长度不大于100。

输入
abc(abc)
输出
Yes
输入
abv(aa
输出
No

*/