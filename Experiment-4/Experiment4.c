// Write a C program to test whether a given identifier is valid or not.

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char s[50];
    printf("Enter identifier : ");
    gets(s);

    bool valid = false;
    if (isalpha(s[0]) || s[0] == '_') {
        valid = true;
        for (int i = 1; s[i]; ++i) {
            if (!isalnum(s[i]) && s[0] != '_') {
                valid = false;
                break;
            }
        }
    }

    if (valid) {
        printf("\"%s\" is a valid identifier", s);
    } else {
        printf("\"%s\" is not a valid identifier", s);
    }

    return 0;
}

/*
C:\> gcc -o Experiment4 Experiment4.c

C:\>Experiment4.exe
Enter identifier : value
"value" is a valid identifier

C:\>Experiment4.exe
Enter identifier : _value
"_value" is a valid identifier

C:\>Experiment4.exe
Enter identifier : 1value
"1value" is not a valid identifier

C:\>Experiment4.exe
Enter identifier : value1
"value1" is a valid identifier
*/