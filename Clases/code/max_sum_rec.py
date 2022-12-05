#!/usr/bin/env python

def m(n):
    if n <= 1:
        return n
    else:
        s = m(n // 2) + m(n // 3) + m(n // 4)
        return max(n, s)
    
if __name__ == "__main__":
    while True:
        try:
            n = int(input("n: "))
            print(m(n))
        except:
            print()
            break
        
