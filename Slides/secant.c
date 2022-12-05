/**
 * @file:  secant.c
 * @brief: Driver to run secant zero finding algorithms
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
        printf(", zero = %17.15f, function calls %d "
               "(error %4.2e, est %4.2e)\n",
               z, fcalls, d, -testcase[i].f(z) / testcase[i].fprime(z));
    }
}

double zero(double f(double), double x0, double x1, double tol)
{
    double y0 = f(x0), y1;
    double d;

    do {
        y1 = f(x1);
        d = y1 * (x1 - x0) / (y1 - y0);
        x0 = x1;
        x1 -= d;
        y0 = y1;
    } while(fabs(d) > tol || fabs(d / x0) > tol);

    return x1;
}
