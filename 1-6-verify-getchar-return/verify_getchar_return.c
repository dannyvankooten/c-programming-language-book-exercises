#include <stdio.h>
#include <assert.h>

int main() {
    printf("Enter some character: ");
    int value = getchar() != EOF;
    assert(value == 0 || value == 1);
}