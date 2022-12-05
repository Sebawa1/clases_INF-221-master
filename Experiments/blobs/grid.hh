/**
 * @file grid.hh
 *
 * Class to describe a grid
 */

#include <set>

class grid {
	int n;	/** size of (square) grid */
	int *t;
public:
	grid(): n(0), t(nullptr) {};
	grid(int nn): n(nn) {t = new int[n * n]();};
	~grid() {delete[] t;};

	int size() {return n;};

	friend int blob(const grid&, int, int);
	friend std::istream& operator>>(std::istream&, grid&);
	friend std::ostream& operator<<(std::ostream&, const grid&);
};
