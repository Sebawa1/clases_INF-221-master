/* Gauß' quadrature, w(x) = 1, [-1, 1], 2 points; solve system of equations */

solve([integrate(1, u, -1, 1)	= a0	    + a1,
       integrate(u, u, -1, 1)	= a0 * x0   + a1 * x1,
       integrate(u^2, u, -1, 1) = a0 * x0^2 + a1 * x1^2,
       integrate(u^3, u, -1, 1) = a0 * x0^3 + a1 * x1^3],
      [a0, a1, x0, x1]);
