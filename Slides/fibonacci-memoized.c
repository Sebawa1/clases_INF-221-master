/**
 * @file  fibonacci-memoized.c
 * @brief Memoized computation of Fibonacci numbers
 */

#include <stdbool.h>

#include "fibonacci.h"

/* Up to F_93 fit in 64 bits */
const int N = 100;
static unsigned long long mem[N] = {[0] = 0, [1] = 1};
static bool known[N] = {[0] = true, [1] = true};

unsigned long long fibonacci(unsigned n)
{
    if(!known[n]) {
        mem[n] = fibonacci(n - 1) + fibonacci(n - 2);
        known[n] = true;
    }
    return mem[n];
}
