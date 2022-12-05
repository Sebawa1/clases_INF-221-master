/**
 * @file:  bisection.c
 * @brief: Driver to run bisection zero finding algorithms
 */

#include <math.h>
#include <stdio.h>

#include "testcases.h"

double zero(double f(double), double x0, double x1, double tol);

const double tol = 1e-10;

int main(void)
{
    for(int i = 0; i < n; i++) {
        fcalls = 0;
        double z = zero(testcase[i].f, testcase[i].x0, testcase[i].x1, tol);
        double d = z - testcase[i].zero;
        if(fabs(d) < tol)
            printf("OK");
        else
            printf("NO");
        printf(", zero = %17.15f, function calls %d (error %4e)\n", z, fcalls,
               d);
    }
}

double zero(double f(double), double x0, double x1, double tol)
{
    double y0 = f(x0), y1 = f(x1), x2, y2;

    do {
        x2 = (x0 + x1) / 2;
        y2 = f(x2);
        if(signbit(y0) != signbit(y2)) {
            x1 = x2;
            y1 = y2;
        }
        else {
            x0 = x2;
            y0 = y2;
        }
    } while(fabs(x1 - x0) > tol);

    return (x0 + x1) / 2;
}
