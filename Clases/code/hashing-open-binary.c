/** @file  hashing-open-binary.c
 *  @brief Open addressing with binary probing
 */

#include <stdlib.h>

#include "hash.h"
#include "item.h"

#define M (1ul << 14)

/* We assume item.whatever == 0 means item not present */

enum result { SUCCESS, PRESENT, FULL };

static struct item table[M];

struct item *search(struct item *pi)
{
    unsigned long h = hash(pi);

    for(unsigned int k = 0; k < M; k++) {
        int i = (h ^ k) % M;
        if(table[i].whatever == 0)
            return NULL;
        if(cmp(pi, &table[i]) == 0)
            return &table[i];
    }
    return NULL;
}

enum result insert(struct item *pi)
{
    unsigned long h = hash(pi);

    for(int k = 0; k < M; k++) {
        int i = (h ^ k) % M;
        if(table[i].whatever == 0) {
            table[i] = *pi;
            return SUCCESS;
        }
        if(cmp(pi, &table[i]) == 0)
            return PRESENT;
    }
    return FULL;
}
