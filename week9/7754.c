/*
Please complete the program according to the input and output examples.
Hint: keep letters only, and convert lowercase letters to uppercase ones

EXAMPLE INPUT 1
j34h13g4lhAg3gD1G3gS1h3g

EXAMPLE OUTPUT 1
JHGLHAGGDGGSHG

EXAMPLE INPUT 2
J4H3aJ7Jdf9aJG4hf5hKn2Vgthst4T2N45J

EXAMPLE OUTPUT 2
JHAJJDFAJGHFHKNVGTHSTTNJ
*/
#include<stdio.h>
void print_letters_in_uppercase()
{
    char t;
    while((t=getchar()) != EOF){
        if(t<='z'&&t>='a')
            t = t - 32;
        if(t<='Z'&&t>='A')
            printf("%c", t);
    }
    printf("\n");
}