#include "polynomials.h"

void read_poly(int *pn, double a[])
{
	scanf("%d", pn);
	for(int k = *pn; k >= 0; k--)
		scanf("%lf", &a[k]);
}

void show_poly(int n, double a[])
{
	printf("n = %d\n", n);
	if(n == 0) {
		printf("%5lf", a[0]);
	}
	else if(n == 1) {
		if(a[1] != 0.0)
			printf("%5.3lf * x", a[1]);
		if(a[0] > 0.0)
			printf(" + %5.3lf", a[0]);
		else if(a[0] < 0.0)
			printf(" - %5.3lf", -a[0]);
	}
	else {
		printf("%5.3lf * x^%d", a[n], n);
		for(int i = n - 1; i > 1; i--) {
			if(a[i] > 0.0)
				printf(" + %5.3lf * x^%d", a[i], i);
			else if(a[i] < 0.0)
				printf(" - %5.3lf * x^%d", -a[i], i);
		}
		if(n >= 1) {
			if(a[1] > 0.0)
				printf(" + %5.3lf * x", a[1]);
			else if(a[1] < 0.0)
				printf(" - %5.3lf * x", -a[1]);
		}
		if(n) {
			if(a[0] > 0.0)
				printf(" + %5.3lf", a[0]);
			else if(a[0] < 0.0)
				printf(" - %5.3lf", -a[0]);
		}
		else
			printf("%5.3lf", 0.0);
	}
	printf("\n");
}
