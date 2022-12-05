#!/usr/bin/env raku

sub MAIN(Int:D $n)
{
	my $out = open "$n.dat", :w;
	$out.print($n, "\n");
	for 1..$n {
		my @line;
		for 1..$n {
			@line.push(2.rand.Int);
		}	
		$out.print(@line.join(" "), "\n");
	 }
}
