#!/usr/bin/env python

##
# @file  omega.py
# @brief Compute the omega polynomial for plotting

def omega(x):
    s = 100;
    for i in range(8 + 1):
        p = -1 + 2 * i / 8
        s *= (x - p)
    return s

for i in range(201 + 1):
    x = -1 + 2 * i / 201
    print(x, omega(x))
    
