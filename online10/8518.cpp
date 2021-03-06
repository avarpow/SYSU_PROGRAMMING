#include <stdio.h>
#define N 2000000
int ts[2][N];
int size[2] = {0};
int main()
{
    int n, all = 1, t;
    scanf("%d", &n);
    all <<= n;
    for (int i = 0; i < all; i++)
    {
        scanf("%d", &t);
        if (t & 1)
        {
            ts[1][size[1]++] = t;
        }
        else
        {
            ts[0][size[0]++] = t;
        }
    }
    int l = 0, r = 0;
    while (l < size[0] && r < size[1])
    {
        if (ts[0][l] < ts[1][r])
        {
            printf("%d ", ts[0][l++]);
        }
        else
        {
            printf("%d ", ts[1][r++]);
        }
    }
    while (l < size[0])
    {
        printf("%d ", ts[0][l++]);
    }
    while (r < size[1])
    {
        printf("%d ", ts[1][r++]);
    }
    return 0;
}
/*
Chino's Rabbits
Description
智乃收到了你排好序后的数据，认为你非常的能干，于是告诉了你她的想法：她想让这些兔子进行一场比赛！

比赛规则很简单：一共有2n只兔子，一共进行n场比赛，第i场比赛，每只兔子被随机分到一个组里，每组有两只兔子，有2i−1组，每组里战斗力高的兔子会获胜，战斗力低的则被淘汰出局。智乃十分在意那只毛茸茸度最高的兔子，她的战斗力在这2n只兔子里排名是第k位，她想知道这只兔子期望能比到第几场比赛。

但是心爱觉得这种比赛太low了，她看了一眼就告诉了智乃答案。

智乃看到自己中意的兔子的期望能比到的比赛场次很低，非常伤心qwq，于是她拿出了randomshuffle函数，根据这些兔子的毛茸茸性运行了这个函数，这2n只兔子就被打乱了！心爱非常惊慌~~因为智乃妹妹伤心了~~，但她知道有一个办法能让智乃开心：这2n只兔子从左到右排成一排，第i只兔子的毛茸茸性为MOFUMOFUi，她可以进行多次操作，每一次可以交换两只相邻兔子的位置，如果最终这2n只兔子的毛茸茸性所构成的序列的字典序最小，智乃就会开心起来。但是在移动的时候，心爱惊奇的发现相邻的两只兔子如果她们的毛茸茸性的奇偶性相同，她们就不肯交换。心爱不知所措qwq，就来拜托你了。

换句话说，这里有2n个数，每一次可以交换两个相邻的且奇偶性不同的两个数，可以进行任意多次操作（包括0次），求最终得到的字典序最小的序列。

Input
第一行有一个正整数n(1≤n≤20)，表示有2n只兔子。

第二行有2n个整数。第i个整数MOFUMOFUi(1≤MOFUMOFUi≤10000000)，分别表示第i只兔子的毛茸茸性。

Output
输出有一行，包括2n个整数，表示进行操作后得到的字典序最小的序列。

Sample input
3

1 2 5 2 5 6 3 7

Sample output
1 2 2 5 5 3 6 7
*/