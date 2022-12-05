/* Gauß' quadrature, w(x) = 1, [-1, 1], 3 points; solve system of equations */
/* We use the symmetry a0 = a2, -x0 = x2 */

solve([integrate(1, u, -1, 1)	= a0	    + a1	+ a0,
       integrate(u, u, -1, 1)	= a0 * x0   + a1 * x1	+ a0 * (-x0),
       integrate(u^2, u, -1, 1) = a0 * x0^2 + a1 * x1^2 + a0 * (-x0)^2,
       integrate(u^3, u, -1, 1) = a0 * x0^3 + a1 * x1^3 + a0 * (-x0)^3,
       integrate(u^4, u, -1, 1) = a0 * x0^4 + a1 * x1^4 + a0 * (-x0)^4,
       integrate(u^5, u, -1, 1) = a0 * x0^5 + a1 * x1^5 + a0 * (-x0)^5],
      [a0, a1, x0, x1]);
