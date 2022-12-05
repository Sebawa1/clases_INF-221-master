#!/usr/bin/env python3

def karatsuba(x: int, y: int) -> int:
    n = max(len(str(x)), len(str(y)))
    if n == 1:
        return x * y
    else:
        nby2  = n // 2
        tnby2 = 10 ** nby2
        a = x // tnby2
        b = x %  tnby2
        c = y // tnby2
        d = y %  tnby2
        ac = karatsuba(a, c)
        bd = karatsuba(b, d)
        ad_plus_bc = karatsuba(a + b, c + d) - ac - bd
        return ac * tnby2 ** 2 + ad_plus_bc * tnby2 + bd

if __name__ == "__main__":
    print(karatsuba(23, 56))
    print(karatsuba(123456, 987654))
