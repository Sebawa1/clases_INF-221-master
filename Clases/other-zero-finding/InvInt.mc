f(e) := fp1 * e + fp2 * e^2 / 2 + fp3 * e^3 / 6 + cc * e^4;

f0 :  f(e0);
f1 :  f(e1);
f2 :  f(e2);

en : e0 * f1 * f2 / ((f0 - f1) * (f0 - f2))
       + e1 * f0 * f2 / ((f1 - f0) * (f1 - f2))
       + e2 * f0 * f1 / ((f2 - f0) * (f2 - f1));


limit(limit(limit(en / (e0 * e1 * e2), e0, 0), e1, 0), e2, 0);

