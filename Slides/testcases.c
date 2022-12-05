/**
 * @file:  testcases.c
 * @brief: Test cases for zero finding
 */

#include <math.h>

#include "testcases.h"

int fcalls;

double f1(double x)
{
    fcalls++;

    return log(1 - x) / log(x) - 0.5;
}

double f1prime(double x)
{
    fcalls++;

    return -1 / ((1 - x) * log(x)) - log(1 - x) / (x * log(x) * log(x));
}

double f2(double x)
{
    fcalls++;

    return x * exp(x) - 1;
}

double f2prime(double x)
{
    fcalls++;

    return x * (exp(x) + 1);
}

double f3(double x)
{
    fcalls++;

    return x * x * x - 3;
}

double f3prime(double x)
{
    fcalls++;

    return 3 * x * x;
}

double f4(double x)
{
    fcalls++;

    return exp(x) - 3 * x;
}

double f4prime(double x)
{
    fcalls++;

    return exp(x) - 3;
}

double f5(double p)
{
    fcalls++;

    return 1 - pow(1.0 / 2.0, p) - pow(1.0 / 3.0, p) - pow(1.0 / 4.0, p);
}

double f5prime(double p)
{
    fcalls++;

    return log(2.0) / pow(2.0, p) + log(3.0) / pow(3.0, p) +
           log(4.0) / pow(4.0, p);
}

struct test testcase[] = {{f1, f1prime, 0.1, 0.9, 0.3819660112501050},
                          {f2, f2prime, 0.0, 1.0, 0.5671432904097838},
                          {f3, f3prime, 0.0, 3.0, 1.4422495703074080},
                          {f4, f4prime, 0.0, 1.0, 0.6190612867649179},
                          {f5, f5prime, 1.0, 2.0, 1.0821314981404190}};

int n = sizeof(testcase) / sizeof(testcase[0]);
