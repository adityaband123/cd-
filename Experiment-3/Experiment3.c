// Write a C program to recognize strings under "a*", "a*b+", "abb"

// * -> 0+
// + -> 1+

#include <stdio.h>

int main() {

    char s[20];

    printf("Enter a text : ");
    gets(s);

    int state = 0;

    for (int i = 0; s[i]; ++i) {
    
        switch (state) {
            
            case 0:
                if (s[i] == 'a') {
                    state = 1;
                } else if (s[i] == 'b') {
                    state = 3;
                } else {
                    state = 4;
                }
                break;

            case 1:
                if (s[i] == 'a') {
                    state = 1;
                } else if (s[i] == 'b') {
                    state = 2;
                } else {
                    state = 4;
                }
                break;

            case 2:
                if (s[i] == 'a') {
                    state = 4;
                } else if (s[i] == 'b') {
                    state = 3;
                } else {
                    state = 4;
                }
                break;

            case 3:
                if (s[i] == 'a') {
                    state = 4;
                } else if (s[i] == 'b') {
                    state = 3;
                } else {
                    state = 4;
                }
                break;

            case 4:
                break;
        }

    }

    if (state == 4) {
        printf("\"%s\" cannot be recognized.", s);    
    } else {
        printf("\"%s\" can be recognized.", s);
    }

    return 0;
}

/*
C:\> gcc -o Experiment3 Experiment3.c

C:\>Experiment3.exe
Enter a text :  
"" can be recognized.

C:\>Experiment3.exe
Enter a text : a
"a" can be recognized.

C:\>Experiment3.exe
Enter a text : aaa
"aaa" can be recognized.

C:\>Experiment3.exe
Enter a text : b
"b" can be recognized.

C:\>Experiment3.exe
Enter a text : bbbbb
"bbbbb" can be recognized.

C:\>Experiment3.exe
Enter a text : aaab
"aaab" can be recognized.

C:\>Experiment3.exe
Enter a text : abb
"abb" can be recognized.

C:\>Experiment3.exe
Enter a text : ba
"ba" cannot be recognized.

C:\>Experiment3.exe
Enter a text : abc
"abc" cannot be recognized.
*/