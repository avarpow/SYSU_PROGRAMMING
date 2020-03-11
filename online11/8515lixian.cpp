//95分代码，未能通过内存检测.离线处理版本
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define AC 1
#define UNAC 0;
struct solved_problem
{
    int pid, methods;
};
struct user
{
    int uid;
    int solve_num;
    struct solved_problem solved_problems[1005];
};
struct contest
{
    int problem_num;
    int rank_list[1005];
    int user_num;
    struct user users[5005];
} contests[1];
struct submission
{
    int sid, cid, pid, uid, result;
} submissions[300005];
int result[300000][4] = {0};
void init_contest(int t)
{
    contests[0].problem_num = t;
    contests[0].user_num = 0;
    memset(contests[0].rank_list, 0, sizeof(contests[0].rank_list));
    for (int i = 0; i <= 5000; i++)
    {
        contests[0].users[i].solve_num = 0;
    }
}
void submission_hander(int sid)
{
    int user_num, exist, solved_problems_num, problems_position;
    user_num = contests[0].user_num;
    exist = -1;
    for (int i = 0; i < user_num; i++)
    {
        if ((contests[0].users)[i].uid == submissions[sid].uid)
        {
            exist = i;
            break;
        }
    }
    if (exist != -1)
    {
        /*
		这人参赛了
			ac
				这题ac过
					用户。解题方法【这个题位置】+1
				这题没ac过
					用户。解题【解题数量】=pid
					用户。解题方法【解题数量】=1
					比赛。分数排行榜【这个人分数-1】-1
					比赛。分数排行榜【这个人分数】+1
					用户。解题数量+1；
			unac
				donothing

		*/
        if (submissions[sid].result == AC)
        {
            problems_position = -1;
            solved_problems_num = (contests[0].users)[exist].solve_num;
            for (int i = 0; i < solved_problems_num; i++)
            {
                if ((contests[0].users)[exist].solved_problems[i].pid == submissions[sid].pid)
                {
                    problems_position = i;
                    break;
                }
            }
            if (problems_position != -1)
            { //这题ac过
                (contests[0].users)[exist].solved_problems[problems_position].methods++;
            }
            else
            { //这题没ac过
                (contests[0].users)[exist].solved_problems[(contests[0].users)[exist].solve_num].pid = submissions[sid].pid;
                (contests[0].users)[exist].solved_problems[(contests[0].users)[exist].solve_num].methods = 1;
                contests[0].rank_list[(contests[0].users)[exist].solve_num]--;
                contests[0].rank_list[(contests[0].users)[exist].solve_num + 1]++;
                (contests[0].users)[exist].solve_num++;
            }
        }
    }
    else
    {
        /*
		这人没参赛
			   ac
				比赛人数+1
				比赛【人数】=该用户uid
				用户。解题数量=1；
				用户。解题【解题数量】=pid
				用户。解题方法【解题数量】=1
				比赛。分数排行榜【1】+1
			Unac
				比赛人数+1
				比赛【人数-1】=该用户uid
				用户。解题数量=0；
				比赛。分数排行榜【0】+1
		*/
        (contests[0].users)[contests[0].user_num].uid = submissions[sid].uid;
        contests[0].rank_list[0]++;
        if (submissions[sid].result == AC)
        {
            (contests[0].users)[contests[0].user_num].solved_problems[(contests[0].users)[contests[0].user_num].solve_num].pid = submissions[sid].pid;
            (contests[0].users)[contests[0].user_num].solved_problems[(contests[0].users)[contests[0].user_num].solve_num].methods = 1;
            (contests[0].users)[contests[0].user_num].solve_num = 1;
            contests[0].rank_list[0]--;
            contests[0].rank_list[1]++;
        }
        else
        {
            (contests[0].users)[contests[0].user_num].solve_num = 0;
        }
        contests[0].user_num++;
    }
}
void getRank_hander(int index, int uid)
{
    int ans, user_solved_num, contest_people_num;
    ans = 0;
    contest_people_num = contests[0].user_num;
    for (int i = 0; i < contest_people_num; i++)
    {
        if (contests[0].users[i].uid == uid)
        {
            user_solved_num = contests[0].users[i].solve_num;
            for (int j = 0; j < user_solved_num; j++)
            {
                ans += contests[0].rank_list[j];
            }
            result[index][0] = uid;
            result[index][1] = user_solved_num;
            result[index][2] = contests[0].user_num - ans - contests[0].rank_list[user_solved_num] + 1;
            result[index][3] = contests[0].user_num - ans;
        }
    }
}
void rejudge_hander(int sid)
{
    int contests_people_num, problem_num;
    /*sid unac donothing
	ac
		找到用户
			找到用户这一题
				用户。这题。方法-1；
				方法=0
					交换这题与末尾
					用户。通过题目-1；
					比赛榜单【用户。通过数量】--
					比赛榜单【用户。通过数量-1】++

			
	*/
    if (submissions[sid].result == AC)
    {
        contests_people_num = contests[0].user_num;
        for (int i = 0; i < contests_people_num; i++)
        {
            if ((contests[0].users)[i].uid == submissions[sid].uid)
            {
                problem_num = contests[0].users[i].solve_num;
                for (int j = 0; j < problem_num; j++)
                {
                    if (contests[0].users[i].solved_problems[j].pid == submissions[sid].pid)
                    {
                        if (contests[0].users[i].solved_problems[j].methods > 1)
                        {
                            contests[0].users[i].solved_problems[j].methods--;
                        }
                        else
                        {
                            contests[0].users[i].solved_problems[j] = contests[0].users[i].solved_problems[problem_num - 1];
                            contests[0].users[i].solve_num--;
                            contests[0].rank_list[problem_num]--;
                            contests[0].rank_list[problem_num - 1]++;
                        }
                    }
                }
            }
        }
    }
    submissions[sid].result = UNAC;
}
struct input
{
    char order[20], result[6];
    int uid, sid, pid, cid, t;
} inputs[300000];
int main()
{
    int pcnt, ucnt, m, gar;
    int all = 0;
    freopen("in1", "r", stdin);
    freopen("myout1", "w", stdout);
    scanf("%d%d%d", &pcnt, &ucnt, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", inputs[i].order);
        if (inputs[i].order[0] == 'c')
        {
            scanf("%d%d", &inputs[i].cid, &inputs[i].t);
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &gar);
            }
        }
        else if (inputs[i].order[0] == 's')
        {
            scanf("%d%d%d%d%s", &inputs[i].sid, &inputs[i].cid, &inputs[i].pid, &inputs[i].uid, inputs[i].result);
        }
        else if (inputs[i].order[0] == 'g')
        {
            scanf("%d%d", &inputs[i].cid, &inputs[i].uid);
            all++;
        }
        else if (inputs[i].order[0] == 'r')
        {
            scanf("%d", &inputs[i].sid);
        }
    }
    for (int i = 1; i < 50; i++)
    {
        int getindex = 0;
        for (int j = 0; j < m; j++)
        {
            if (inputs[j].order[0] == 'r' && submissions[inputs[j].sid].cid == i)
            {
                rejudge_hander(inputs[j].sid);
            }
            else if (inputs[j].cid == i)
            {
                if (inputs[j].order[0] == 'c')
                {
                    init_contest(inputs[j].t);
                }
                else if (inputs[j].order[0] == 's')
                {
                    submissions[inputs[j].sid].sid = inputs[j].sid;
                    submissions[inputs[j].sid].cid = inputs[j].cid;
                    submissions[inputs[j].sid].pid = inputs[j].pid;
                    submissions[inputs[j].sid].uid = inputs[j].uid;
                    submissions[inputs[j].sid].result = (inputs[j].result[0] == 'A') ? AC : UNAC;
                    submission_hander(inputs[j].sid);
                }
                else if (inputs[j].order[0] == 'g')
                {
                    getRank_hander(getindex, inputs[j].uid);
                }
            }
            if (inputs[j].order[0] == 'g')
                getindex++;
        }
    }
    for (int i = 0; i < all; i++)
    {
        printf("%d %d %d %d\n", result[i][0], result[i][1], result[i][2], result[i][3]);
    }
}
/*
背景故事
后来，出题人通过死亡的经历，知道了猎肠者的阴谋，救下了艾米莉亚，艾米莉亚把出题人带回了宅邸，出题人留下成为了仆人。

出题人迫不及待地想跟艾米莉亚约会，但是发现女仆们都防着他，终有一天出题人约到了艾米莉亚，愉快的一天过后他竟然被杀死了。

出题人十分不解，又死了几次才终于明白了原因。原来，艾米莉亚努力考上了中山大学计算机系，每天都在刷程设题。而出题人只是中大的混混，女仆们怕艾米莉亚整天跟出题人玩会变得颓废，于是要把他清理掉。

不甘心的出题人决定教艾米莉亚学程设，证明自己是优秀的大学生。

题目描述
艾米莉亚利用课余时间刷了很多题目，但她是个很健忘的孩子，经常会忘记自己刷过一些什么题目，所以出题人想写一个 OJ 来帮她管理做过的题目。

经过一个星期的努力，出题人的 OJ 基本成型，只是还差一个 Contest 的模块没有实现。出题人觉得这个模块很难实现，所以他希望找你来帮忙。

一个OJ的基础元素包括：

1、题目，可以用pid唯一标识，pid为正整数。

2、比赛，可以用cid唯一标识，cid为正整数。

3、用户，可以用uid唯一标识，uid为正整数。

4、提交状态，可以由sid唯一标识，sid为正整数。一个提交状态是由sid, cid, pid, uid, result组成的，分别表示本条状态的提交ID，所属比赛ID，题目ID，用户ID以及评测结果。

简单起见，这里的result只有AC,UNAC,WAIT三种状态，分别表示通过，不通过，等待评测。

一个比赛模块需要实现以下请求：

createContest cid t pid _ 1 pid _ 2 … pid _ t
表示要创建一个比赛，cid是一个正整数，是这场比赛的唯一标识。

t表示这场比赛有t(1<=t<=1000)道题目，接下来t个不同的整数，表示这场比赛的题目编号。

submission sid cid pid uid result
该条状态的sid要么之前没出现过，要么以前出现过，但是被rejudge了。

result为AC或者UNAC。

getRank cid uid
在一场比赛中，所有有提交的用户都应该算在排名内(包括被rejudge的提交)，用户的排名按照通过的题目数从大到小排序，如果题目数相同，则按随机顺序排序。

该指令需要统计用户uid在cid这场比赛中的当前通过题目数，当前可能最高排名以及当前可能最低排名。

值得注意的是，用户uid在cid这场比赛中同一道题目的多个通过记录只算一次。

输出格式: uid solved highest lowest

分别代表用户ID，通过题目数量，最高排名以及最低排名，其中highest <= lowest。

rejudge sid
重测以sid标识的提交记录，即将该记录的result改成WAIT

输入格式
第一行三个整数pcnt, ucnt, m(1<=pcnt<=5000, 1<=ucnt<=5000, 1<=m<=300000)，分别表示OJ有pcnt道题目，ucnt个用户以及m条请求。

pid的范围是1000 ~ 1000 + pcnt - 1，uid的范围是1 ~ ucnt，cid的范围为1 ~ 50，1<=sid<=m。

接下来有m行，每行一个请求，请求为题述四种请求之一，请求是需要按输入顺序执行。

输入满足以下几点：

1、对于createContest请求，保证cid不会与之前的createContest的cid重复。

2、对于submission请求，在此请求前，保证比赛cid在已经创建，题目pid是该场比赛的题目之一。

3、对于getRank指令，在此请求前，保证比赛cid已经创建，用户uid至少在该比赛中有一个提交记录。

4、对于rejudge指令，在此请求前，保证存在以sid标识的提交。

输出格式
对于每一个getRank请求，根据要求输出用户ID，通过题目数量，最高排名以及最低排名，整数之间用一个空格隔开。

样例输入
7 5 17
createContest 1 5 1001 1004 1002 1005 1006
submission 1 1 1001 1 AC
submission 2 1 1001 1 AC
submission 3 1 1001 2 UNAC
submission 4 1 1004 3 UNAC
getRank 1 1
getRank 1 2
getRank 1 3
rejudge 3
submission 3 1 1001 2 AC
getRank 1 2
submission 5 1 1006 2 AC
getRank 1 1
submission 6 1 1006 2 UNAC
getRank 1 2
rejudge 5
getRank 1 2
样例输出
1 1 1 1
2 0 2 3
3 0 2 3
2 1 1 2
1 1 2 2
2 2 1 1
2 1 1 2
数据范围
1<=pcnt,ucnt<=5000, 1<=m<=300000, 1<=cid<=50
*/