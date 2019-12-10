#include "stdio.h"
int fib(int n);
int main(){
	int n ;
	scanf("%d", &n);
	int f = fib(n);
	printf("%d\n", f);
	return 0;
}
int fib(int n){
    static int s[45] = {0, 1, 1};
    if(n<=0)
        return 0;
    else{
        if(s[n])
            return s[n];
        else{
            s[n] = fib(n - 1) + fib(n - 2);
            return s[n];
        }
    }
}

