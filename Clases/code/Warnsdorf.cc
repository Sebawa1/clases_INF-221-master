#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>

int board[8][8];

void backtrack(int, int, int);

int main(int argc, char *argv[])
{
	if(argc != 1 && argc != 3) {
		std::cerr << "usage: " << argv[0] << " [x y]" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	int x, y;
	if(argc == 1)
		x = y = 0;
	else {
		x = std::atoi(argv[1]); y = std::atoi(argv[2]);
	}

	try {
		backtrack(x, y, 0);
	} catch(...) {
		for(int i = 0; i < 8; ++i) {
			for(int i = 0; i < 8; ++i)
				std::cout << "+--";
			std::cout << "+\n";
			for(int j = 0; j < 8; ++j)
				std::cout << "|"
					  << std::setw(2) << board[i][j];
			std::cout << "|\n";
		}
		for(int i = 0; i < 8; ++i)
			std::cout << "+--";
		std::cout << "+\n";
	}
}

struct move {
	int dx;
	int dy;
};

const struct move mvs[8] = {{ 1,  2}, { 2,  1}, { 2, -1}, { 1, -2},
		            {-1, -2}, {-2, -1}, {-2,  1}, {-1,  2}};

inline bool is_free(int x, int y)
{
	return 0 <= x && x < 8 && 0 <= y && y < 8
	       && board[x][y] == 0;
}

inline int free_neighbors(int x, int y)
{
	int n = 0;
	for(int m = 0; m < 8; m++)
		n += is_free(x + mvs[m].dx, y + mvs[m].dy);
	return n;
}

std::vector<int> next(int x, int y)
{
	std::vector<std::pair<int, int>> m;

	for(int k = 0; k < 8; ++k) {
		int nx = x + mvs[k].dx,
		    ny = y + mvs[k].dy;
		if(is_free(nx, ny)) {
			int fn = 0;
			for(int k = 0; k < 8; k++) {
				int nnx = nx + mvs[k].dx,
				    nny = ny + mvs[k].dy;
				if(is_free(nnx, nny))
					++fn;
			}
			m.push_back({k, fn});
		}
	}
	std::ranges::sort(m, std::ranges::less(), &std::pair<int, int>::second);

	std::vector<int> mvs;
	for(auto im:  m)
		mvs.push_back(im.first);
	return mvs;
}

void backtrack(int x, int y, int n)
{
	if(n >= 65) {
		std::exception e;
		throw e;
	}

	for(auto k: next(x, y)) {
		int nx = x + mvs[k].dx,
		    ny = y + mvs[k].dy;
		board[nx][ny] = n;
		backtrack(nx, ny, n + 1);
		board[nx][ny] = 0;
	}
}
