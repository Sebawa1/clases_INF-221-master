/**
 * @file:  newton.c
 * @brief: Driver to run Newton zero finding algorithms
 */

#include <math.h>
#include <stdio.h>

#include "testcases.h"

double zero(double f(double), double fprime(double), double x0, double tol);

const double tol = 1e-10;

int main(void)
{
    for(int i = 0; i < n; i++) {
        fcalls = 0;
        double z = zero(testcase[i].f, testcase[i].fprime,
                        (testcase[i].x0 + testcase[i].x1) / 2, tol);
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

double zero(double f(double), double fprime(double), double x0, double tol)
{
    double d;

    do {
        d = f(x0) / fprime(x0);
        x0 -= d;
    } while(fabs(d) > tol || fabs(d / x0) > tol);

    return x0;
}
