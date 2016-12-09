#include <stdio.h>
#include "prototype_tree.h"

void create_tree(Tree *p)
{
    *p = NULL;
}

int is_tree_full(Tree *p)
{
    void *aux = malloc(sizeof(node));
    free(aux);

    return aux == NULL;
}
int is_empty_tree(Tree *p)
{
    return (*p) == NULL;
}

int put_in_tree(Tree *p, Info *d, int (*compear)(Info *, Info *))
{
    int cmp;

    while(*p)
    {
        cmp = compear(&(*p)->info.dni, d);

        if(!cmp)
            return CLAV_DUP;

        if(cmp > 0)
            p = &(*p)->left;
        else
            p = &(*p)->rigth;
    }

    node new_node = (node *) malloc(sizeof(node));

    if(!new_node)
        return SIN_MEM;

    new_node->info = *d;
    new_node->left = NULL;
    new_node->rigth = NULL;
    *p = new_node;
    return O_K;
}

void pos_order(Tree *p)
{
    if(*p)
    {
        pos_order(&(*p)->left);
        pos_order(&(*p)->rigth);
        pos_order(&(*p)->info);
    }
}

void pre_order(Tree *p)
{
    if(*p)
    {
        pre_order(&(*p)->info);
        pre_order(&(*p)->left);
        pre_order(&(*p)->rigth);
    }
}

void in_order(Tree *p)
{
    if(*p)
    {
        in_order(&(*p)->left);
        in_order(&(*p)->info);
        in_order(&(*p)->rigth);
    }
}

int heigth_tree(Tree *)
{
    int h_left,
        h_rigth;

    if(*p)
    {
        h_left = heigth_tree(&(*p)->left);
        h_rigth = heigth_tree(&(*p)->rigth);

        return h_left >= h_rigth ? h_left + 1 ? h_rigth +1;
    }
    return 0;
}

int count_nodes(Tree *p)
{
    if(*p)
    {
        return count_nodes(&(*p)->left) +  count_nodes(&(*p)->rigth) + 1;
    }
    return 0;
}
