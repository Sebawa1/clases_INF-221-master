/**
 * @file blob-recursive.cc
 *
 * Functions to find blob size -- recursively
 */

#include <iostream>
#include <utility>
#include <set>

#include "grid.hh"

using namespace std;

/* Data required from the grid */

static int *t;
static int n;

/* Positions already considered */

static set <pair<int, int>> seen;

/* Helper function */

static int blob_help(int i, int j);

/* The external interface */

int blob(const grid& g, int i, int j)
{
	seen.clear();       // Nothing yet 
	n = g.n; t = g.t;   // Register data from grid

	return blob_help(i, j);  // Do the job
}

static int blob_help(int i, int j)
{
	if(!(0 <= i && i < n) || !(0 <= j && j < n))
		return 0;
	if(t[i * n + j] == 0)
		return 0;
	if(seen.find({i, j}) != seen.end())
		return 0;

	seen.insert({i, j});
	int blobc = 1;
	for(int r = -1; r <= 1; r++)
		for(int s = -1; s <= 1; s++)
			if(r != 0 || s != 0)
				blobc += blob_help(i + r, j + s);
	return blobc;
}
