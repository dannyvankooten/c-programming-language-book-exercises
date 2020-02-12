
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
extern int binsearch(int x, int v[], long unsigned int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid]) {
            high = mid ;
        } else if (x > v[mid]) {
            low = mid;
        } else {
            /* found match */
            return mid;
        }
    }

    /* no match */
    return -1;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
extern int binsearch_2(int x, int v[], long unsigned int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    return (x == v[low]) ? low : -1;
}