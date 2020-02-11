#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trim(char line[]);

int main() {
	int len = 0;
	char * line = malloc(1000);
	size_t max_line = 1000;
	while ((len = getline(&line, &max_line, stdin)) != EOF) {
		trim(line);
		printf("%s", line);	
	}

	free(line);
}

void trim(char line[]) {
	int len = strlen(line);	

	for(int i=len-2; i >= 0; i--) {
		if (line[i] != '\n' && line[i] != ' ' && line[i] != '\t') {
			break;
		}

		// shift to the left
		line[i] = line[i+1];
		line[i+1] = '\0';
	}

	if (line[0] == '\n') {
		line[0] = '\0';
	}
}
