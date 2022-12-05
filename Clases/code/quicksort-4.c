/**
 * @file  quicksort-4.c
 * @brief Quicksort, Hoare partitioning, median of three pivot,
 *	  cut off and finish of with insertion, replace smaller
 *	  part tail call by loop
 */

#include "sort.h"

const int M = 9;

static void qs(double a[], int m, int n);
static void is(double a[], int n);

void sort(double a[], int n)
{
    qs(a, 0, n);
    is(a, n);
}

static inline void swap(double *pa, double *pb)
{
    double tmp;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

static void qs(double a[], int m, int n)
{
    while(n - m > M) {
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
        if(j + 1 - m > n - j - 1) {
            qs(a, m, j + 1);
            m = j + 1;
        }
        else {
            qs(a, j + 1, n);
            n = j;
        }
    }
}

static void is(double a[], int n)
{
    int i, j;

    for(i = 1; i < n; i++) {
        double tmp = a[i];
        for(j = i - 1; j >= 0 && a[j] > tmp; j--)
            a[j + 1] = a[j];
        a[j + 1] = tmp;
    }
}
