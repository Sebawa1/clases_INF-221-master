/**
 * @file  quicksort-5.c
 * @brief Quicksort, Dutch national flag partitioning, straight
 *
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
        int i = m, j = m, k = n;
        while(j < k) {
            if(a[j] < p) {
                swap(&a[i], &a[j]);
                i++;
                j++;
            }
            else if(p < a[j]) {
                k--;
                swap(&a[j], &a[k]);
            }
            else
                j++;
        }
        qs(a, m, i);
        qs(a, k, n);
    }
}
