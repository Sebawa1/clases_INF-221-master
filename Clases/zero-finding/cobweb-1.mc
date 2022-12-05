/* cobweb-1.mc -- Cobweb diagram, diverges */

/*
   f(x) = a0 + a1 * x + a2 * x^2 + a3 * x^3,
   with given values at x0, x1, x2 and given derivative at x1
 */

xv : [1/10,  1/2, 9/10];
yv : [19/20, 1/2, 3/20];

yp1 : -12/10;

f(x) := block([acc : a[1]],
              for i : 1 thru 3 do
                acc : acc + a[i + 1] * x^i,
              acc);

remvalue(a); /* Clear variable */
a : map(rhs, solve([f(xv[1]) = yv[1],
                    f(xv[2]) = yv[2],
                    f(xv[3]) = yv[3],
                    at(diff(f(t), t), t = xv[2]) = yp1],
                   [a[1], a[2], a[3], a[4]])[1]);
    
plot2d([t, f(t)], [t, 0, 1]);

array(x, 6);
x[1] : 3/10;
for i : 1 thru 5 do
  x[i + 1] : f(x[i]);


for i : 1 thru 6 do
  print("x[", i, "] = ", float(x[i]));
