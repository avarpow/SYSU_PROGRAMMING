/*
Description
Write a function to check whether string s1 is a substring of string s2. The function returns the first index in s2 if there is a match. Otherwise, return -1. The function header is:

int indexOf(const char *s1, const char *s2)

Hint
Don't submit the main() function.
*/
#include <stdio.h>
#include <string.h>
int indexOf(const char *s1, const char *s2){
    int len_s1=strlen(s1);
    int len_s2 = strlen(s2);
    for (int i = 0; i + len_s1 <= len_s2;i++){
        int flag = 0;
        for (int j = 0; j < len_s1;j++){
            if(s1[j]!=s2[i+j]){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    return -1;
}
int main()
{
  int t;
  scanf("%d", &t);

  char s[80];
  gets(s);

  while(t--)
  {
    // Prompt the user to enter a string
    printf("Enter the first string: ");
    char s1[80];
    gets(s1);
    // Prompt the user to enter a string
    printf("Enter the second string: ");
    char s2[80];
    gets(s2);
    printf("%d\n", indexOf(s1, s2));
  }
  return 0;
}
