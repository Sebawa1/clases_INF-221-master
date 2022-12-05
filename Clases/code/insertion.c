/**
 * @file insertion.c
 * @brief Insertion sort
 */

#include "sort.h"

void sort(double a[], int n)
{
    for(int i = 1; i < n; i++) {
        double tmp = a[i];
        int j;
        for(j = i - 1; j >= 0 && tmp < a[j]; j--)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}
