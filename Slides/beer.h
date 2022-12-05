/**
 * @file  beer.h
 * @brief Declarations for beer drinking
 */

#ifndef BEER_H
#define BEER_H

extern int n;

extern const int N;

extern double v[];

double beer(int n);

inline double max(double a, double b)
{
    if(a > b)
        return a;
    else
        return b;
}

#endif /* BEEER_H */
