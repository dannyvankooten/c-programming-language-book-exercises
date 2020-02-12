#include <string.h>
#include <stdio.h>

void test(char s1[], char s2[], int expected);
int any(char s1[], char s2[]);

int main() {
    test("Foo", "o", 1);
    test("Bar", "Foo", -1);
    test("Hello world", "dlrow olleH", 0);
}

void test(char _s1[], char s2[], int expected) {
    char s1[1000];
	strcpy(s1, _s1);

	int result = any(s1, s2);
    if (result != expected) {
		printf("any(\"%s\", \"%s\") failed. Expected \"%d\", got \"%d\"\n", _s1, s2, expected, result);
    }

}

int any(char s1[], char s2[]) {
   for (int i=0; s1[i] != '\0'; i++) {
       // determine if character is in s2
       for (int j=0; s2[j] != '\0'; j++) {
           if (s1[i] == s2[j]) {
              return i;
           }
       }
   }

   return -1;
}