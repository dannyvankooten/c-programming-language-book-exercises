#include <string.h>
#include <stdio.h>

void test(char s1[], char s2[], char expected[]);
void squeeze(char s1[], char s2[]);

int main() {
    test("Foo", "o", "F");
    test("Foo", "Bar", "Foo");
    test("Foo", "", "Foo");
    test("ABCDEFGHIJKLMNOPQRSTUWV", "VWUTSRQPONMLKJIHGFEDCBA", "");
}

void test(char _s1[], char s2[], char expected[]) {
    char s1[1000];
	strcpy(s1, _s1);

	squeeze(s1, s2);

	if (expected == NULL) {
		expected = s2;
	}

	if (strcmp(s1, expected) != 0) {
		printf("squeeze(\"%s\", \"%s\") failed. Expected \"%s\", got \"%s\"\n", _s1, s2, expected, s1);
	}
}

void squeeze(char s1[], char s2[]) {
   
   for (int i=0; s1[i] != '\0'; i++) {
       // determine if character is in s2
       for (int j=0; s2[j] != '\0'; j++) {
           if (s1[i] == s2[j]) {
               // remove char from s1 by shifting everything one to the left
               for (int k=i; s1[k] != '\0'; k++) {
                   s1[k] = s1[k+1];
               }
               i--;
               break;
           }
       }
   }
}