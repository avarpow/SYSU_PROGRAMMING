/*
Description
Given two n*n matrices, A and B, computes its matrices multiplication C=A∙B.

Input
There are multiples test cases. Each case is:
The first line is an integer n(<=10), meaning the size of the matrix. For the following 2*n lines, each line contains n integers. The first n lines contain the elements in matrix A.

Input is terminated by EOF.

Output
For each test case, output:
The multiplication C= A∙B, there will be n lines and each line contains n integers, separating the integers by a space.

Sample Input
2
1 2
3 4
1 1
1 1
Sample Output
3 3
7 7
Hint
//To process multiple cases, you can use some C++ codes like:
//original codes:
//cin >> a >> b;
//cout << a + b << endl;
while(cin >> a){
    cin >> b;
    cout << a + b << endl;
}

//or use some C codes like:
//original codes:
//scanf("%d%d", &a, &b);
//printf("%d\n", a + b);
while(scanf("%d", &a) != EOF){
    scanf("%d", &b);
    printf("%d\n", a + b);
}
*/
#include<stdio.h>
int m1[14][24],m2[24][42],ans[21][23],n;
int main(){
    while(scanf("%d",&n)!=EOF){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                scanf("%d", &m1[i][j]);
            }
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                scanf("%d", &m2[i][j]);
            }
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                int sum = 0;
                for (int k = 0; k < n;k++){
                    sum += m1[i][k] * m2[k][j];
                }
                ans[i][j] = sum;
            }
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }        
    }
}