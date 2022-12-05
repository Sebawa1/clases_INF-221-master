/**
 * @file  quicksort-1.c
 * @brief Quicksort, Hoare partitioning, straight
 *
 * This variant *does not* leave the pivot at j.
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
        double p = a[m + (n - m - 1) / 2];
        int i = m - 1, j = n;
        for(;;) {
            while(a[++i] < p)
                ;
            while(p < a[--j])
                ;
            if(i >= j)
                break;
            swap(&a[i], &a[j]);
        }
        qs(a, m, j + 1);
        qs(a, j + 1, n);
    }
}
