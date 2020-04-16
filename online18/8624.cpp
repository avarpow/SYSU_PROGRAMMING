#include <stdio.h>
#include <string.h>
struct node
{
    int val;
    int step;
};
int vis[10100] = {0};
struct node que[10000];
int top = 0, end = 0;
int main()
{
    int t;
    scanf("%d", &t);
    int ori, ans;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        top = end = 0;
        scanf("%d%d", &ori, &ans);
        struct node temp;
        temp.val = ori;
        temp.step = 0;
        vis[temp.val] = 1;
        que[end++] = temp;
        int flag = 0;
        while (end - top > 0)
        {
            int fi, sec;
            if (que[top].val == ans)
            {
                printf("%d\n", que[top].step);
                flag = 1;
                break;
            }
            struct node temp1 = que[top];
            if (temp1.val / 1000 == 9)
            {
                temp1.val = temp1.val - 8000;
            }
            else
            {
                temp1.val = temp1.val + 1000;
            }
            temp1.step++;
            if (vis[temp1.val] == 0)
            {
                que[end++] = temp1;
                vis[temp1.val] = 1;
            }

            temp1 = que[top];
            temp1.step++;
            if (temp1.val / 1000 == 1)
            {
                temp1.val = temp1.val + 8000;
            }
            else
            {
                temp1.val = temp1.val - 1000;
            }
            if (vis[temp1.val] == 0)
            {
                que[end++] = temp1;
                vis[temp1.val] = 1;
            }
            struct node temp2 = que[top];
            if ((temp2.val / 100) % 10 == 9)
            {
                temp2.val -= 800;
            }
            else
            {
                temp2.val += 100;
            }
            temp2.step++;
            if (vis[temp2.val] == 0)
            {
                que[end++] = temp2;
                vis[temp2.val] = 1;
            }

            temp2 = que[top];
            temp2.step++;
            if ((temp2.val / 100) % 10 == 1)
            {
                temp2.val += 800;
            }
            else
            {
                temp2.val -= 100;
            }
            if (vis[temp2.val] == 0)
            {
                que[end++] = temp2;
                vis[temp2.val] = 1;
            }
            struct node temp3 = que[top];
            if ((temp3.val / 10) % 10 == 9)
            {
                temp3.val -= 80;
            }
            else
            {
                temp3.val += 10;
            }
            temp3.step++;
            if (vis[temp3.val] == 0)
            {
                que[end++] = temp3;
                vis[temp3.val] = 1;
            }

            temp3 = que[top];
            temp3.step++;
            if ((temp3.val / 10) % 10 == 1)
            {
                temp3.val += 80;
            }
            else
            {
                temp3.val -= 10;
            }
            if (vis[temp3.val] == 0)
            {
                que[end++] = temp3;
                vis[temp3.val] = 1;
            }
            struct node temp4 = que[top];
            if (temp4.val % 10 == 9)
            {
                temp4.val -= 8;
            }
            else
            {
                temp4.val += 1;
            }
            temp4.step++;
            if (vis[temp4.val] == 0)
            {
                que[end++] = temp4;
                vis[temp4.val] = 1;
            }

            temp4 = que[top];
            temp4.step++;
            if (temp4.val % 10 == 1)
            {
                temp4.val += 8;
            }
            else
            {
                temp4.val -= 1;
            }
            temp4.step++;
            if (vis[temp4.val] == 0)
            {
                que[end++] = temp4;
                vis[temp4.val] = 1;
            }
            struct node temp5 = que[top];
            fi = temp5.val / 1000;
            sec = (temp5.val / 100) % 10;
            temp5.val -= (fi - sec) * 1000;
            temp5.val += (fi - sec) * 100;
            temp5.step++;
            if (vis[temp5.val] == 0)
            {
                que[end++] = temp5;
                vis[temp5.val] = 1;
            }
            struct node temp6 = que[top];
            fi = (temp6.val / 100) % 10;
            sec = (temp6.val / 10) % 10;
            temp6.val -= (fi - sec) * 100;
            temp6.val += (fi - sec) * 10;
            temp6.step++;
            if (vis[temp6.val] == 0)
            {
                que[end++] = temp6;
                vis[temp6.val] = 1;
            }
            struct node temp7 = que[top];
            fi = (temp7.val / 10) % 10;
            sec = temp7.val % 10;
            temp7.val -= (fi - sec) * 10;
            temp7.val += (fi - sec);
            temp7.step++;
            if (vis[temp7.val] == 0)
            {
                que[end++] = temp7;
                vis[temp7.val] = 1;
            }

            top++;
        }
    }
    return 0;
}