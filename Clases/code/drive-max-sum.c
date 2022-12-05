/**
 * @file drive-max-sum.c
 * @brief Driver to test max-sum
 */

#include <stdio.h>
#include <stdlib.h>

#include "max-sum.h"

int main(int argc, char *argv[])
{
    FILE *infile;
    int n;

    if(argc != 2) {
        fprintf(stderr, "usage: %s array\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((infile = fopen(argv[1], "r")) == NULL) {
        perror(argv[0]);
        exit(EXIT_FAILURE);
    }

    fscanf(infile, "%d", &n);
    double a[n];
    for(int i = 0; i < n; i++)
        fscanf(infile, "%lf", &a[i]);

    printf("%lf\n", MaxSum(a, n));
    exit(EXIT_SUCCESS);
}
