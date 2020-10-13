#include <iostream>
#include <queue>
using namespace std;
struct seg
{
    int prehead, preend, inhead, inend;
};
void solve(queue<seg> &q, string &pre, string &in, seg t)
{
    int seglen = t.prehead - t.preend;
    if (seglen == 0)
    {
        cout<<pre[t.prehead];//这段只有一个元素，直接输出
        return;
    }
    else
    {
        cout<<pre[t.prehead];//先输出这段的根节点
        int index = t.inhead;
        while (in[index] != pre[t.prehead])
            index++; //在中序历遍中找到根节点
        //cout << " index " << index << endl;
        seg temp;
        if (index == t.inhead)//只有右子树
        {
            temp.prehead = t.prehead + 1;
            temp.inhead = t.inhead+1;
            temp.inend = t.inend;
            temp.preend = t.preend;
            q.push(temp); //push右子树
        }
        else if (index == t.inend)//只有左子树
        {
            temp.prehead = t.prehead+1;
            temp.inhead = t.inhead;
            temp.inend = t.inend-1;
            temp.preend = t.preend;
            q.push(temp); //push右子树
        }
        else
        {
            temp.prehead = t.prehead + 1;
            temp.inhead = t.inhead;
            temp.inend = index - 1;
            temp.preend = temp.prehead + temp.inend - temp.inhead;
            q.push(temp); //push左子树

            temp.prehead = temp.preend + 1;
            temp.inhead = index + 1;
            temp.inend = t.inend;
            temp.preend = t.preend;
            q.push(temp);//push右子树
        }
    }
}
int main()
{
    string pre, in;
    cin >> pre;
    cin >> in;
    int len = pre.size();
    queue<seg> q;
    seg t;
    t.prehead = t.inhead = 0;
    t.preend = t.inend = len - 1;
    q.push(t);
    while (!q.empty())
    {
        seg f = q.front();
        // cout << " prehead " << f.prehead
        //      << " preend " << f.preend
        //      << " inhead " << f.inhead
        //      << " inend " << f.inend << endl;
        solve(q, pre, in, f);
        q.pop();
    }
    return 0;
}