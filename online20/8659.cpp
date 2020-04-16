#include <stdio.h>
#include <string.h>
int a[1005000];
int find(int k)
{
    if (a[k] == k)
        return k;
    else
    {
        a[k] = find(a[k]);
    }
    return a[k];
}
void add(int q, int w)
{
    int qf = find(q);
    int wf = find(w);
    if (qf != wf)
    {
        a[wf] = qf;
    }
    return;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        a[i] = i;
    }
    char s[5];
    int q, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%s%d%d", s, &q, &w);
        if (s[0] == 'c')
        {
            add(q, w);
        }
        else
        {
            if (find(q) != find(w))
            {
                printf("Not connected!\n");
            }
            else
                printf("Connected!\n");
        }
    }
    return 0;
}