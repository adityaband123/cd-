// Write a C program to simulate a lexical analyser for validating operators

#include <stdio.h>
#include <stdbool.h>

int main() {

    char arithmatic[5] = {'+', '-', '*', '/', '%'};
    char relational[4] = {'<', '>', '!', '='};
    char bitwise[4] = {'&', '|', '^', '~'};

    char op[2]; // operator

    printf("Enter the operator : ");
    scanf("%s", &op);

    bool valid = false;

    if (((op[0] == '&' || op[0] == '|') && (op[0] == op[1])) || (op[0] == '!' && op[1] == '\0')) {
        valid = true;
        printf("%s is an logical operator", op);
    }

    for (int i = 0; i < 4; ++i) {
        if ((op[0] == relational[i] && (op[1] == '=' || op[1] == '\0')) && !(op[0] == '!' && op[1] == '\0')) {
            valid = true;
            printf("%s is a relational operator", op);
            break;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if ((op[0] == bitwise[i] && op[1] == '\0') || ((op[0] == '<' || op[0] == '>') && op[0] == op[1])) {
            valid = true;
            printf("%s is a bitwise operator", op);
            break;
        }
    }

    if (op[0] == '?' && op[1] == ':') {
        valid = true;
        printf("%s is a ternary operator", op);
    }

    for (int i = 0; i < 5; ++i) {
        if ((op[0] == '+' || op[0] == '-') && op[0] == op[1]) {
            valid = true;
            printf("%s is an unary operator", op);
            break;
        } else if ((op[0] == arithmatic[i] && op[1] == '=') || (op[0] == '=' && op[1] == '\0')) {
            valid = true;
            printf("%s is an assignment operator", op);
            break;
        } else if (op[0] == arithmatic[i] && op[1] == '\0') {
            valid = true;
            printf("%s is an arithmatic operator", op);
            break;
        }
    }

    if (!valid) {
        printf("%s is not a valid operator", op);
    }

    return 0;
}

/*
C:\> gcc -o Experiment5 Experiment5.c

C:\>Experiment5.exe
Enter the operator : +
+ is an arithmatic operator.

C:\>Experiment5.exe
Enter the operator : &&
&& is a logical operator.

C:\>Experiment5.exe
Enter the operator : <=
<= is a relational operator.

C:\>Experiment5.exe
Enter the operator : ?:
?: is a ternary operator.

C:\>Experiment5.exe
Enter the operator : =
= is an assignment operator.

C:\>Experiment5.exe
Enter the operator : &
& is a bitwise operator.
*/