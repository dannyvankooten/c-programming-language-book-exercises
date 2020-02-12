#include "itoa.c"
#include <stdio.h>
#include <string.h>

void test(int input, char exp_output[]);

int main () {
    test(1000, "01000");
    test(005, "00005");
}

void test(int input, char exp_output[]) {
    char output[1000];
    itoa_pad(input, output, 5);

    if (strcmp(output, exp_output) != 0) {
        printf("expected %s, got %s", exp_output, output);
    }
}