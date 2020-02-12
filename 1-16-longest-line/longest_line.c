#include <stdlib.h>
#include <stdio.h>

void copy(char * dst, char * src);

#define MAXLINE 10

int main() {
	int c;
	int max = 0;
	char longest[MAXLINE];
	char line[MAXLINE];
	int llen = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == EOF) {

			if (llen > max) {
				max = llen;
				copy(longest, line);
			}

			llen = 0;
			continue;
		} 

		// only copy up to MAXLINE chars
		if (llen < MAXLINE-1) {
			line[llen] = c;
		}
		llen++;
	}

	printf("Longest line is %d characters.\n", max);
	printf("Longest line: %s\n", longest);
}

void copy(char * dst, char * src) {
	int i = 0;
	while ((dst[i] = src[i]) != '\0') {
		i++;
	}
}
