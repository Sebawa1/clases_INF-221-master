/**
 * @file max-sum-3.c
 * @brief Algoritmo 3 -- cuadrático
 */

#include "max-sum.h"

double MaxSum(double a[], int n)
{
    double CumArray[n + 1]; /* Sum of a[0] to a[i - 1] */
    double MaxSoFar;

    CumArray[0] = 0.0;
    for(int k = 0; k < n; k++)
        CumArray[k + 1] = CumArray[k] + a[k];

    MaxSoFar = 0.0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            MaxSoFar = max(MaxSoFar, CumArray[j + 1] - CumArray[i]);

    return MaxSoFar;
}
