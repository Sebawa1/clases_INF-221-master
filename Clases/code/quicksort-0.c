/**
 * @file  quicksort-0.c
 * @brief Quicksort, Lomuto partitioning, straight
 *
 * Note that a[j] = p, it can be omited.
 */

#include "sort.h"

static void qs(double a[], int m, int n);

void sort(double a[], int n) { qs(a, 0, n); }

static inline void swap(double *pa, double *pb)
{
    double tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

static void qs(double a[], int m, int n)
{
    if(n - m > 1) {
        double p = a[n - 1];
        int i, j = m;
        for(i = m; i < n - 1; i++)
            if(a[i] <= p) {
                swap(&a[i], &a[j]);
                j++;
            }
        swap(&a[j], &a[n - 1]);

        qs(a, m, j);
        qs(a, j + 1, n);
    }
}
