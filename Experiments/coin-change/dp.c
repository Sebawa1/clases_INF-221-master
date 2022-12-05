/**
 * @file   dp.c
 * @brief  Coin change, dynamic programming
 */

#include "dp.h"

int m(int const value,
      int const bill[], int const n,
      int count[])
{
	struct {
		int count;
		int last_bill;
	} a[value + 1];

	a[0].count = 0; a[0].last_bill = -1;
	for(int c = 1; c <= value; c++) {
		int min_count = a[c - 1].count, min_k = 0;
		for(int k = 1; k < n && bill[k] <= c; k++)
			if(a[c - bill[k]].count < min_count) {
				min_count = a[c - bill[k]].count;
				min_k = k;
			}
		a[c].count = min_count + 1;
		a[c].last_bill = min_k;
	}
	
	/* Extract number of each denomination */
	for(int i = 0; i < n; i++)
		count[i] = 0;

	for(int c = value; c > 0; c -= bill[a[c].last_bill])
		count[a[c].last_bill]++;

	return a[value].count;
		 
}
		    
