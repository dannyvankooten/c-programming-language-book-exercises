/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like
\n and \t as it copies the string t to s . Use a switch . Write a function for the other direction as well, converting escape
sequences into the real characters.
*/

#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);
void escape_reverse(char s[], char t[]);
void test(char s[], char exp[]);

int main() {
    test("Hello \n", "Hello \\n");
}

void test(char s[], char exp[]) {
    char result[1000];
    escape(result, s);

    if (strcmp(result, exp) != 0) {
        printf("escape(\"%s\") failed. expected %s, got %s\n", s, exp, result);
    }

    char reverse_result[1000];
    escape_reverse(reverse_result, result);
    if (strcmp(reverse_result, s) != 0) {
        printf("escape_reverse(\"%s\") failed. expected %s, got %s\n", result, s, result);
    }

}

void escape(char s[], char t[]) {
    char c;
    for (int i=0, j = 0; t[i] != '\0'; i++) {
        c = t[i];

        switch (c) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;

            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;

            default:
                s[j++] = c;
                break;
        }

       
    }
}


void escape_reverse(char s[], char t[]) {
    char c, c_next;
    for (int i=0, j = 0; t[i] != '\0'; i++) {
        c = t[i];

        if (c == '\\') {
            c_next = t[i+1];
            switch (c_next) {
                case 'n':
                    s[j++] = '\n';
                    i++;
                break;

                case 't':
                    s[j++] = '\t';
                    i++;
                break;
            }
        } else {
            s[j++] = c;
        }
       

      
       
    }
}