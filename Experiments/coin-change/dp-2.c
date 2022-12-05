/**
 * @file   dp-2.c
 * @brief  Coin change, dynamic programming by denomination
 */

#include "dp.h"

int m2(int const value,
      int const bill[], int const n,
      int count[])
{
	struct {
		int count;
		int last_bill;
	} a[value + 1];

	for(int c = 0; c <= n; c++) {
		a[c].count = c; a[c].last_bill = 0;
	}
	for(int k = 1; k < n; k++) {
		for(int c = bill[k]; c <= value; c++)
			if(a[c].count > a[c - bill[k]].count + 1) {
				a[c].count = a[c - bill[k]].count + 1;
				a[c].last_bill = k;
			}
	}
	
	/* Extract number of each denomination */
	for(int i = 0; i < n; i++)
		count[i] = 0;

	for(int c = value; c > 0; c -= bill[a[c].last_bill])
		count[a[c].last_bill]++;

	return a[value].count;
		 
}
		    
