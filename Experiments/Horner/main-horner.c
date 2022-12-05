#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "polynomials.h"
#include "horner.h"

void naive(const int n, const double a[], const double x, double r[]);

int main()
{
	int n = -1;
	int d = 0;
	double a[256], r[256];
	double x;

	int opt;

	while((opt = menu("N(ew S(how E(valuate Q(uit", "Try: nseq")) != EOF) {
		switch(opt) {
		case 'n': /* Read a new polynomial */
			read_poly(&n, a);
			show_poly(n, a);
			break;
		case 's': /* Display the saved polynomial */
			show_poly(n, a);
			break;
		case 'e': /* Evaluate */
			if(n < 0) {
				printf("No polynomial yet\n");
				break;
			}
			printf("Enter x: ");
			scanf("%lf", &x);
			printf("Derivatives: ");
			scanf("%d", &d);
			if(!(0 <= d && d <= n)) {
				printf("Number of derivatives "
				       "out of range\n");
				break;
			}
			horner(n, a, x, d, r);
			printf("Horner: p(%5.3lf) = %5lf",
			       x, r[0]);
			for(int i = 1; i < d; i++)
				printf(", p^(%d)(%5.3lf) = %5lf",
				       i, x, r[i]);
			printf("\n");
			naive(n, a, x, r);
			printf("Naive:	p(%5.3lf) = %5lf, "
			       "p'(%5.3lf) = %5lf, "
			       "p''(%5.3lf) = %5lf\n",
			       x, r[0],
			       x, r[1],
			       x, r[2]);
			break;
		case 'q':
			printf("\n");
			goto out;
			break;
		}
	}
out:
	exit(EXIT_SUCCESS);
}

void naive(const int n, const double a[], const double x,
	   double r[])
{
	double v, vp, vpp;
	double xp;

	xp = 1.0; v = 0.0;
	for(int k = 0; k <= n; k++) {
		v += a[k] * xp;
		xp *= x;
	}

	xp = 1.0; vp = 0.0;
	for(int k = 1; k <= n; k++) {
		vp += k * a[k] * xp;
		xp *= x;
	}

	xp = 1.0; vpp = 0.0;
	for(int k = 2; k <= n - 2; k++) {
		vpp += k * (k - 1) * a[k] * xp;
		xp *= x;
	}

	r[0] = v; r[1] = vp; r[2] = vpp;
}
