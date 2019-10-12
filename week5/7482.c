/*
Description
Given two integers representing a year and a month, could you tell me how many days there are in a month?

If the input is valid, you should output in the format xxxx/xx has xx days. where each x represents one digit.

Valid input requires:

0≤year≤9999
1≤month≤12
Otherwise, simply output Invalid Input Detected.

Check out the following samples for more information.

A newline \n is expected after the output.
*/
#include <stdio.h>
int main()
{
    int y, m,md=0,temp,flag = 0;
    scanf("%d %d", &y,&m);
    (y >= 0 && y <= 9999 && m >= 1 && m <= 12) ? printf("%04d/%02d has %d days.\n", y, m, m == 2 ? ((y % 100==0 ? (y % 400==0 ? 1 : 0 ): (y % 4==0 ? 1 : 0)) == 1 ? 29 : 28) : ((m * 2 - 15) > 0 ? (m * 2 - 15) : (15 - m * 2)) % 4 == 1 ? 31 : 30) : printf("Invalid Input Detected.\n");
}