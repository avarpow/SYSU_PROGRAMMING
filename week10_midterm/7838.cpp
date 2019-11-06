/*
Input a string of length 30(including letters and numbers), your task is to keep letters only and convert them into uppercase ones Hint: keep letters only, and convert lowercase letters to uppercase ones

EXAMPLE INPUT 1
j34h13g4lhAg3gD1G3gS1h3g45qwe1

EXAMPLE OUTPUT 1
JHGLHAGGDGGSHGQWE

EXAMPLE INPUT 2
J4H3aJ7Jdf9aJG4hf5hKn2Vgthst4T

EXAMPLE OUTPUT 2
JHAJJDFAJGHFHKNVGTHSTT
*/
#include<stdio.h>
int a[100][100]={0};
int main()
{
    char n;
    while((n=getchar())!=EOF){
        if(n>='a' && n<='z')
            n = n - 'a' + 'A';
        if(n>='A' && n<='Z')
            printf("%c", n);
    }
    printf("\n");
    return 0;
}