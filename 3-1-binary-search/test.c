#include <assert.h>
#include <stdio.h>
#include "binsearch.h"

int main() {
    int v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(binsearch(5, v, 10) == 5);
    assert(binsearch(2, v, 10) == 2);
    assert(binsearch(8, v, 10) == 8);
    assert(binsearch(0, v, sizeof v / sizeof v[0]) == 0);

    assert(binsearch_2(5, v, 10) == 5);
    assert(binsearch_2(2, v, 10) == 2);
    assert(binsearch_2(8, v, 10) == 8);
    assert(binsearch_2(0, v, sizeof v / sizeof v[0]) == 0);
}
