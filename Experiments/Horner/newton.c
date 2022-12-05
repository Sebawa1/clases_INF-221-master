#include <math.h>

#include "newton.h"

/*
 * Use Horner's scheme to compute f, f' in Newton's method for polynomials
 */

double newton(const int n, const double a[], double x, const double eps)
{
	double r0, r1, delta;

	double myeps = fabs(eps);
	do {
		/* Compute f, f' by Horner's scheme */
		r0 = r1 = a[n];
		for(int j = n - 1; j; j--) {
			r0 = r0 * x + a[j];
			r1 = r1 * x + r0;
		}
		r0 = r0 * x + a[0];

		delta = r0 / r1;
		x -= delta;
	} while(fabs(delta) > myeps);
	return x;
}
