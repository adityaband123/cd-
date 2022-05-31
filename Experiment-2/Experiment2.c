// Write a C program to identify whether a given line is a comment or not.

#include <stdio.h>
#include <stdbool.h>

int main() {
    char text[30]; 
    bool is_comment = false;
    
    printf("Enter text : ");
    gets(text);

    if (text[0] == '/') {
        if (text[1] == '/') {
            is_comment = true;
        } else if (text[1] == '*') {
            for (int i = 3; i < 30; i++) {
                if (text[i - 1] == '*' && text[i] == '/') {
                    is_comment = true;
                    break;
                }        
            }
        }
    }
    
    if (is_comment) {
        printf("It is a comment.\n");
    } else {
        printf("It is not a comment.\n");
    }

    return 0;
}

/*
C:\> gcc -o Experiment2 Experiment2.c

C:\>Experiment2.exe
Enter text : // This is a function declaration
It is a comment.

C:\>Experiment2.exe
Enter text : int main() 
It is not a comment.
*/