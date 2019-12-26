/*
Description
From Wikipedia

Quicksort (sometimes called partition-exchange sort) is an efficient sorting algorithm, serving as a systematic method for placing the elements of an array in order. Developed by British computer scientist Tony Hoare in 1959 and published in 1961 it is still a commonly used algorithm for sorting. When implemented well, it can be about two or three times faster than its main competitors, merge sort and heapsort.

Input
In the first line, there is a number n (1⩽n⩽10000), which means the size of array. In the following line, there are n integers.

Output
The ascending order of the array.

Sample Input
2
2 1
Sample Output
1 2
Hint
https://en.wikipedia.org/wiki/Quicksort
*/
#include<stdio.h>
int a[20000];
  int n;

void swap(int l,int r){
    int t = a[l];
    a[l] = a[r];
    a[r] = t;
}
void quicksort(int left,int right){
    if(right-left<=0)
        return;
    else if(right-left==1){
        if(a[left]>a[right])
            swap(left, right);
    }
    int k = a[left],r=right,l=left;
    while(r!=l){
        while(a[r]>=k && r!=l)
            r--;
        a[l] = a[r];
        while(a[l]<=k && r!=l)
            l++;
        a[r] = a[l];
    }
    a[l] = k;
    quicksort(left, l - 1);

    quicksort(l + 1, right);

}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &a[i]);
    }
    quicksort(0, n-1);
    for (int i = 0; i < n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}