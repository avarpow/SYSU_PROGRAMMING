#include <stdio.h>
#include <time.h>

struct stanmsl
{
    long long t, kinds;
} status[2000000];
int costa = 0;
long long a[50];
long long now = 0;
long long ans = 0;
int n;
long long t;
long long nw = 0;
clock_t begin, end;
double cost;
long long backsum[50];
long long dich(long long k)
{
    int l = 0, r = costa - 1, mid = (l + r) / 2;
    while (r - l > 1)
    {
        if (status[mid].t == k)
        {
            l = r = mid;
            break;
        }
        else if (status[mid].t > k)
        {
            r = mid - 1;
            mid = (l + r) / 2;
        }
        else
        {
            l = mid;
            mid = (l + r) / 2;
        }
    }
    if (status[r].t <= k)
        return status[r].kinds;
    else
    {
        return status[l].kinds;
    }
}
void inidfs(int step, int end)
{
    if (step == end && now <= t)
    {
        status[costa].t = now;
        status[costa++].kinds = 1;
    }
    else
    {
        inidfs(step + 1, end);
        now += a[step];
        if (now <= t)
        {
            inidfs(step + 1, end);
        }
        now -= a[step];
    }
}
void dfs(int step, int iend)
{
    if (step == iend)
    {
        ans += dich(t - now);
    }
    else
    {
        dfs(step + 1, iend);
        now += a[step];
        if (now <= t)
        {
            dfs(step + 1, iend);
        }
        now -= a[step];
    }
}
void quicksort(int l, int r)
{
    if (l >= r)
        return;
    struct stanmsl temp = status[l];
    int left = l, right = r;
    while (left < right)
    {
        while (left < right && status[right].t >= temp.t)
        {
            right--;
        }
        status[left] = status[right];
        while (left < right && status[left].t <= temp.t)
        {
            left++;
        }
        status[right] = status[left];
    }
    status[left] = temp;
    quicksort(l, left - 1);
    quicksort(left + 1, r);
}
int main()
{
    long long sum = 0;
    scanf("%d%lld", &n, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a[i];
        sum += a[i];
    }
    //printf("%lld\n%lld\n", t, sum);
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[j + 1])
            {
                long long temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    begin = clock();
    inidfs(n / 2 + 4, n);
    quicksort(0, costa - 1);
    for (int i = 0; i < costa; i++)
    {
        int count = 1;
        while (status[i].t == status[i + 1].t)
            i++, count++;
        for (int j = 0; j < count; j++)
        {
            status[i - j].kinds = status[i - count].kinds + count;
        }
    }
    dfs(0, n / 2 + 4);
    printf("%lld", ans);
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
    return 0;
}