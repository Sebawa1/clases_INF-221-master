#include <stdlib.h>
#include <string.h>

#include "ElfHash.h"
#include "hashing.h"

#define M 2027

static struct node *T[M];

static struct node *new_node(char *key)
{
    struct node *p;

    p = malloc(sizeof(struct node));
    p->key = strdup(key);
    p->next = NULL;
    return p;
}

static void push(struct node **list, struct node *np)
{
    np->next = *list;
    *list = np;
}

static inline unsigned int hash(char *key)
{
    return ElfHash((unsigned char *)key) % M;
}

void insert(char *key)
{
    struct node *p;

    p = new_node(key);
    push(&T[hash(key)], p);
}

struct node *find(char *key)
{
    struct node *p;

    for(*p = T[hash(key)]; p; p = p->next)
        if(strcmp(p->key, key) == 0)
            return p;
    return NULL;
}
