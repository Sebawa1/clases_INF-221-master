/**
 * @file  beer-driver.c
 * @brief Driver to get maximal amount of beer to drink
 */

#include <stdbool.h>
#include <stdio.h>

#include "beer.h"

const int N = 32;
int n;
double v[N];
bool win[N], drink[N];

int main(void)
{
    for(;;) {
        printf("> ");
        if(scanf("%d", &n) != 1)
            break;
        if(!(0 <= n && n < N))
            continue;
        for(int i = 0; i < n; i++)
            scanf("%lf", &v[i]);

        printf("M = %f\n", beer(n));
    }
}
