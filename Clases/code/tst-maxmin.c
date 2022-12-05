/**
 * @file tst-maxmin.c
 * @brief Driver, find maximum and minimum
 */

#include "max-min.h"
#include <stdio.h>

int main()
{
    int n;
    double a[256], min, max;

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lf", &a[i]);

    maxmin(a, n, &min, &max);
    printf("Min: %f, max: %f\n", min, max);
}
