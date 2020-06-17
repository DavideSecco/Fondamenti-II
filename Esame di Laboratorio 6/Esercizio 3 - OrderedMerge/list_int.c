#include "list_int.h"

#include <stdio.h>

list EmptyList()
{
    return NULL;
}

list Cons(const element e, list l) 
{
    list t;
    t = malloc(sizeof(item));
    t->value = Copy(e);
    t->next = l;
    return t;
}

bool IsEmpty(list l) {
    return (l == NULL);
}

element Head(list l) {
    if (IsEmpty(l)) {
        printf("ERROR: Alla funzione 'Head()' è stata passata una lista vuota (NULL pointer).\n");
        abort();
    }
    else {
        return l->value;
    }
}

list Tail(list l) {
    if (IsEmpty(l)) {
        printf("ERROR: Alla funzione 'Tail()' è stata passata una lista vuota (NULL pointer).\n");
        abort();
    }
    else {
        return l->next;
    }
}

element Copy(const element e) {
    element el;
    el = e;
    return el;
}