/**
 * @file max-sum-1.c
 * @brief Algoritmo 1 -- cúbico
 */

#include "max-sum.h"

double MaxSum(double a[], int n)
{
    double MaxSoFar;

    MaxSoFar = 0.0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j <= n; j++) {
            double Sum = 0.0;
            for(int k = i; k < j; k++)
                Sum += a[k];
            MaxSoFar = max(MaxSoFar, Sum);
        }
    }
    return MaxSoFar;
}
