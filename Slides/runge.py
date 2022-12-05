#!/usr/bin/env python

##
# @file  runge.py
# @brief Compute points to plot interpolating polynomial for Runge's function

def lagrange(z, x, y):
    n = len(x)
    s = 0
    for i in range(n):
        t = y[i]
        for j in range(n):
            if j != i:
                t *= (z - x[j]) / (x[i] - x[j])
        s += t
    return s


intervals = 8
xi = [-1 + 2 * i / intervals for i in range(intervals + 1)]
yi = [1 / (1 + 25 * x * x) for x in xi]

points = 201
for i in range(points + 1):
    x = -1 + 2 * i / points
    print(x, lagrange(x, xi, yi))
