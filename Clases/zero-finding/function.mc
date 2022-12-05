/*
 * function.mc -- Example function, lines, points for secant and Newton
 */

/* Points to interpolate */
xval : [1/20, 3/20, 3/10, 2/5,	4/5];
yval : [4/5,  2/5,  3/20, 0,   -3/10];

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
s(x) := (yval[1] - yval[3]) * (x - xval[3]) / (xval[1] - xval[3]) + yval[3];

/* Tangent */
t(x) := at(diff(f(r), r), r = xval[2]) * (x - xval[2]) + yval[2];

plot2d([f(x), s(x), t(x)], [x, 0, 0.5]);

ratsimp(f(x));
ratsimp(s(x));
ratsimp(t(x));

solve(s(x) = 0, x);
solve(t(x) = 0, x);
