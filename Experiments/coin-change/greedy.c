/**
 * @file 
 * @brief
 */

#include "greedy.h"

int g(int value, int const bill[], int const n, int count[])
{
	int r = 0;
	for(int k = n - 1; k >= 0; k--) {
		count[k] = value / bill[k]; 
		r += count[k];
		value %= bill[k];
	}

	return r;
}
