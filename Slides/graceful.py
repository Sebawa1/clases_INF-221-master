#!/usr/bin/env python

import sys

n = 0  # Filled later
count = 0

free = []
diff = []
p = []

def place(k, i):
    p[k] = i
    free[i] = False
    diff[abs(i - p[k - 1])] = False

def retract(k, i):
    free[i] = True
    diff[abs(i - p[k - 1])] = True

def generate(k):
    global count

    if k == n + 1:
        print(p); count += 1
    else:
        for i in range(n + 1):
            if free[i] and diff[abs(i - p[k - 1])]:
                place(k, i)
                generate(k + 1)
                retract(k, i)

if __name__ == "__main__":
    n = int(sys.argv[1])
    count = 0
    free = [True for i in range(n + 1)]
    diff = [False] + [True for i in range(n)]
    p = [None for i in range(n + 1)]
    
    for i in range(n + 1):
        p[0] = i; free[i] = False
        generate(1)
        free[i] = True

    print(f"There are {count} graceful labellings",
          f"of the path of length {n}")
