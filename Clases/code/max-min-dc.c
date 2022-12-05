/**
 * @file max-min-dc.c
 * @brief Find maximum and minimum (divide and conquer)
 */

#include "max-min.h"

void maxmin(const double a[], const int n, double *pl, double *pu)
{
    if(n == 1)
        *pl = *pu = a[0];
    else if(n == 2) {
        if(a[0] < a[1]) {
            *pl = a[0];
            *pu = a[1];
        }
        else {
            *pl = a[1];
            *pu = a[0];
        }
    }
    else {
        double mina, minb, maxa, maxb;
        int n2 = n / 2;
        maxmin(a, n2, &mina, &maxa);
        maxmin(a + n2, n - n2, &minb, &maxb);
        if(mina < minb)
            *pl = mina;
        else
            *pl = minb;
        if(maxa > maxb)
            *pu = maxa;
        else
            *pu = maxb;
    }
}
