/**
 * @file  beer-recursive.c
 * @brief Optimal amount of beer to drink, recursive version
 */

#include "beer.h"

double beer(int n)
{
    if(n == 0)
        return 0.0;
    if(n == 1)
        return v[0];

    return max(beer(n - 1), beer(n - 2) + v[n - 1]);
}
