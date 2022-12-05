#ifndef HORNER_H
#define HORNER_H

/*
 * Compute the k first derivatives (just the polynomial if k == 0)
 * of the polynomial a[0] + a[1] * x + ... + a[n] * x ** n
 * into r[]
 */

void horner(const int n, const double a[], const double x,
            const int k, double r[]);

#endif
