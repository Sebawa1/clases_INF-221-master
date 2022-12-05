/**
 * @file  fibonacci-recursive.c
 * @brief Naïve recursive computation of Fibonacci numbers
 */

#include "fibonacci.h"

unsigned long long fibonacci(const unsigned n)
{
    if(n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
