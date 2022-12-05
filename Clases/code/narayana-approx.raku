#!/usr/bin/env raku

sub secant(&f, $x0 is copy, $x1 is copy, $eps)
{
	my ($y0, $y1) = (f($x0), f($x1));
	my $delta = $y1 * ($x1 - $x0) / ($y1 - $y0);
	
	repeat until abs($delta) < $eps {
		($x0, $x1) = ($x1, $x1 - $delta);
		($y0, $y1) = ($y1, f($x1)); 
		$delta = $y1 * ($x1 - $x0) / ($y1 - $y0);
	}
	return $x1 - $delta;	 
}

sub f($x)
{
	return ($x - 1) * $x * $x - 1;
}

my $rho = secant(&f, 1, 2, 1e-15);

say $rho;

sub a($n)
{
	return $rho**($n + 3) / ($rho**2 + 3);
}

say a(10), ", ", abs(a(10) - 28) / 28 * 100;
say a(17), ", ", abs(a(17) - 406) / 406 * 100;


