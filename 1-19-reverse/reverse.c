#include <stdio.h>

#define MAX_LINE_LENGTH 100

// Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to write a program that reverses its
// input a line at a time. 

void reverse_better(char s[]);
int get_line(char line[]);

int main() {
	int len = 0;
	char line[MAX_LINE_LENGTH];

	while ((len = get_line(line)) > 0) {
		reverse_better(line);
		printf("%s", line);
	}
}

int get_line(char line[]) {
	char c;
	int i = 0;
	while ((c = getchar()) != EOF && c != '\n' && i < MAX_LINE_LENGTH-2) {
		line[i] = c;	
		i++;
	}

	line[i++] = '\n';
	line[i++]  = '\0';
	return i;
}

void reverse_better(char s[]) {
	char tmp;

	// get line length
	int j = 0;
	for (; s[j] != '\0'; j++);

	// strip ending \0
	j--;

	// strip ending \n
	if (s[j] == '\n') {
		j--;
	}

	int i;
	for (i=0; i<j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}

}
