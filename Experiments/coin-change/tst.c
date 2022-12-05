/**
 * @file  tst.c
 * @brief Check coin change routines
 */

#include <stdio.h>

#include "greedy.h"
#include "dp.h"

const int bill[] = {1, 4, 7, 13, 28, 52, 91, 365};
#define N_BILLS (sizeof(bill) / sizeof(bill[0]))

int msol[N_BILLS], m2sol[N_BILLS], gsol[N_BILLS];

int main(void)
{
	int value;
	while(scanf("%d", &value) == 1) {
		int gcnt = g(value, bill, N_BILLS, gsol);
		int mcnt = m(value, bill, N_BILLS, msol);
		int m2cnt = m(value, bill, N_BILLS, m2sol);

		printf("%d: %d greedy, %d value, %d denomination\n",
		       value, gcnt, mcnt, m2cnt);
		int gsum = 0, msum = 0, m2sum = 0;
		for(int k = 0; k < N_BILLS; k++) {
			gsum += gsol[k] * bill[k];
			msum += msol[k] * bill[k];
			m2sum += m2sol[k] * bill[k];
		}
		if(gsum != value)
			printf("Greedy fails: %d\n", gsum);
		if(msum != value)
			printf("Dynamic programming by value fails: %d\n",
			       msum);
		if(m2sum != value)
			printf("Dynamic programming by denomination fails: "
			       "%d\n",
			       msum);
		for(int k = 0; k < N_BILLS; k++)
			printf(" %d", gsol[k]);
		printf("\n");
		for(int k = 0; k < N_BILLS; k++)
			printf(" %d", msol[k]);
		printf("\n");
		for(int k = 0; k < N_BILLS; k++)
			printf(" %d", m2sol[k]);
		printf("\n");
	}
}
