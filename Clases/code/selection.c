/**
 * @file selection
 * @brief Straight selection sort
 */

#include "sort.h"

void sort(double a[], int n)
{
    for(int i = n; i; i--) {
        int imax = 0;
        double max = a[0];
        for(int j = 1; j < i; j++)
            if(a[j] > a[imax])
                imax = j;

        double tmp = a[i];
        a[i] = a[imax];
        a[imax] = tmp;
    }
}
