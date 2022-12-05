#!/usr/bin/env raku

my (@x0, @xf, @c);

@c[1] = 327/320, -23/40, -25/16, 5/4;       @x0[1] = 0.3; @xf[1] = 0.5;
@c[2] = 17/20, -1/4, -7/5, 1;               @x0[2] = 0.1; @xf[2] = 0.5;
@c[3] = -553/2704, 27217/12168, -3160/1521, 2450/1521;
   @x0[3] = 0.3; @xf[3] = 0.25;
@c[4] = 5773/13520, 16409/20280, -1270/1521, 680/1521;
   @x0[4] = 0.1; @xf[4] = 0.75;

sub f(@c, $x)
{
    my $p = 1;
    my $s = 0;
    for @c -> $c {
	$s += $c * $p;
	$p *= $x;
    }
    return $s;
}

for 1..4 -> $i {
}

sub write-figure($name, @c, $x0, $xf)
{
    my @x = $x0;
    for 0..5 -> $i {
	@x[$i + 1] = f(@c, @x[$i]);
    }
    
    my $fh = $name.IO.open :w;

    my @head = '\documentclass[spanish, fleqn]{standalone}',
               '\usepackage{babel}',
               '\usepackage{tikz}',
               '\usepackage{pgfplots}',
               '\pgfplotsset{compat = 1.16}',
	       '',
               '\usetikzlibrary{arrows}',
               '',
               '\begin{document}',
	       '  \begin{tikzpicture}',
	       '    \begin{axis}[domain = 0:1,',
	       '                 axis x line = bottom, axis y line = left,',
	       '                 xmin = 0, xmax = 1,',
	       '                 ymin = 0, ymax = 1,',
	       '                 xtick = {' ~ join(', ', @x, $xf) ~ '},',
	       '                 xticklabels = {\(x_0^{\phantom{\ast}}\),',
	       '                                \(x_1^{\phantom{\ast}}\),',
	       '                                \(x_2^{\phantom{\ast}}\),',
	       '                                \(x_3^{\phantom{\ast}}\),',
	       '                                \(x_4^{\phantom{\ast}}\),',
	       '                                \(x_5^{\phantom{\ast}}\),',
	       '                                \(x_6^{\phantom{\ast}}\),',
	       '                                \(x^{\ast}_{\phantom{0}}\)},',
	       '                 ytick style = {draw = none},',
	       '                 yticklabels = {}]',
	       '',
	       '      \addplot[mark = none, blue] {x};',
	       '      \addplot[mark = none, red]';

     my @tail = '    \end{axis}',
	       '  \end{tikzpicture}',
	       '\end{document}';

     # Fix up so there is no overlapping ticks by hand later
     
     $fh.print(join("\n", @head), "\n");
     $fh.print('        {');
     for (0..3).reverse -> $i {
	 my $n = Rat(@c[$i]).numerator;
	 my $d = Rat(@c[$i]).denominator;
	 if $i < 3 {
	     if $n > 0 {
		 $fh.print(" + ");
	     }
	     else {
		 $fh.print(" - ");
		 $n = -$n;
	     }
	 }
	 if $i == 0 {
	     $fh.print("$n / $d");
	 }
	 elsif $i == 1 {
	     $fh.print("$n * x / $d");
	 }
	 else {
	     $fh.print("$n * x^$i / $d");
	 }
     }
     $fh.print('};', "\n\n");

     $fh.print('    \draw [blue, very thin, dashed]', "\n");
     $fh.print("       (axis cs:@x[0], 0) -- (axis cs:@x[0], @x[1]);\n");
     $fh.print('    \draw [blue, very thin, dashed]', "\n");
     $fh.print("       (axis cs:@x[0], @x[1]) -- (axis cs:@x[1], @x[1]);\n");
     for 1..4 -> $i {
	 my ($a, $b, $c) = @x[$i .. $i + 2];
	 $fh.print('    \draw [blue, very thin, dashed]', "\n");
	 $fh.print("       (axis cs:$a, $a) -- (axis cs:$a, $b);\n");
	 $fh.print('    \draw [blue, very thin, dashed]', "\n");
	 $fh.print("       (axis cs:$a, $b) -- (axis cs:$b, $b);\n");
	 $fh.print('    \draw [blue, very thin, dashed]', "\n");
	 $fh.print("       (axis cs:$b, $b) -- (axis cs:$b, $c);\n");
     }
     $fh.print('    \draw [blue, very thin, dashed]', "\n");
     $fh.print("       (axis cs:@x[5], @x[6]) -- (axis cs:@x[6], @x[6]);\n");

     $fh.print(join("\n", @tail), "\n");
}

for 1..4 -> $i {
    write-figure("cobweb-$i.tex", @c[$i], @x0[$i], @xf[$i]);
}
