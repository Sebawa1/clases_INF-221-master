/**
 * @file max-min.c
 * @brief Find maximum and minimum
 */

#include "max-min.h"

void maxmin(const double a[], const int n, double *pl, double *pu)
{
    double max, min;

    max = min = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }
    *pl = min;
    *pu = max;
}
