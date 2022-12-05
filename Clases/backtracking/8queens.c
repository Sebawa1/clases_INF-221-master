/* 8queens.c -- solve 8 queens problem by backtracking */

#include <stdio.h>
#include <stdbool.h>

/* Board */

int solutions = 0;

int queen[8];

bool rfree[8], dufree[15], ddfree[15];

void search(int c);

int main()
{
	for(int i = 0; i < 8; i++)
		rfree[i] = true;
	for(int i = 0; i < 15; i++)
		dufree[i] = ddfree[i] = true;

	search(0);

	return 0;
}

void search(int c)
{
	if(c == 8) {
		/* All queens placed */
		printf("%4d:", ++solutions);
		for(int i = 0; i < 8; i++)
			printf(" %d", queen[i]);
		printf("\n");
	}
	else {
		for(int r = 0; r < 8; r++) {
			if(rfree[r] && dufree[r + c] && ddfree[c + 7 - r]) {
				/* Place queen, mark row and diagonals */
				queen[c] = r;
				rfree[r] = dufree[r + c]
					 = ddfree[c + 7 - r] = false;
				search(c + 1);
				/* Remove queen, unmark row and diagonals */
				rfree[r] = dufree[r + c] = ddfree[c + 7 - r]
					 = true;
			}
		}
	}
}
