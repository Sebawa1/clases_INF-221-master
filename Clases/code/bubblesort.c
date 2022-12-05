/**
 * @file bubblesort.c
 * @brief Bubble sort
 */

#include "sort.h"

void sort(double a[], int n)
{
    int k;

    for(int i = n - 1; i; i = k) {
        k = 0;
        for(int j = 0; j < i; j++) {
            if(a[j + 1] < a[j]) {
                double tmp;
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

                k = j;
            }
        }
        i = k;
    }
}
