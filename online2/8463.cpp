#include <stdio.h>
#include <string.h>
int main()
{
    char s[400] = {0};
    char c[200] = {0};
    fgets(s, 400, stdin);
    scanf("%s", c);
    int len1 = strlen(s);
    int len2 = strlen(c);
    for (int i = 0; i < len1; i++)
    {
        char temp = s[i + len2];
        s[i + len2] = '\0';
        if (strcmp(s + i, c) == 0)
        {
            printf("%d ", i);
        }
        s[i + len2] = temp;
    }
}
/*
Description
Given a paragraph and a key word, try to find the key word in the paragraph and output the positions of the keyword in the paragraph.

Input format
The first line is a long string containing spaces, and its length is less than 300 characters. The second line is a key word whose length is less than 20.

Output format
Integers that indicate the key word positions in the long string. These integers are seperated by a space. New line is not needed at the end.

Example input
fkqy yqvnrtys zrmz gfveulqfp fkqy rwdnxeu qekla gdphcspi hbsfyf adzpbf kklrwq zmixrpi ffeclhbvf byeqfqojw osile fkqy bxq    
fkqy
Example output
0 29 112
*/