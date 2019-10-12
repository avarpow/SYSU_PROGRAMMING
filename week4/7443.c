/*
Description
In one week an employee works h hours (h is an integer and 0<h<168) at the hourly pay rate of 24.75 dollar. Assume a 40.0 hour normal work week and an overtime pay rate factor of 1.5.
What are the employee’s wages?
*/
#include <stdio.h>
int main(){
    int hours=0;
    scanf("%d",&hours);
    printf("%.2f\n", 24.75 * hours + (hours > 40 ? 0.5f*24.75*(hours-40):0.0));
}