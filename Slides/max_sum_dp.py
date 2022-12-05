#!/usr/bin/env python

def m(n):
    if n <= 1:
        return n
    else:
        val = [0, 1]
        for k in range(2, n // 2 + 1):
            val.append(max(k, val[k // 2] 
                               + val[k // 3] 
                               + val[k // 4]))
        return max(n, val[n // 2] 
                        + val[n // 3]
                        + val[n // 4])
    
if __name__ == "__main__":
    while True:
        try:
            n = int(input("n: "))
            print(m(n))
        except:
            print()
            break
        
