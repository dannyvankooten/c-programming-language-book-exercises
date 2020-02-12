#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TRESHOLD 20

void copy(char * dst, char * src);
int get_line(char line[], int max_length);

int main() {
	int c;
	char line[MAXLINE];
	int line_length = 0;
	size_t maxline = 30;
	char * line2 = malloc(30);
	while ((line_length = getline(&line2, &maxline, stdin)) > 0) {
		if (line_length > TRESHOLD) {
			printf("%d %s", line_length, line2);
		}
	}
	
}

void copy(char * dst, char * src) {
	int i = 0;
	while ((dst[i] = src[i]) != '\0') {
		i++;
	}
}

int get_line(char line[], int max_length) {
	int len = 0;
	int c;
	for (; (c = getchar()) != EOF && c != '\n' && len < max_length; ++len) {
		line[len] = c;	
	}

	if (c == '\n') {
		line[len] = '\n';
		len++;
	}
	line[len] = '\0';
	return len;
}
// last line which should also show
