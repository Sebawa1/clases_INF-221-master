#!/usr/bin/env raku

# Narayana's cows recurrence

# Recurrence is:
#  @a[$i + 3] = @a[$i + 2] * @c[2] + @a[$i + 1] * @c[1] + @a[$1] * @c[0]
# Initial values are in @a

my @a = [1, 1, 1];
my @c = [1, 0, 1];

for 2..16 -> $i {
	@a[$i + 1] = [+] (@a[$i - @c.elems + 1 .. $i] Z* @c);
}

say @a;