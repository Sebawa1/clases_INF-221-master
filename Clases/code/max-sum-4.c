/**
 * @file max-sum-4.c
 * @brief Algoritmo 4 -- n log n
 */

#include "max-sum.h"

static double *aa;

static double msi(int l, int u)
{
    double Sum, MaxToRight, MaxToLeft, MaxCrossing, MaxInA, MaxInB;

    if(l >= u) /* Zero-element vector */
        return 0.0;
    if(l == u - 1) /* One-element vector */
        return max(aa[l], 0.0);

    int m = (l + u) / 2;
    /* Find max crossing to left */
    Sum = MaxToLeft = 0.0;
    for(int i = m - 1; i >= l; i--) {
        Sum += aa[i];
        MaxToLeft = max(MaxToLeft, Sum);
    }
    /* Find max crossing to right */
    Sum = MaxToRight = 0.0;
    for(int i = m; i < u; i++) {
        Sum += aa[i];
        MaxToRight = max(MaxToRight, Sum);
    }
    MaxCrossing = MaxToLeft + MaxToRight;

    MaxInA = msi(l, m);
    MaxInB = msi(m, u);

    return max(MaxCrossing, max(MaxInA, MaxInB));
}

double MaxSum(double a[], int n)
{
    aa = a;

    return msi(0, n);
}
