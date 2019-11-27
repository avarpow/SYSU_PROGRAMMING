#include "stdio.h"
int fibonacci(int n);
int main(){
	int n ;
	scanf("%d", &n);
	int f = fibonacci(n);
	printf("%d\n", f);
	return 0;
}
int fibonacci(int n){
    static int s[200] = {0, 1, 3};
    if(n<=0)
        return 0;
    else{
        if(s[n])
            return s[n];
        else{
            s[n]=fibonacci(n-1)+fibonacci(n-2)+1;
            return s[n];
        }
    }
}

