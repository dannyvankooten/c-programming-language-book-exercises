#include <stdio.h>
#include <string.h>

// Exercise 1-23. Write a program to remove all comments from a C program. Don’t forget to handle quoted strings and
// character constants properly. C comments don’t nest.
#define MAX_LINE 1000

void substr(char s[], int start, int end);
void strip_comments(char input[]);
void test(char input[], char expected[]);

int main() {
	test("// hidden", "");
	test("With prefix // hidden", "With prefix ");
	test("Multi-line on a single line /* hidden */", "Multi-line on a single line ");
	test("In '// string literal'", NULL);
	test("In '/* string literal */'", NULL);
	test("After '/* string literal */' // hidden", "After '/* string literal */' ");
	test("After '/* string literal */' /* hidden */", "After '/* string literal */' ");
	test("After '/* string literal */' /* hidden */", "After '/* string literal */' ");
	test("Line 1 //hidden \nLine 2: // hidden", "Line 1 \nLine 2: ");
	test("/* multiple comments*/+/*on a single line */+// mixed type too \n", "++\n");
}

void test(char input[], char expected[]) {
	char s[1000];
	strcpy(s, input);

	strip_comments(s);

	if (expected == NULL) {
		expected = input;
	}

	if (strcmp(s, expected) != 0) {
		printf("strip_comments(\"%s\") failed. Expected \"%s\", got \"%s\"\n", input, expected, s);
	}
}

void strip_comments(char input[]) {
	
	int in_literal = 0;
	int in_single_line_comment = 0;
	int comment_start = -1;
	int comment_end = -1;
	int i = 0;
	char c;
	char c_next;

	for (i=0; input[i] != '\0'; i++) {
		c = input[i];
		c_next = input[i+1];

		// detect start or end of literal
		if (comment_start < 0 && (c == '\'' || c == '"')) {
			in_literal = !in_literal;
			continue;
		}

		// detect start of single-line comment
		if (!in_literal && c == '/' && c_next == '/') {
			comment_start = i;
			in_single_line_comment = 1;
			continue;
		}
		
		// detect start of multi-line comment
		if (!in_literal && comment_start < 0 && c == '/' && c_next == '*') {
			comment_start = i;
		}

		// detect end of single-line comment
		if (in_single_line_comment && (c_next == '\0' || c_next == '\n')) {
			comment_end = i;
		}

		// detect end of multi-line comment
		if (comment_start >= 0 && !in_single_line_comment && c == '*' && c_next == '/') {
			comment_end = i+1;
		}

		// if we have something to strip, do it now
		if (comment_start >= 0 && comment_end >= 0) {
			substr(input, comment_start, comment_end);
			i = i - (comment_end - comment_start);
			comment_start = -1;
			comment_end = -1;
			in_single_line_comment = 0;
		}
	}

	// if we reached end of the string & comment is still open
	// strip everything
	if (comment_start >= 0) {
		substr(input, comment_start, -1);
	}	
}

void substr(char s[], int start, int end) {
	end++;

	// find length
	int len = 0;
	while (s[len++] != '\0');

	// if end is after end, strip everything
	if (end < 0 || end > len) {
		s[start] = '\0';
		return;
	}	

	// shift everything after end by the amount to be stripped
	int shift = end - start;
	int i;
	for (i = end; i <= len; i++) {
		s[i-shift] = s[i];	
	}
}

