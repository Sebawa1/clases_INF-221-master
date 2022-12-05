#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menu.h"
#include "polynomials.h"
#include "horner.h"
#include "newton.h"

int main()
{
	int n = -1;
	double a[256];
	double x0, eps = 0.0;

	int opt;

	while((opt = menu("N(ew S(how R(oot E(psilon Q(uit", "Try: nsreq"))
                 != EOF) {
		switch(opt) {
		case 'n': /* Read a new polynomial */
			read_poly(&n, a);
			show_poly(n, a);
			break;
		case 's': /* Display the saved polynomial */
			show_poly(n, a);
			break;
		case 'e': /* Set epsilon */
			printf("Enter epsilon: ");
			scanf("%lf", &eps);
			eps = fabs(eps);
			if(eps == 0)
				eps = 1e-5;
			break;
		case 'r': /* Solve */
			if(n < 0) {
				printf("No polynomial yet\n");
				break;
			}
			if(eps == 0) {
				printf("No epsilon yet\n");
				break;
			}
				
			printf("Enter initial value: ");
			scanf("%lf", &x0);

			double rho = newton(n, a, x0, eps);
			double r[2];
			horner(n, a, rho, 1, r);
			printf("Root: %f (f = %g, f' = %g",
			       rho, r[0], r[1]);
			if(r[1] != 0.0)
				printf(", delta = %g",
				       -r[0] / r[1]);
			printf(")\n");
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
