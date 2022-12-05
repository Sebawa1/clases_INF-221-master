/**
 * @file  sgrep.c
 * @brief A simple grep(1) based on Pike's code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "match.h"

#define BUFSZ 1024

int main(int argc, char *argv[])
{
    FILE *infile;
    char buffer[BUFSZ];

    if(argc != 3) {
        fprintf(stderr, "usage: %s regex file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((infile = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", argv[0], argv[2]);
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, BUFSZ, infile)) {
        char *p = strchr(buffer, '\n');
        if(p)
            *p = '\0';
        if(match(argv[1], buffer))
            printf("%s\n", buffer);
    }
    exit(EXIT_SUCCESS);
}
