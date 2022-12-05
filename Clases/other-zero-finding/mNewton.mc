f(e) := e^m * (g + gp * e + gpp * e^2 / 2) + c * e^(m + 3);

fp(e) := diff(f(e), e);

fpp(e) := diff(f(e), e, 2);

mN(e) := e - f(e) / fp(e) * (1 - f(e) * fpp(e) / fp(e)^2)^(-1);

Err(e) := taylor(mN(e), e, 0, 4);

E0 : ratsimp(coeff(Err(e), e^0));
E1 : ratsimp(coeff(Err(e), e));
E2 : ratsimp(coeff(Err(e), e^2));
E3 : ratsimp(coeff(Err(e), e^3));

L : limit(1 - f(e) * fpp(e) / fp(e)^2, e, 0);
