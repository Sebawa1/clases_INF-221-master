/*
 * regula-falsi.mc -- Example function, lines, points for regula falsi
 */

/* Points to interpolate */
xval : [1/5,  3/10, 9/10, 17/10, 19/10];
yval : [9/10, 7/10, 0,    -3/10, -7/20];

/* Lagrange */
l(x, i) := block([m : 1],
		 for j : 1 thru length(xval) do
		   m : m * if i # j then
			     (x - xval[j]) / (xval[i] - xval[j])
			   else
			     1,
		 m);

f(x) := block([s : 0],
	      for i : 1 thru length(xval) do
		s : s + yval[i] * l(x, i),
	      s);

/* Secant */
s(x) := (yval[2] - yval[4]) * (x - xval[4]) / (xval[2] - xval[4]) + yval[4];

plot2d([f(x), s(x)], [x, 0, 2]);

ratsimp(f(x));
ratsimp(s(x));

x2 : rhs(solve(s(x) = 0, x)[1]);
f(x2);
