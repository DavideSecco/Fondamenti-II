#ifndef TREE_H_
#define TREE_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>

typedef int element;

typedef struct tree_element {
    element	value;
	struct tree_element *left,*right;
} node;

typedef node* tree;

/** @brief Ritorna un albero vuoto, ovvero un puntatore a NULL

@returns albero vuoto

*/
tree EmptyTree();

/** @brief Costruisce (e restituisce) un nuovo albero avente come radice un nuovo 
nodo a cui viene associato il valore e, e come sottoalberi sinistro e destro i due
alberi l e r, rispettivamente.

@param e elemento da associare alla radice del nuovo albero
@param l sottoalbero di sinistra, puo' essere un albero vuoto (NULL)
@param r sottoalbero di destra, puo' essere un albero vuoto (NULL)

@returns albero risultante
*/
tree ConsTree(const element *e, tree l, tree r);

/** @brief Controlla se l'albero e' vuoto.

@param t albero da controllare

@returns true se l'albero e' vuoto, false altrimenti
*/
bool IsEmpty(tree t);

/** @brief Restituisce il puntatore all'elemento memorizzato nel nodo radice dell'albero.

@param t albero di cui ottenere l'elemento radice

@returns puntatore all'elemento memorizzato nel nodo radice
*/
element* GetRoot(tree t);

/** @brief Restituisce il sottoalbero sinistro di un albero.

@param t albero da cui ottenere il sottoalbero sinistro, Non puo' essere un albero vuoto

@returns sottoalbero sinistro di t
*/
tree Left(tree t);

/** @brief Restituisce il sottoalbero destro di un albero.

@param t albero da cui ottenere il sottoalbero destro

@returns sottoalbero destro di t
*/
tree Right(tree t);

/** @brief Restituisce true se l'albero (il nodo) è una foglia, false altrimenti.

@param t albero (nodo) da controllare

@returns true se l'albero (il nodo) è una foglia, false altrimenti
*/
bool IsLeaf(tree t);

#endif //TREE_REFERENTE_H_