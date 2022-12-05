README
======

Count blobs of contiguous ones in a square grid.

The class `grid` handles the data itself, and befriends stream
`operator>>` and `operator<<` to read and write grids.

The files `blob-recursive.cc` and `blob-iterative.cc` define recursive and
iterative versions of the friend function `blob(grid& g, int i, int j)`.

In the recursive version, the friend function `blob` counts the size of
the blob containing position `i, j` by setting up a set of seen (counted)
positions, filled in by helper function `blob_help` while counting. The
recursive function `blob_help` calls itself to count the sizes of the blobs
containing each of the neighbors of `i, j`, using data stashed by `blob`
in global static variables of file `blob-recursive.cc`. Base cases for
the recursion are:

- The given coordinate is outside of the grid, it doesn't add to
  the total.
- The point at the given coordinate is zero, not part of a blob.
- The point has already been seen (counted, processed).

The recursive case just adds up the sizes counted for neighbors.

In the iterative version, `blob` manages a queue of pairs yet to be
explored explicitly. Each time a new position comes up, it is pushed into
the queue; a loop extracts the front position and checks it in the same
way as explained above. A position with a one gets counted, marked seen and
it's possible neighbors queued for later consideration.

Example swizzled from Laura Toma's [slides][1] at Bowdoin for CSCI~210,
"Data Structures -- Recursion" (Fall 2010).

[1]: http://www.bowdoin.edu/~ltoma/teaching/cs210/fall10/Slides/Recursion.pdf
