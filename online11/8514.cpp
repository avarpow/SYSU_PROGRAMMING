//矩阵快速幂
#include <stdio.h>
#define MOD 1000000007
long long mat[23][23] = {0};
long long ans[23][23] = {0};
long long dst[23][23] = {0};
void multipy(long long dst[23][23], long long a[23][23], long long b[23][23], int k)
{
    long long temp = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            temp = 0;
            for (int q = 0; q < k; q++)
            {
                temp += ((a[i][q] % MOD * b[q][j] % MOD) % MOD);
                temp %= MOD;
            }
            dst[i][j] = temp;
        }
    }
}
void copy(long long dst[23][23], long long source[23][23], int k)
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dst[i][j] = source[i][j];
        }
    }
}
void asd(long long n, long long temp[23][23], long long k)
{
    long long now = 1;
    while (now <= n)
    {
        int t = n & now;
        if (t)
        {
            multipy(temp, ans, mat, k);
            copy(ans, temp, k);
        }
        now <<= 1;
        multipy(temp, mat, mat, k);
        copy(mat, temp, k);
    }
}
int main()
{
    long long k, n;
    scanf("%lld%lld", &k, &n);
    n = n - k;
    long long a[23], c[23];
    long long temp[23][23];
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%lld", &c[i]);
    }
    for (int i = 0; i < k; i++)
    {
        ans[i][i] = 1;
        mat[0][i] = c[i];
        mat[i + 1][i] = 1;
    }
    asd(n, temp, k);
    long long ret = 0;
    for (int i = 0; i < k; i++)
    {
        ret += ((a[k - i - 1] % MOD) * (ans[0][i] % MOD)) % MOD;
        ret = ret % MOD;
    }
    printf("%lld", ret);
    return 0;
}
/*背景故事
出题人遇到了被偷了徽章的艾米莉亚，他们一起寻找徽章，最后锁定在一家赃物店里，却没有想到，两人相继进店，相继被杀。

出题人发现自己拥有死亡回归的能力，读档复活了。出题人又遇见了艾米莉亚，然而艾米莉亚却一副不认识出题人的样子，出题人一脸茫然。

不知所措的出题人决定先去店里赎回徽章。来到店里，这里只有罗姆老爷爷，和一个小女孩。

罗姆：“你拿什么来赎？”

题目描述
出题人：“当当当当！看这个手机，它有很神奇的能力，它能算递推数列哦！”

罗姆：“递推数列？这个老夫也会，老夫识得斐波那契数列，就是 f1=1, f2=1, fn=fn−1+fn−2，这个数列是 1,1,2,3,5,8,13⋯”

出题人：“很好。常系数齐次线性递推就是一种扩展，定义 f1=a1, f2=a2,⋯,fk=ak，当 n>k 时，有 fn=c1fn−1+c2fn−2+⋯+ckfn−k。

“比如，令 k=2, a1=a2=c1=c2=1，那么它就成了斐波那契数列。

“现在给你 a1,⋯,ak 这 k 个初始项、c1,⋯,ck 这 k 个递推系数，以及 n，你能求出 fn 吗？注意 n 很大哟~你不会了吧~”

罗姆：“这。。老夫还真不会，你这破盒子就能算对了？”

你作为出题人手机这个程序的编写者，是时候向罗姆爷展现你的能力了！

由于答案可能很大，你只需要输出答案对 109+7 取模。易证，对于乘法运算：(a×b)modp=((amodp)×(bmodp))modp，对于加法运算：(a+b)modp=((amodp)+(bmodp))modp。即，对于你的程序中跟答案直接相关的加法和乘法运算，每次运算完之后都对 109+7 取模，这样就不会溢出 long long 了。

本题附有提示，但在阅读提示前请务必进行充分的独立思考，否则对你的学习能力提升没有意义。

输入格式
第一行两个正整数 k,n。（1≤k≤20，k≤n≤1018）

第二行 k 个整数，表示 a1,⋯,ak。

第三行 k 个整数，表示 c1,⋯,ck。（1≤ai,ci≤109）

输出格式
一行，一个整数，表示 fn 对 109+7 取模。

样例输入1
2 6

1 1

1 1

样例输出1
8

样例输入2
3 6

1 2 3

3 2 1

样例输出2
181

提示1
聪明的你一定学过线性代数，我们来简单应用一下。

考虑斐波那契数列 fn=fn−1+fn−2，我们构造一个向量 v⃗ =[fn−1fn−2]，把它乘一个矩阵 A=[1110]，会得到什么呢？
Av⃗ =[1110][fn−1fn−2]=[fn−1+fn−2fn−1]=[fnfn−1]
会发现 f 的下标往前推进了一位！这就产生了递推！

聪明的你一定想到了扩展到常系数齐次线性递推要怎么做。

提示2
给定 x,y，而 y 很大，要怎么求 xy 呢？

如果 y 是偶数，你可以先求 xy2，然后给它平方一下；

如果 y 是奇数，你可以先求 xy−12，然后给它平方一下，然后再乘个 x。

聪明的你一定知道这样做的时间复杂度是多少。

提示3
离散课本里好像还给出了一种直接解特征方程的方法呢！哪个方法比较好呢？课本里的方法能不能用在这个题里呢？两种方法有什么联系呢？能不能互相推导出来呢？

聪明的你一定被激发了学习的热情！

*/