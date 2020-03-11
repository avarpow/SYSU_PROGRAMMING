#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int *problems;
    int *rank_list;
    int user_num;
    struct user users[5005];
} contests[12];
struct submission
{
    int sid, cid, pid, uid, result;
} submissions[300005];
void init_contest(int cid, int t)
{
    contests[cid].problem_num = t;
    contests[cid].problems = (int *)malloc(sizeof(int) * t);
    contests[cid].rank_list = (int *)calloc(t, sizeof(int));
    contests[cid].user_num = 0;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", contests[cid].problems + i);
    }
}
void submission_hander()
{
    int cid, pid, uid, sid, user_num, exist, solved_problems_num, problems_position;
    char result[10];
    scanf("%d%d%d%d%s", &sid, &cid, &pid, &uid, result);
    submissions[sid].sid = sid;
    submissions[sid].cid = cid;
    submissions[sid].pid = pid;
    submissions[sid].uid = uid;
    submissions[sid].result = result[0] == 'A' ? AC : UNAC;
    user_num = contests[cid].user_num;
    exist = -1;
    for (int i = 0; i < user_num; i++)
    {
        if ((contests[cid].users)[i].uid == uid)
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
            solved_problems_num = (contests[cid].users)[exist].solve_num;
            for (int i = 0; i < solved_problems_num; i++)
            {
                if ((contests[cid].users)[exist].solved_problems[i].pid == pid)
                {
                    problems_position = i;
                    break;
                }
            }
            if (problems_position != -1)
            { //这题ac过
                (contests[cid].users)[exist].solved_problems[problems_position].methods++;
            }
            else
            { //这题没ac过
                (contests[cid].users)[exist].solved_problems[(contests[cid].users)[exist].solve_num].pid = pid;
                (contests[cid].users)[exist].solved_problems[(contests[cid].users)[exist].solve_num].methods = 1;
                contests[cid].rank_list[(contests[cid].users)[exist].solve_num]--;
                contests[cid].rank_list[(contests[cid].users)[exist].solve_num + 1]++;
                (contests[cid].users)[exist].solve_num++;
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
        (contests[cid].users)[contests[cid].user_num].uid = uid;
        contests[cid].rank_list[0]++;
        if (submissions[sid].result == AC)
        {
            (contests[cid].users)[contests[cid].user_num].solved_problems[(contests[cid].users)[contests[cid].user_num].solve_num].pid = pid;
            (contests[cid].users)[contests[cid].user_num].solved_problems[(contests[cid].users)[contests[cid].user_num].solve_num].methods = 1;
            (contests[cid].users)[contests[cid].user_num].solve_num = 1;
            contests[cid].rank_list[0]--;
            contests[cid].rank_list[1]++;
        }
        else
        {
            (contests[cid].users)[contests[cid].user_num].solve_num = 0;
        }
        contests[cid].user_num++;
    }
}
void getRank_hander()
{
    int cid, uid, ans, user_solved_num, contest_people_num;
    ans = 0;
    scanf("%d%d", &cid, &uid);
    contest_people_num = contests[cid].user_num;
    for (int i = 0; i < contest_people_num; i++)
    {
        if (contests[cid].users[i].uid == uid)
        {
            user_solved_num = contests[cid].users[i].solve_num;
            for (int j = 0; j < user_solved_num; j++)
            {
                ans += contests[cid].rank_list[j];
            }
            printf("%d %d %d %d\n", uid, user_solved_num, contests[cid].user_num - ans - contests[cid].rank_list[user_solved_num] + 1, contests[cid].user_num - ans);
        }
    }
}
void rejudge_hander()
{
    int sid, cid, uid, pid, contests_people_num, problem_num;
    scanf("%d", &sid);
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
        cid = submissions[sid].cid;
        pid = submissions[sid].pid;
        uid = submissions[sid].uid;
        contests_people_num = contests[cid].user_num;
        for (int i = 0; i < contests_people_num; i++)
        {
            if ((contests[cid].users)[i].uid == uid)
            {
                problem_num = contests[cid].users[i].solve_num;
                for (int j = 0; j < problem_num; j++)
                {
                    if (contests[cid].users[i].solved_problems[j].pid == pid)
                    {
                        if (contests[cid].users[i].solved_problems[j].methods > 1)
                        {
                            contests[cid].users[i].solved_problems[j].methods--;
                        }
                        else
                        {
                            contests[cid].users[i].solved_problems[j] = contests[cid].users[i].solved_problems[problem_num - 1];
                            contests[cid].users[i].solve_num--;
                            contests[cid].rank_list[problem_num]--;
                            contests[cid].rank_list[problem_num - 1]++;
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int pcnt, ucnt, m;
    char order[20];
    int cid, t;
    scanf("%d%d%d", &pcnt, &ucnt, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", order);
        if (order[0] == 'c')
        {
            scanf("%d%d", &cid, &t);
            init_contest(cid, t);
        }
        else if (order[0] == 's')
        {
            submission_hander();
        }
        else if (order[0] == 'g')
        {
            getRank_hander();
        }
        else if (order[0] == 'r')
        {
            rejudge_hander();
        }
    }
    return 0;
}