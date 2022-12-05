#include "horner.h"

/* Filched from Pankiewicz, "Algorithm 337 Calculation of a Polynomial
 * and its Derivative Values by Horner Scheme", CACM 11:9 (Sep 1968), p 633
 */

/*
 * Compute the k first derivatives (just the polynomial if k == 0)
 * of the polynomial a[0] + a[1] * x + ... + a[n] * x ** n
 * into r[]
 */

void horner(const int n, const double a[], const double x,
            const int k, double r[])
{
	for(int i = 0; i <= k; i++)
		r[i] = a[n];

	for(int j = n - 1; j > -1; j--) {
		r[0] = r[0] * x + a[j];
		int l = j > k ? k : j;
		for(int i = 1; i <= l; i++)
			r[i] = r[i] * x + r[i - 1];
	}
	int l = 1;
	for(int i = 2; i <= k; i++) {
		l *= i;
		r[i] *= l;
	}	
}

