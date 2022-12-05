/**
 * @file  fibonacci-driver.c
 * @brief Driver to compute Fibonacci numbers
 */

#include <stdio.h>

#include "fibonacci.h"

int main(void)
{
    unsigned n;

    for(;;) {
        printf("> ");
        if(scanf("%u", &n) != 1)
            break;
        if(n > 93)
            fprintf(stderr, "%u is too large\n", n);
        else
            printf("F(%u) = %llu\n", n, fibonacci(n));
    }
}
