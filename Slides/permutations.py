#!/usr/bin/env python

n = 4

free = [True for i in range(n)]
element = [i for i in range(1, n + 1)]
p = [None for i in range(n)]

def place(k, i):
    free[i] = False
    p[k] = element[i]

def retract(k, i):
    free[i] = True

def show_permutation():
    for i in p:
        print(i, end = " ")
    print()

def generate(k):
    if k == n:
        show_permutation()
    else:
        for i in range(n):
            if free[i]:
                place(k, i)
                generate(k + 1)
                retract(k, i)

generate(0)
