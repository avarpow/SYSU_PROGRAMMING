/*
Description
Alice想给Bob发信息，他们约定了一种加密方式，规则如下：

假如 Bob 收到这样一个字符矩阵:

anml
bopk
cfuc
他会按逆时针方向读取这个矩阵，得到一个解码后的字符串

abcfucklmnop
不幸的是，当Bob想将解码后的信息发送给Ｔom时，却发现有些信息不完整，这是由于信息中含有敏感词, 这些敏感词会被和谐掉

比如上面例子，fuck是一个敏感词，所以当Tom收到信息时，会看到下面这样

abcf***lmnop
当有多个敏感词重叠时，只和谐第一个。例如，假设fuck和kill都是敏感词，则 abcfuckill　会被和谐成　abcf***ill
当多个敏感词有相同的前缀时，优先和谐那个在输入时顺序靠前的敏感词。例如，按顺序输入了两个敏感词 kill 和 killing，则 abckillingxyz 会被和谐成 abck***ingxyz
现在给你Bob收到的字符矩阵，输出Bob解码后的字符串和Tom看到的信息内容

Input
第一行：两个整数，0 < m < 50, 0 < n < 50，代表矩阵的高度和宽度

接下来ｍ行是字符矩阵

接着是一个整数 t, 0 < t < 10, 代表敏感词个数

接下来ｔ行，每行一个敏感词，敏感词的长度小于 50

Output
输出两行，分别是Bob解码后的字符串和Tom看到的字符串

Sample Input
3 4
anml
bopk
cfuc
1
fuck
Sample Output
abcfucklmnop
abcf***lmnop
*/
#include<stdio.h>
#include<string.h>
char s[55][55],pre[2502],post[2945],ci[12][30],vis[55][55]={0};
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int n, m,p;
char read(){
    char t=getchar();
    while (!((t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z')))
    {
        t = getchar();
    }
    return t;
}
int pi(int i,int j){
    int len = strlen(ci[j]);
    if(i+len-1<n*m){
        int flag = 1;
        for (int k = 0; k < len;k++){
            if(post[i+k]!=ci[j][k]){
                flag = 0;
                break;
            }
        }
        return flag;
    }
    else{
        return 0;
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            s[i][j] = read();
        }
    }
    scanf("%d", &p);
    for (int i = 0; i < p;i++){
        scanf("%s", ci[i]);
    }
    int dirs = 0, count = 0,x=0,y=0;
    while(count<m*n){
        pre[count++] = s[x][y];
        vis[x][y] = 1;
        if(x+dir[dirs][0]>=0 && x+dir[dirs][0]<n && y+dir[dirs][1]>=0 && y+dir[dirs][1]<m && vis[x+dir[dirs][0]][y + dir[dirs][1]]==0){
            x = x + dir[dirs][0];
            y = y + dir[dirs][1];
        }
        else{
            dirs++;
            if(dirs==4)
                dirs = 0;
            x = x + dir[dirs][0];
            y = y + dir[dirs][1];
        }
    }
    strcpy(post, pre);
    for (int i = 0; i < n * m;i++){
        for (int j = 0; j < 10;j++){
            if(pi(i,j)){
                int len = strlen(ci[j]);
                for (int k = 0; k < len-1;k++){
                    post[i + 1 + k] = '*';
                }
            }
        }
    }
    printf("%s\n%s\n", pre, post);
    return 0;
}