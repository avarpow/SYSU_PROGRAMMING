/*
编写一个Catenate函数实现将两个int型数组拼接在一起并以指针形式返回新数组。

Catenate函数的原型为int* Catenate(int a[], int b[], int len1, int len2),其中a和b两个需要拼接的数组，len1是a中元素个数，len2是b中元素个数。返回一个int*型指针，指向一个数组，数组中前部分为a的内容，后部分为b的内容。

注意，只需要实现Catenate函数即可，main函数已经写好。详见Main.cpp文件。
*/
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int* Catenate(int a[], int b[], int len1, int len2){
    int *c=(int *)malloc(sizeof(int)*(len1+len2));
    memcpy(c, a, len1*sizeof(int));
    memcpy(c + len1, b, len2*sizeof(int));
    return c;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int *a = (int*)malloc(n * sizeof(int));
	int *b = (int*)malloc(m * sizeof(int));
	for(int i = 0; i < n; ++i) scanf("%d", a + i);
	for(int i = 0; i < m; ++i) scanf("%d", b + i);
	int *c = Catenate(a, b, n, m);
	free(a);
	free(b);
	n += m;
	for(int i = 0; i < n; ++i)
		printf("%d\r\n", c[i]);
	free(c);
	return 0;
}