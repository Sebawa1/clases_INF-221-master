README
======

0/1 knapsack problem, branch and bound.

The `knapsack.cc` program solves the problem by [branch and
bound][1]. As bound the function `b()` computes the optimal value of
the knapsack, assuming items are continuous (can be split). The
optimal solution for the continuous knapsack problem is just to sort
the items by decreasing `value / weight`, and add as much as possible
of each item in order.

To simplify the `b()` function, the program assumes the items come in
order of decreasing `value / weight` already. That way there is no
need to sort them beforehand.

The heart of the program is the `bb(int)` function. It does it's job
by [backtracking][2], as in this case it is easy to place an item in
the backpack and take it back. To (hopefully) speed up the search (get
good bounds early on), the backtracking machinery tries first to
include and then exclude each item. In essence, the first full
solution constructed is the one built by the greedy algorithm:
Consider items in decreasing `value / weight`, add each item if it
still fits.

A small test case is provided, taken from an [example at Geeks for geeks][3].

Input is on standard input, results on standard output. Input data is
the number of items (an `int`), the total capacity (a `double`)
followed by pairs of `value` and `weight` (both `double`) for the
items. The items must be listed in order of decreasing `value /
weight`. No input data validation is done.


[1]: https://en.wikipedia.org/wiki/Branch_and_bound
[2]: https://en.wikipedia.org/wiki/Backtracking
[3]: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
