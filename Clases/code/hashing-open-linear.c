/** @file  hashing-open-linear.c
 *  @brief Open addressing with linear probing
 */

#include <stdlib.h>

#include "hash.h"
#include "item.h"

#define M 10267ul

/* We assume item.whatever == 0 means item not present */

enum result { SUCCESS, PRESENT, FULL };

static struct item table[M];

struct item *search(struct item *pi)
{
    unsigned long h = hash(pi);

    int i;
    do {
        i = h;
        if(table[i].whatever == 0)
            return NULL;
        if(cmp(pi, &table[i]) == 0)
            return &table[i];
        i = (i + 1) % M;
    } while(i != h);
    return NULL;
}

enum result insert(struct item *pi)
{
    unsigned long h = hash(pi);

    int i = h;
    do {
        if(table[i].whatever == 0) {
            table[i] = *pi;
            return SUCCESS;
        }
        if(cmp(pi, &table[i]) == 0)
            return PRESENT;
        i = (i + 1) % M;
    } while(i != h);
    return FULL;
}
