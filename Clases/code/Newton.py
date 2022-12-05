#!/usr/bin/env python

# Analyze Newton's root finding method

from sympy import *
from sympy.abc import e, M

fpc = symbols('fpc') # For f'(x^*)

def f(e):
    '''The function, f(x^* + e)'''
    return fpc * e * (1 + M * e + O(e ** 2, e))

def fp(e):
    '''The function's derivative, f'(x^* + e)'''
    return fpc * (1 + 2 * M * e + O(e ** 2, e))

print(series(e - f(e) / fp(e), e, 0, 3))
