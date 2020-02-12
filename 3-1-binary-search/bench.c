#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "binsearch.h"

int main(int argc, char *argv[]) {
    unsigned int iterations = 10000000;
    if (argc > 2 && argv[2]) {
        iterations = atoi(argv[2]);
    }

    int(*f)(int x, int v[], long unsigned int n);
    if (argc < 2 || strcmp(argv[1], "binsearch") == 0) {
         f = binsearch;
         printf("Benchmarking %s using %d iterations\n", "binsearch", iterations);
    } else {
        f = binsearch_2;
        printf("Benchmarking %s using %d iterations\n", "binsearch_2", iterations);
    }

    int v[999] = {0};
    for (int i=0; i<999; i++) {
        v[i] = i;
    }
    
    assert(f(1, v, 999) == 1);  
    for (int i = 0; i < iterations; i++) {
        f(1, v, 999);   
    }
}
