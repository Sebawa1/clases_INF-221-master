#include <iostream>
#include <iomanip>

const int maxitems = 32;

/* Problem data */
int n;
double capacity;
double value[maxitems], weight[maxitems];

/* Currently explored position */
bool ep[maxitems];
double cv, cc;

/* Best so far */
double best;
bool pick[maxitems];

/* Compute the bound */
double b(int k)
{
	double bv = cv, bc = cc;
	int i;
	
	for(i = k; i < n && bc >= weight[i]; i++) {
		bv += value[i];	bc -= weight[i];
	}
	if(i < n)
		bv += value[i] * std::min(bc / weight[i], 1.0);

	return bv;
}

/* Branch and bound, backtrack style */
void bb(int k)
{
	if(k == n) {
		if(cv > best) {
			best = cv;
			for(int i = 0; i < n; i++)
				pick[i] = ep[i];
		}
		return;
	}
	if(b(k) < best)
		return;
	if(cc >= weight[k]) {
		ep[k] = true; cc -= weight[k]; cv += value[k];
		bb(k + 1);
		ep[k] = false; cc += weight[k]; cv -= value[k];
	}
	bb(k + 1);
}
	
int main()
{
	std::cin >> n >> capacity;
	for(int i = 0; i < n; i++)
		std::cin >> value[i] >> weight[i];
	
	best = 0.0; cc = capacity; cv = 0.0;
	bb(0);

	std::cout << "Optimal value: " << best << std::endl;
	for(int i = 0; i < n; i++)
		if(pick[i]) std::cout << std::setw(3) << i;
	std::cout << std::endl;
}
