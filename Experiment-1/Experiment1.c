// Design a lexical analyzer for given language and the lexical analyzer should ignore redundant spaces, tabs and new lines.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main() {    
    char c, str[50], keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };
    int line_no = 1, num = 0, i = 0;

    FILE *f;

    printf("Enter C Program :\n");
    f = fopen("input.txt", "w");
    while ((c = getchar()) != EOF) {
        putc(c, f);
    }
    fclose(f);

    f = fopen("input.txt", "r");
    while ((c = getc(f)) != EOF) {
        if (c == '#') {
            c = getc(f);
            while (c != '\n') {
                c = getc(f);
            }
        } else if (c == '"') {
            str[i++] = c;
            c = getc(f);
            while (c != '"') {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = c;
            str[i++] = '\0';
            printf("string         : %s\n", str);
            i = 0;
        } else if (isdigit(c)) {
            num = c - 48;
            c = getc(f);
            while (isdigit(c)) {
                num = num * 10 + (c - 48);
                c = getc(f);
            }
            printf("number         : %d\n", num);
            ungetc(c, f);
        } else if (isalpha(c)) {
            str[i++] = c;
            c = getc(f);
            while (isdigit(c) || isalpha(c) || c == '_') {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = '\0';

            bool is_keyword = false;
            for (int j = 0; j < 32; ++j) {
                if (strcmp(str, keywords[j]) == 0) {
                    is_keyword = true;
                    break;
                }
            }
            if (is_keyword) {
                printf("keyword        : %s\n", str);
            } else {
                printf("identifier     : %s\n", str);
            }
            ungetc(c, f);
            i = 0;
        } else if (c == '\n') {
            ++line_no;
        } else if (c != ' ' && c != '\t') {
            printf("special symbol : %c\n", c);
        }
    }
    printf("number of lines : %d\n", line_no);
    fclose(f);
}

/*
C:\> gcc -o Experiment1 Experiment1.c

C:\> Experiment1.exe
Enter C Program :
#include <stdio.h>

int main() {
        printf("Hello World");
        int a = 10, b = 20;
        printf("%d", a + b);
        return 0;
}
^Z
keyword        : int
identifier     : main
special symbol : (
special symbol : )
special symbol : {
identifier     : printf
special symbol : (
string         : "Hello World"
special symbol : )
special symbol : ;
keyword        : int
identifier     : a
special symbol : =
number         : 10
special symbol : ,
identifier     : b
special symbol : =
number         : 20
special symbol : ;
identifier     : printf
special symbol : (
string         : "%d"
special symbol : ,
identifier     : a
special symbol : +
identifier     : b
special symbol : )
special symbol : ;
keyword        : return
number         : 0
special symbol : ;
special symbol : }
number of lines : 8
*/
