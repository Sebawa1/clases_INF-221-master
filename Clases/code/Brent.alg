real procedure zero (a, b, macheps, t, f);
value a, b, macheps, t; real a, b, macheps, t;
real procedure f;

begin
  comment:
    Procedure zero returns a zero x of function f in the given
    interval [a, b], to within a tolerance 6 macheps |x| + 2 t,
    where macheps is the relative machine precision and t is a
    positive tolerance. The procedure assumes that f(a) and f(b)
    have different signs;

  real c, d, e, fa, fb, fc, tol, m, p, q, r, s;
  
  fa := f(a); fb := f(b);
  int: c := a; fc := fa; d := e := b - a;
  ext: if abs(fc) < abs(fb) then begin
           a := b; b := c; c := a;
           fa := fb; fb := fc; fc := fa
         end;
       tol := 2 × macheps × abs(b) + t; m := 0.5 × (c - b);
       if abs(m) > tol ∧ fb ≠ 0 then begin
	 comment: See if a bisection is forced;
           if abs(e) < tol ∨ abs(fa) ≤ abs(fb) then
             d := e := m
           else begin
             s := fb / fa;
             if a = c then begin comment: Linear interpolation;
                 p := 2 × m × s; q := 1 - s
               end
             else begin comment: Inverse quadratic interpolation;
                 q := fa / fc; r := fb / fc;
                 p := s × (2 × m × q × (q - r)
		        - (b - a) × (r - 1));
                 q := (q - 1) × (r - 1) × (s - 1)
               end;
           if p > 0 then
             q := -q
           else
             p := -p;
   	   s := e; e := d;
   	   if 2 × p < 3 × m × q - abs(tol × q)
               ∧ p < abs(0.5 × s × q) then
             d := p / q
           else
             d := e := m
        end;
      a := b; fa := fb;
      b := b + (if abs(d) > tol then d
                  else if m > 0 then tol else -tol);
      fb := f(b);
      go to if fb > 0 ≡ fc > 0 then int else ext
    end;
    zero := b
  end zero;
