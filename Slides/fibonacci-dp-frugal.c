/**
 * @file  fibonacci-dp-frugal.c
 * @brief Dynamic programming computation of Fibonacci numbers, frugal
 */

#include "fibonacci.h"

unsigned long long fibonacci(const unsigned n)
{
    if(n <= 1)
        return n;

    unsigned long long a = 0, b = 1, tmp;
    for(int i = 2; i <= n; i++) {
        tmp = b + a;
        a = b;
        b = tmp;
    }
    return b;
}
