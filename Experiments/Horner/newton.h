#ifndef NEWTON_H
#define NEWTON_H

/*
 * If p(x) = a[n] x**n + a[n - 1] x**(n - 1) + ... + a[0], solve
 * p(x) = 0 near x0 using Newton's method.
 */

double newton(const int n, const double a[], double x0, const double eps);

#endif
