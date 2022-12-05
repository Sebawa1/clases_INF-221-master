f(e)   := f1 * e + f2 * e^2 / 2 + f3 * e^3 / 6 + c0 * e^4;
fp(e)  := f1 + f2 * e + f3 * e^2 / 2 + c1 * e^3;
fpp(e) := f2 + f3 * e + c2 * e^2;

Cubic(e)  := e - f(e) / fp(e) * (1 + f(e) * fpp(e) / (2 * fp(e)^2));
Halley(e) := e - f(e) / fp(e) / (1 - f(e) * fpp(e) / (2 * fp(e)^2));

taylor(Cubic(e), e, 0, 4);

taylor(Halley(e), e, 0, 4);
