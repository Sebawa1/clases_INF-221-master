/**
 * @file  quicksort-2.c
 * @brief Quicksort, Hoare partitioning, median of three pivot
 *
 * Note that we know a[m] <= p <= a[n - 1], we can skip the ends
 * Even if there are only two elements the sort of the sample works,
 * could special case that one.
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
        int mid = m + (n - m - 1) / 2;
        if(a[m] > a[mid])
            swap(&a[m], &a[mid]);
        if(a[mid] > a[n - 1])
            swap(&a[mid], &a[n - 1]);
        if(a[m] > a[mid])
            swap(&a[m], &a[mid]);

        double p = a[mid];
        int i = m, j = n - 1;
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
