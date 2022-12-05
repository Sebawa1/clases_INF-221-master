/**
 * @file tst.cc
 *
 * Test grid operations
 */

#include <iostream>
#include <utility>

#include "grid.hh"

using namespace std;

int main()
{
	grid g;

	cin >> g;
	cout << g;

	for(int i = 0; i < g.size(); i++)
		for(int j = 0; j < g.size(); j++)
			cout << "Blob at (" << i << ", " << j << "): "
			     << blob(g, i, j) << "\n";

	return 0;
}
