/* binary-tree-traversal.c -- Recursive version */

#include <stdlib.h> /* For NULL */

struct node {
    item data;
    struct node *left, *right;
};

void traverse_tree(struct node *p, void visit(item))
{
    if(p == NULL)
        return;
    visit(p->data);
    traverse_tree(p->left, visit);
    traverse_tree(p->right, visit);
}
