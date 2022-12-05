/**
 * @file  fibonacci-dp.c
 * @brief Dynamic programming computation of Fibonacci numbers
 */

#include "fibonacci.h"

unsigned long long fibonacci(const unsigned n)
{
    unsigned long long mem[n > 1 ? n + 1 : 2];

    mem[0] = 0;
    mem[1] = 1;
    for(int i = 2; i <= n; i++)
        mem[i] = mem[i - 1] + mem[i - 2];
    return mem[n];
}
