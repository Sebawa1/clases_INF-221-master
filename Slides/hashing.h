#ifndef HASHING_H
#define HASHING_H

struct node {
    char *key;
    struct node *next;
};

struct node *find(char *key);
void insert(char *key);

#endif /* HASHING_H */
