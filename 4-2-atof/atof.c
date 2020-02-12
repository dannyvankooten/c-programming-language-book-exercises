// Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
// where a floating-point number may be followed by e or E and an optionally signed exponent.

#include <ctype.h>
#include <stdio.h>
#include <assert.h>

int main() {
    double atof(char[]);
   
    assert(atof("10.00") == 10.0);
    assert(atof("12.34") == 12.34);
    assert(atof("12.34e5") == 1234000);
    assert(atof("12.34e-5") == 0.0001234);

    return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int i, sign;

    // skip spaces
    for (i = 0; isspace(s[i]); i++);

    // handle + and minus sign
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
         i++;
    }

    // handle digits before decimals separator
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    // handle separator
    if (s[i] == '.') {
        i++;
    }

    // handle decimals
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    // handle scientific notation
    if (s[i] == 'e' || s[i] == 'E') {
        // skip char
        i++;

        // skip sign
        int esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        // get exp
        int e = s[i] - '0';
        for (int k = 0; k < e; k++) {
            if (esign > 0) {
                val *= 10;
            } else {
                val /= 10;
            }
        }
        
        
    }

    return sign * val / power;
}