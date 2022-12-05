#!/usr/bin/env python

import sys
from itertools import permutations

n = 0  # Filled later

def is_graceful(p):
    global n
    diff = [False for x in range(n)]
    for i in range(n):
        if diff[abs(p[i + 1] - p[i]) - 1]:
            return False
        else:
            diff[abs(p[i + 1] - p[i]) - 1] = True
    return True

if __name__ == "__main__":
    n = int(sys.argv[1])

    count = 0
    for p in permutations(range(n + 1)):
        if is_graceful(p):
            count += 1
            print(p)
    print(f"There are {count} graceful labellings",
          f"of the path of length {n}")
