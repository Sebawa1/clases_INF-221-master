/**
 * @file max-min-opt.c
 * @brief Find maximum and minimum (oprimal)
 */

#include "max-min.h"

void maxmin(const double a[], const int n, double *pl, double *pu)
{
    double max, min;
    int i;

    if(n % 1) {
        max = min = a[0];
        i = 1;
    }
    else {
        if(a[0] < a[1]) {
            max = a[1];
            min = a[0];
        }
        else {
            max = a[0];
            min = a[1];
        }
        i = 2;
    }
    for(; i < n; i += 2) {
        if(a[i] < a[i + 1]) {
            if(a[i] < min)
                min = a[i];
            if(a[i + 1] > max)
                max = a[i + 1];
        }
        else {
            if(a[i + 1] < min)
                min = a[i + 1];
            if(a[i] > max)
                max = a[i];
        }
    }
    *pl = min;
    *pu = max;
}
