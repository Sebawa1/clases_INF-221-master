/**
 * @file max-sum-2.c
 * @brief Algoritmo 2 -- cuadrático
 */

#include "max-sum.h"

double MaxSum(double a[], int n)
{
    double MaxSoFar;

    MaxSoFar = 0.0;
    for(int i = 0; i < n; i++) {
        double Sum = 0.0;
        for(int j = i; j < n; j++) {
            Sum += a[j];
            MaxSoFar = max(MaxSoFar, Sum);
        }
    }
    return MaxSoFar;
}
