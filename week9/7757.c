/*
Description
Write a program that prints the characters in the ASCII character table from '!' to '~' (including '~').

Input
a number n (3 <= n <= 15)

Output
Print n characters per line and specify the width of each character's print field to 2, and justify the output to right.

The characters in one line are separated by a space and there is no space at the end of the line.

Sample Input
10
Sample Output
 !  "  #  $  %  &  '  (  )  *
 +  ,  -  .  /  0  1  2  3  4
 5  6  7  8  9  :  ;  <  =  >
 ?  @  A  B  C  D  E  F  G  H
 I  J  K  L  M  N  O  P  Q  R
 S  T  U  V  W  X  Y  Z  [  \
 ]  ^  _  `  a  b  c  d  e  f
 g  h  i  j  k  l  m  n  o  p
 q  r  s  t  u  v  w  x  y  z
 {  |  }  ~
 */
#include<stdio.h>
int main()
{
    int n,c=0;
    scanf("%d", &n);
    for (int i = '!'; i <= '~';i++,c++){
        printf("%s%c%s%s",c%n==0?" ":"  ", i, c % n == n - 1 ? "\n" : "",(i==126) && (c%n != n-1)?"\n":"");
    }
}