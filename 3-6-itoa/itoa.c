// Exercise 3-6. Write a version of itoa that accepts three arguments instead of two.
// The third argument is a minimum field width; 
// the converted number must be padded with blanks on the left if necessary to make it wide enough.

#include <string.h>

void itoa(int n, char s[]);
void itoa_pad(int n, char s[], unsigned int width);
void reverse(char s[]);


/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    /* record sign */
    /* make n positive */ i = 0;
    do
    {
        /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);
    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* itoa: convert n to characters in s */
void itoa_pad(int n, char s[], unsigned int width)
{
    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }
        
    /* generate digits in reverse order */
    i = 0;
    do {
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);

    // if number is smaller than width, pad with zeroes
    while (i < width) {
        s[i++] = '0';
    }

    /* add minus sign if needed */
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}