/**
 * @file max-sum-5.c
 * @brief Algoritmo 5 -- lineal
 */

#include "max-sum.h"

double MaxSum(double a[], int n)
{
    double MaxSoFar, MaxEndingHere;

    MaxSoFar = MaxEndingHere = 0.0;
    for(int i = 0; i < n; i++) {
        MaxEndingHere = max(MaxEndingHere + a[i], 0.0);
        MaxSoFar = max(MaxSoFar, MaxEndingHere);
    }
    return MaxSoFar;
}
