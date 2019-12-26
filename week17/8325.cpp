/*
成绩排序[结构体的使用]
建立一个结构体，读入并保存 n 个学生的考试信息，每个学生的信息包括学号，姓名和考试分数。然后对学生的分数进行排序(由高到低)，若分数相同则按学号排序（由小到大）。最后按照“学号 姓名 成绩”的格式逐行打印成绩表（可参考Sample Input和Sample Output）。

Sample Input
4

1 a 90

2 b 80

3 c 90

4 d 100

Sample Output
4 d 100

1 a 90

3 c 90

2 b 80

注意：
1、学号的范围是1-- n 且 n < 100；

2、学生的姓名由一个字母字符串表示（长度不大于10）；

3、分数约定为0--100的整数；

4、存储结构可自由选择；

5、输出的每一行最后都带换行符。
*/
#include<stdio.h>
struct stu{
    int id, score;
    char name[10];
};
int cmpp(struct stu a,struct stu b){
    if(a.score!=b.score){
        return a.score < b.score;
    }
    else{
        return a.id > b.id;
    }
}
int main(){
    int n;
    struct stu s[100];
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d%s%d", &s[i].id, s[i].name, &s[i].score);
    }
    for (int i = n - 2; i >= 0;i--){
        for (int j = 0; j <= i;j++){
            if(cmpp(s[j],s[j+1])>0){
                struct stu t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
    for (int i = 0; i < n;i++){
        printf("%d %s %d\n", s[i].id, s[i].name, s[i].score);
    }
    return 0;
}