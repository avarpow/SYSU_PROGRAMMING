/*
Description
编写一个函数，返回整数数组中的最小值：

int smallestElement(int array[], int size)

Input
输入包括两行，第一行为数组长度，第二行为数组

Output
数组中的最小值

Sample Input
3
1 2 3
Sample Output
1
Hint
You should submit the implementation of the function but do not submit the main() function.
*/
#include <stdio.h>
int smallestElement(int array[], int size){
    int ans=array[0];
    for(int i=0;i<size;i++){
        ans=ans>array[i]?array[i]:ans;
    }
    return ans;
}
int main()
{
	int n;
	scanf("%d", &n);
	int list[n];
	for (int i = 0; i < n; i++) scanf("%d", &list[i]);
	printf("%d\n", smallestElement(list, n));

	return 0;
}
