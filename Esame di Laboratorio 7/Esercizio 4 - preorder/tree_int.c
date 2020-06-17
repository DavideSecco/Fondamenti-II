#include "tree_int.h"

#include <stdio.h>
#include <stdlib.h>

bool IsEmpty(tree t) {
    return (t == NULL);
}

tree EmptyTree() {
    return NULL;
}

bool IsLeaf(tree t) {
    return Left(t) == NULL && Right(t) == NULL;
}

element* GetRoot(tree t) {
    if (IsEmpty(t)) {
        printf("ERROR: Alla funzione 'GetRoot()' è stato passato un albero (nodo) vuoto (NULL pointer).\n");
        abort();
    }
    else {
        return &(t->value);
    }
}

tree Left(tree t) {
    if (IsEmpty(t)) {
        return NULL;
    }
    else {
        return t->left;
    }
}

tree Right(tree t) {
    if (IsEmpty(t)) {
        return NULL;
    }
    else {
        return t->right;
    }
}

tree ConsTree(const element *e, tree l, tree r) {
    tree t = malloc(sizeof(node));
    t->value = *e;
    t->left = l;
    t->right = r;
    return t;
}
