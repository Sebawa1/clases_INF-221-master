/* Convergence analysis of Aitken's delta squared process */

g(e) := g1 * e + g2 * e^2 / 2 + c * e^3;

e1 : g(e0);
e2 : g(e1);

ep(e0) := e0 - (e1 - e0)^2 / (e2 - 2 * e1 + e0);

taylor(ep(e0), e0, 0, 3);
