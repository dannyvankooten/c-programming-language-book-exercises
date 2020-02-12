// Exercise 4-1. Write the function strindex(s,t) 
// which returns the position of the rightmost occurrence of t in s ,
// or -1 if there is none.

#include <stdio.h>
#include <assert.h>

int strindex(char s[], char t[]);

int main () {
    assert(strindex("Foo", "Bar") == -1);
    assert(strindex("Foo", "oo") == 1);
    assert(strindex("Hello world", "lo") == 3);
    assert(strindex("Hello world", "o") == 7);
}

int strindex(char s[], char t[]) {
    int s_len = 0; 
    int t_len = 0;

    for (s_len=0; s[s_len] != '\0'; s_len++);
    for (t_len=0; t[t_len] != '\0'; t_len++);

    if (t_len > s_len) {
        return -1;
    }

    for (int i = s_len - t_len; i >= 0; i--) {

        int j;
        for (j = 0; j < t_len; j++) {
            if (s[i+j] != t[j]) {
                break;
            }
        }

        if (j == t_len) {
            return i;
        }
    }


    return -1;
}
