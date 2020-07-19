#ifndef NODO_H
#define NODO_H

struct nodo {
	int valore;
	struct nodo* prev;
	struct nodo* next;
};
typedef struct nodo nodo;

#endif // !NODO_H

