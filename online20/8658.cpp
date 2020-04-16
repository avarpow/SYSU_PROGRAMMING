#include <stdio.h>
#include <string.h>
#define N 1000000
int a[N], b[2 * N];
void quicksort(int *a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    else
    {
        int l = left, r = right;
        int k = a[left];
        while (l < r)
        {
            while (l < r && a[r] <= k)
            {
                r--;
            }
            a[l] = a[r];
            while (l < r && a[l] >= k)
            {
                l++;
            }
            a[r] = a[l];
        }
        a[l] = k;
        quicksort(a, left, l - 1);
        quicksort(a, l + 1, right);
    }
}
void up(int *b, int index)
{
    if (index == 1)
        return;
    if (b[index] > b[index / 2])
    {
        int k = b[index];
        b[index] = b[index / 2];
        b[index / 2] = k;
        up(b, index / 2);
    }
}
void add(int *h, int val, int size)
{
    h[size] = val;
    up(b, size);
}
void down(int *h, int index)
{
    if (h[index * 2] != -1 && h[index * 2 + 1] != -1)
    {
        if (h[index * 2] > h[index * 2 + 1] && h[index] < h[index * 2])
        {
            int k = h[index];
            h[index] = h[index * 2];
            h[index * 2] = k;
            down(h, index * 2);
        }
        else if (h[index * 2] <= h[index * 2 + 1] && h[index] < h[index * 2 + 1])
        {
            int k = h[index];
            h[index] = h[index * 2 + 1];
            h[index * 2 + 1] = k;
            down(h, index * 2 + 1);
        }
    }
    else if (h[index * 2] != -1 && h[index * 2 + 1] == -1 && h[index] < h[index * 2])
    {
        int k = h[index];
        h[index] = h[index * 2];
        h[index * 2] = k;
    }
}
void pop(int *h, int size)
{
    h[1] = h[size - 1];
    h[size - 1] = -1;
    down(b, 1);
}
int main()
{
    int n, m, op, ind = 0, size = 1;
    char s[10];
    memset(b, -1, sizeof(b));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", s);
        if (s[0] == 'q')
        {
            if (ind < n && a[ind] > b[1])
            {
                printf("%d\n", a[ind++]);
            }
            else
            {
                printf("%d\n", b[1]);
                pop(b, size);
                size--;
            }
        }
        else
        {
            scanf("%d", &op);
            add(b, op, size);
            size++;
        }
    }
    while (ind < n && size > 1)
    {
        if (ind < n && a[ind] > b[1])
        {
            printf("%d\n", a[ind++]);
        }
        else
        {
            printf("%d\n", b[1]);
            pop(b, size);
            size--;
        }
    }
    while (ind < n)
    {
        printf("%d\n", a[ind++]);
    }
    while (size > 1)
    {
        printf("%d\n", b[1]);
        pop(b, size);
        size--;
    }
    return 0;
}
