#include <stdio.h>
#include <string.h>

// Exercise 1-23. Write a program to remove all comments from a C program. Don’t forget to handle quoted strings and
// character constants properly. C comments don’t nest.
int htoi(char s[]);
void test(char input[], int expected);

int main() {
	test("0x0", 0);
    test("0xF", 15);
    test("0xFF", 255);
    test("0xFFF", 4095);
    test("0xFFFF", 65535);
    test("0xAF45", 44869);
}

void test(char input[], int expected) {
	char s[1000];
	strcpy(s, input);

	int result = htoi(s);

	if (result != expected) {
		printf("htoi(\"%s\") failed. Expected \"%d\", got \"%d\"\n", input, expected, result);
	}
}

/* convert hexadecimal string to integer */
int htoi(char s[]) {
    int n = 0;

    // 0: 0
    // 1: 1
    // ....
    // 9: 9
    // A: 10
    // B: 11
    // ....
    // F: 16

    int base = 0;
    int i = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    for (; ; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            base = s[i] - '0';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            base = s[i] - 'A' + 10;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
             base = s[i] - 'a' + 10;
        } else {
            break; // unexpected character
        }

        n = 16 * n + base;
    }

    return n;
}

/* atoi: convert s to integer */
int atoi(char s[])
{
    int n = 0;
    int i;
    for (i = 0; s[i] >= '0' && s[i] <= '0'; ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}
