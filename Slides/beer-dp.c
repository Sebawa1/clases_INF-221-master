/**
 * @file  beer-dp.c
 * @brief Optimal amount of beer to drink, dynamic programming
 */

#include "beer.h"

double beer(int n)
{
    double mb[n > 1 ? n + 1 : 2];

    mb[0] = 0.0;
    mb[1] = v[0];
    for(int i = 2; i <= n; i++)
        mb[i] = max(mb[i - 1], mb[i - 2] + v[i - 1]);
    return mb[n];
}
