/**
 * @file:  fpi.c
 * @brief: Driver to run fixed point iteration algorithm
 */

#include <math.h>
#include <stdio.h>

int fcalls;
double zero(double g(double), double x0, double tol);

double u = 1.0;

double g(double);

const double tol = 1e-10;

int main(void)
{
    fcalls = 0;
    double z = zero(g, 0.9, tol);
    double d = z - 0.5671432904097838;
    if(fabs(d) < tol)
        printf("OK");
    else
        printf("NO");
    printf(", zero = %17.15f, function calls %d (error %4e)\n", z, fcalls, d);
}

double zero(double g(double), double x0, double tol)
{
    double x1;

    for(;;) {
        x1 = g(x0);
        if(fabs(x1 - x0) <= tol && fabs((x1 - x0) / x0) <= tol)
            break;
        x0 = x1;
    }
    return x1;
}

double g(double x)
{
    fcalls++;

    return u * exp(-x);
}
