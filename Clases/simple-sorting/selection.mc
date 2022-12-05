/*
 * Check analysis of selection sort
 */

H(n) := block([s:0],
              for k : 1 thru n do s : s + 1 / k,
              s);


/* Expected value */

E(n) := block([s:0],
              for k:1 thru n do s : s + H(k),
              s);
Es(n) := (n + 1) * H(n) - n;

DE(n) := E(n) - Es(n);


/* Sums for variance */

S1(n) := block([s:0],
               for k:1 thru n do
                 s : s + k * H(k),
               s);
S1s(n) := n * (n + 1) / 2 * H(n) - n * (n - 1) / 4;

D1(n) := S1(n) - S1s(n);


S2(n) := block([s:0],
               for k:1 thru n do
                 s : s + H(k)^2,
               s);

S2s(n) := (n + 1) * H(n)^2 - (2 * n + 1) * H(n) + 2 * n;

D2(n) := S2(n) - S2s(n);


/* Variance, full check */

V(n) := block([s:0],
              for k:1 thru n do
                s : s + (k + 2) * H(k) - k - H(k)^2,
              s);
Vi(n) := S1(n) + 2 * E(n) - n * (n + 1) / 2 - S2(n);

Vii(n) := S1s(n) + 2 * Es(n) - n * (n + 1) / 2 - S2s(n);

Vs(n) := (n^2 + 9 * n + 6) / 2 * H(n)
           - (n + 1) * H(n)^2
           - n * (3 * n + 17) / 4;

Di(n) := V(n) - Vi(n);
Dii(n) := V(n) - Vii(n);
D(n)  := V(n) - Vs(n);

                
            
