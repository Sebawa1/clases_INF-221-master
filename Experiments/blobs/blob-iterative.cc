/**
 * @file blob-iterative.cc
 *
 * Functions to find blob size -- iteratively
 */

#include <iostream>
#include <utility>
#include <set>
#include <queue>

#include "grid.hh"

using namespace std;

int blob(const grid& g, int i, int j)
{
	set <pair<int, int>> seen;
	queue <pair<int, int>> work;

	int blobc = 0;
	work.push({i, j});
	while(!work.empty()) {
		pair<int, int> curr = work.front(); work.pop();
		i = curr.first, j = curr.second;
		if(!(0 <= i && i < g.n) || !(0 <= j && j < g.n))
			continue;
		if(g.t[i * g.n + j] == 0)
			continue;
		if(seen.find({i, j}) != seen.end())
			continue;
		seen.insert({i, j}); blobc++;
		for(int r = -1; r <= 1; r++)
			for(int s = -1; s <= 1; s++)
				work.push({i + r, j + s});
	}
	return blobc;
}
