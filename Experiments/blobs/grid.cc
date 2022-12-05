/**
 * @file grid.cc
 *
 * Class to describe a grid
 */

#include <iostream>
#include <utility>
#include <set>

using namespace std;

#include "grid.hh"


istream& operator>>(istream& is, grid& g)
{
	is >> g.n;
	delete[] g.t;
	g.t = new int[g.n * g.n];

	for(int i = 0; i < g.n; i++)
		for(int j = 0; j < g.n; j++)
			is >> g.t[i * g.n + j];
	return is;
}

ostream& operator<<(ostream& os, const grid& g)
{
	for(int i = 0; i < g.n; i++) {
		for(int j = 0; j < g.n; j++)
			os << g.t[i * g.n + j];
		os << "\n";
	}
	return os;
}
