#include <stdio.h>

/* Polynomial: Coefficients and degree */

float a[] = {1, -4, 6, -4, 1};
const int n = sizeof(a) / sizeof(a[0]) - 1;

float horner(int n, float a[], float x)
{
    float p = a[n];
    
    for(int k = n - 1; k > -1; k--)
	p = p * x + a[k];
    return p;
}

int main()
{
	for(int k = 0; k < (1.035 - 0.975) / 0.001; k++) {
		float x = 0.975 + k * 0.001;
		printf("%f %e\n",  x, horner(n, a, x));
        }
}
