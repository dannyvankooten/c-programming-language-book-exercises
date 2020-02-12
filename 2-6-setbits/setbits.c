/*
Exercise 2-6. 
Write a function setbits(x,p,n,y) that returns x with the n bits 
that begin at position p set to the rightmost n bits of y , 
leaving the other bits unchanged.
*/
#include <assert.h>
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main() {

    printf("%d\n", 1 & ~(~0 << 1));

    assert(setbits(2, 0, 1, 1) == 3);
    assert(setbits(4, 0, 0, 1) == 4);
    assert(setbits(4, 0, 1, 0) == 4);
    assert(setbits(4, 0, 1, 1) == 5);


    printf("%d\n", getbits(2, 0, 2));
    printf("%d\n", setbits(4, 0, 2, 2));
    assert(setbits(4, 0, 2, 2) == 6);
   
 /*
    4 2 1
    -------
    1 0 0
    0 1 1
    1 1 0
*/

}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: n bits from position p set to the rightmost n bits of y ,*/
unsigned setbits(unsigned x, int p, int n, int y) {
    int last_y = getbits(y, 0, n);
    return x | last_y;
}
