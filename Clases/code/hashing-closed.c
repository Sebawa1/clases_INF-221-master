/** @file  hashing-closed.c
 *  @brief Closed hashing
 */

#include <stdlib.h>

#include "hash.h"
#include "item.h"

#define M 10267

struct node {
    struct item item;
    struct node *next;
};

static struct node *table[M];

struct item *search(struct item *pi)
{
    unsigned long h = hash(pi);

    struct node *p;

    for(p = table[h]; p; p = p->next)
        if(cmp(pi, &p->item) == 0)
            return &p->item;
    return NULL;
}

void insert(struct item *pi)
{
    unsigned long h = hash(pi);

    struct node *p = malloc(sizeof(struct node));

    p->item = *pi;
    p->next = table[h];
    table[h] = p;
}
