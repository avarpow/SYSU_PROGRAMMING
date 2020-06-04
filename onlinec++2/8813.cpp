#include <iostream>
int main()
{
    int sum = 15, t;
    for (int i = 0; i < 4; i++)
    {
        std::cin >> t;
        sum -= t;
    }
    std::cout << sum;
    return 0;
}
/*
Week2 The missing number 实时评测
 2020-04-18 19:40
 1000 ms
 32 MB
 周玉飞 (18340232)
Description
There are five numbers 1,2,3,4 and 5,now you can see four of them,do you know what is the remaining one?

Input
Four different integers in range 1 to 5.

Output
One line,the missing number.

Sample Input
2 4 1 5

Sample Output
3
*/