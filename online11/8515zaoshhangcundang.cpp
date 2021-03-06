#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define AC 1
#define UNAC 0;
struct solved_problem {
    int pid, methods;
};
struct user {
    int uid;
    int solve_num;
    struct solved_problem solved_problems[1005];
};
struct contest {
    int problem_num;
    int rank_list[1005];
    int user_num;
    struct user users[5005];
} contests[1];
struct submission {
    int sid, cid, pid, uid, result;
} submissions[300005];
int result[300000][4] = {0};
int readint()
{
    char c = getchar();
    while (!(c <= '0' && c >= '9'))
        c = getchar();
    int x = 0;
    while (c <= '0' && c >= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int buf[10];
void writeint(int i)
{
    int p = 0;
    if (i == 0)
        p++;
    else
        while (i) {
            buf[p++] = i % 10;
            i /= 10;
        }
    for (int j = p - 1; j >= 0; j--)
        putchar('0' + buf[j]);
}
                                                                                                                                                    void init_contest(int t)
{
    contests[0].problem_num = t;
    contests[0].user_num = 0;
    memset(contests[0].rank_list,0,sizeof(contests[0].rank_list));
    for (int i = 0; i <= 5000; i++) {
        contests[0].users[i].solve_num = 0;
	}
}
void submission_hander(int sid)
{
    int user_num, exist,solved_problems_num,problems_position;
    user_num = contests[0].user_num;
    exist = -1;
    for (int i = 0; i < user_num; i++) {
        if ((contests[0].users)[i].uid == submissions[sid].uid) {
            exist = i;
            break;
        }
    }
    if (exist != -1) {
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
        if (submissions[sid].result == AC) {
            problems_position = -1;
            solved_problems_num = (contests[0].users)[exist].solve_num;
            for (int i = 0; i < solved_problems_num; i++) {
                if ((contests[0].users)[exist].solved_problems[i].pid == submissions[sid].pid) {
                    problems_position = i;
                    break;
				}
			}
            if (problems_position != -1) {//这题ac过
				(contests[0].users)[exist].solved_problems[problems_position].methods++;
            } else {//这题没ac过
                (contests[0].users)[exist].solved_problems[(contests[0].users)[exist].solve_num].pid = submissions[sid].pid;
                (contests[0].users)[exist].solved_problems[(contests[0].users)[exist].solve_num].methods = 1;
                contests[0].rank_list[(contests[0].users)[exist].solve_num]--;
                contests[0].rank_list[(contests[0].users)[exist].solve_num+1]++;
                (contests[0].users)[exist].solve_num++;
			}
        } 
    } else {
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
        if (submissions[sid].result == AC) {
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
void getRank_hander(int index,int uid) {
    int ans,user_solved_num,contest_people_num;
    ans = 0;
    contest_people_num = contests[0].user_num;
    for (int i = 0; i < contest_people_num; i++) {
        if (contests[0].users[i].uid == uid) {
            user_solved_num = contests[0].users[i].solve_num;
            for (int j = 0; j < user_solved_num; j++) {
                ans += contests[0].rank_list[j];
			}
            result[index][0] = uid;
            result[index][1] = user_solved_num;
            result[index][2] = contests[0].user_num - ans - contests[0].rank_list[user_solved_num] + 1;
            result[index][3] = contests[0].user_num - ans;
		}
	}
}
void rejudge_hander(int sid) {
    int contests_people_num,problem_num;
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
    if (submissions[sid].result == AC) {
        contests_people_num = contests[0].user_num;
        for (int i = 0; i < contests_people_num; i++) {
            if ((contests[0].users)[i].uid == submissions[sid].uid) {
                problem_num = contests[0].users[i].solve_num;
                for (int j = 0; j < problem_num; j++) {
                    if (contests[0].users[i].solved_problems[j].pid == submissions[sid].pid) {
                        if (contests[0].users[i].solved_problems[j].methods > 1) {
                            contests[0].users[i].solved_problems[j].methods--;
                        } else {
                            contests[0].users[i].solved_problems[j] = contests[0].users[i].solved_problems[problem_num-1];
                            contests[0].users[i].solve_num--;
                            contests[0].rank_list[problem_num]--;
                            contests[0].rank_list[problem_num-1]++;
						}
					}
				}
			}
		}
	}
    submissions[sid].result = UNAC;
}
struct input {
    char order[20],result[6];
    int uid, sid, pid, cid,t;
} inputs[300000];
int main()
{
    clock_t begin, end;
    double cost;
    //开始记录
    begin = clock();
	
    int pcnt, ucnt, m;
    char gar=0;
    int all=0;
    freopen("in1", "r", stdin);
    freopen("myout1", "w", stdout);
    //pcnt = readint();
    //ucnt = readint();
    //m = readint();
	scanf("%d%d%d", &pcnt, &ucnt, &m);
    for (int i = 0; i < m; i++) {
            if (i % 50000==0) {
            end = clock();
            cost = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs\n", CLOCKS_PER_SEC, cost);
			}
		scanf("%s", inputs[i].order);
        if (inputs[i].order[0] == 'c') {
            //inputs[i].cid = readint();
            //inputs[i].t = readint();
            scanf("%d%d", &inputs[i].cid, &inputs[i].t);
            while (gar != '\n')
                gar = getchar();
        } else if (inputs[i].order[0] == 's') {
            //inputs[i].sid = readint();
            //inputs[i].cid = readint();
            //inputs[i].pid = readint();
            //inputs[i].uid = readint();
            scanf("%d%d%d%d%s", &inputs[i].sid, &inputs[i].cid, &inputs[i].pid, &inputs[i].uid, inputs[i].result);
            //scanf("%s", inputs[i].result);
        } else if (inputs[i].order[0] == 'g') {
            //inputs[i].cid = readint();
            //inputs[i].uid = readint();
            scanf("%d%d", &inputs[i].cid, &inputs[i].uid);
            all++;
        } else if (inputs[i].order[0] == 'r') {
            //inputs[i].sid = readint();
            scanf("%d", &inputs[i].sid);
        }
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
    for (int i = 1; i < 50; i++) {
        int getindex = 0;
        for (int j = 0; j < m; j++) {
            if (inputs[j].order[0] == 'r' && submissions[inputs[j].sid].cid == i) {
                rejudge_hander(inputs[j].sid);
			} 
			else if (inputs[j].cid == i) {
                if (inputs[j].order[0] == 'c') {
                    init_contest(inputs[j].t);
				} 
				else if (inputs[j].order[0] == 's') {
                    submissions[inputs[j].sid].sid = inputs[j].sid;
                    submissions[inputs[j].sid].cid = inputs[j].cid;
                    submissions[inputs[j].sid].pid = inputs[j].pid;
                    submissions[inputs[j].sid].uid = inputs[j].uid;
                    submissions[inputs[j].sid].result = (inputs[j].result[0] == 'A') ? AC : UNAC;
                    submission_hander(inputs[j].sid);
				} 
				else if (inputs[j].order[0]=='g') {
                    getRank_hander(getindex, inputs[j].uid);
                 }
			}
			if (inputs[j].order[0] == 'g')
                getindex++;
		}
	}
    for (int i = 0; i < all; i++) {
		printf("%d %d %d %d\n", result[i][0], result[i][1], result[i][2], result[i][3]);
    }
    end = clock();
    cost = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
}    
