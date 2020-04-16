//100分版本
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define AC 1
#define UNAC 0;
struct node
{
    int cid;
    int solve_methods;
    struct node *next;
};
struct list
{
    int sizes; //这场比赛有sizes个人ac了这道题
    struct node *head;
    struct node *curr;
};
int vis[51][5001] = {0};               //cid,uid
struct list problem[5001][5001] = {0}; //uid,pid
struct contest
{
    int solnum[5001], sum[50], allsum; //solnum i个人过题目数量
} contests[51];
struct submission
{
    int sid, cid, pid, uid, result;
} submissions[300005];
void init() { memset(contests, 0, sizeof(contests)); };
void init_contest(int cid, int t)
{
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &t);
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
    //user_num = contests[cid].user_num;
    //exist = -1;
    //for (int i = 0; i < user_num; i++) {
    //    if ((contests[cid].users)[i].uid == uid) {
    //        exist = i;
    //        break;
    //    }
    //}
    if (vis[cid][uid] != 0)
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
            //problems_position = -1;
            //solved_problems_num = (contests[cid].users)[exist].solve_num;
            //for (int i = 0; i < solved_problems_num; i++) {
            //    if ((contests[cid].users)[exist].solved_problems[i].pid == pid) {
            //        problems_position = i;
            //        break;
            //    }
            //}
            struct node *temp = problem[uid][pid].head;
            int flag = 0;
            for (int i = 0; temp != NULL; i++)
            {
                if (temp->cid == cid)
                {
                    flag = 1;
                    break;
                }
                temp = temp->next;
            }
            if (flag == 1)
            { //这题ac过
                temp->solve_methods++;
            }
            else
            { //这题没ac过
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->next = NULL;
                newnode->cid = cid;
                newnode->solve_methods = 1;
                if (problem[uid][pid].sizes == 0)
                {
                    problem[uid][pid].head = newnode;
                    problem[uid][pid].curr = newnode;
                }
                else
                {
                    problem[uid][pid].curr->next = newnode;
                    problem[uid][pid].curr = newnode;
                }
                problem[uid][pid].sizes++;
                int k = contests[cid].solnum[uid]++;
                contests[cid].sum[k]--;
                contests[cid].sum[k + 1]++;
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
        vis[cid][uid] = 1;
        contests[cid].allsum++;
        if (submissions[sid].result == AC)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->next = NULL;
            newnode->cid = cid;
            newnode->solve_methods = 1;
            if (problem[uid][pid].sizes == 0)
            {
                problem[uid][pid].head = newnode;
                problem[uid][pid].curr = newnode;
            }
            else
            {
                problem[uid][pid].curr->next = newnode;
                problem[uid][pid].curr = newnode;
            }
            problem[uid][pid].sizes++;
            contests[cid].solnum[uid] = 1;
            contests[cid].sum[1]++;
        }
        else
        {
            contests[cid].sum[0]++;
            contests[cid].solnum[uid] = 0;
        }
    }
}
void getRank_hander()
{
    int cid, uid, ans, user_solved_num, contest_people_num;
    ans = 0;
    scanf("%d%d", &cid, &uid);
    contest_people_num = contests[cid].allsum;
    user_solved_num = contests[cid].solnum[uid];
    for (int j = 0; j < user_solved_num; j++)
    {
        ans += contests[cid].sum[j];
    }
    printf("%d %d %d %d\n", uid, user_solved_num, contest_people_num - ans - contests[cid].sum[user_solved_num] + 1, contest_people_num - ans);
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
        contests_people_num = contests[cid].allsum;
        struct node *temp = problem[uid][pid].head;
        for (int i = 0; temp != NULL; i++)
        {
            if (temp->cid == cid)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
        }
        else if (temp->solve_methods > 1)
        {
            temp->solve_methods--;
        }
        else
        {
            problem[uid][pid].sizes--;
            contests[cid].solnum[uid]--;
            if (temp == problem[uid][pid].head)
            {
                problem[uid][pid].head = temp->next;
                free(temp);
            }
            else
            {
                struct node *last = problem[uid][pid].head;
                while (last->next != temp)
                {
                    last = last->next;
                }
                last->next = temp->next;
                if (last->next == NULL)
                {
                    problem[uid][pid].curr = last;
                }
                free(temp);
            }
            int k = contests[cid].solnum[uid];
            contests[cid].sum[k]++;
            contests[cid].sum[k + 1]--;
        }
    }
}
int main()
{
    clock_t begin, end;
    double cost;
    //开始记录
    begin = clock();
    int pcnt, ucnt, m;
    char order[20];
    int cid, t;
    //freopen("in1", "r", stdin);
    //freopen("myout1", "w", stdout);
    init();
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
    struct node *temp, nex;
    for (int i = 0; i < 5001; i++)
    {
        for (int j = 0; j < 5001; j++)
        {
            struct node *temp = problem[i][j].head;
            if (temp != NULL)
            {
                struct node *nex = temp->next;
                while (nex != NULL)
                {
                    free(temp);
                    temp = nex;
                    nex = nex->next;
                }
                free(temp);
            }
        }
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
    return 0;
}