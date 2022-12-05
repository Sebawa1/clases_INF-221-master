#!/usr/bin/env python

##
# @file  Chebyshev-s.py
# @brief Compute the T_9 (scaled) polynomial for plotting

from math import *

def T9(x):
    return cos(9 * acos(x))

for i in range(201 + 1):
    x = -1 + 2 * i / 201
    print(x, 100 / 256 * T9(x))
    
