#ifndef PROTOTYPE_TREE_H_INCLUDED
#define PROTOTYPE_TREE_H_INCLUDED
#define compear compear_data
typedef struct
{
    long dni;
    char surName[SIZE_NAME],
         name[SIZE_SURNAME];
    float average;
}person, Info;

typedef struct node
{
    struct node *left,
                *rigth;
    Info info;
}node, *Tree;

#endif // PROTOTYPE_TREE_H_INCLUDED
