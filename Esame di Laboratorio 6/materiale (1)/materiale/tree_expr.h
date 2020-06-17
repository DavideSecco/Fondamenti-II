/** @file
 Documentazione Expression Tree - Esame del 08/01/2020
*/
#ifndef TREE_EXPR_H_
#define TREE_EXPR_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>

typedef struct element {
    char op; 
    int  vl;

    bool is_op; // Identifica se l'element corrente è un operatore (true) o un operando (false).
}element;

typedef struct tree_element {
    element	value;
	struct tree_element *left,*right;
} node;

typedef node* tree;

/** @brief Ritorna un albero vuoto, ovvero un puntatore a NULL.

@returns Albero vuoto (puntatore a NULL).

*/
tree EmptyTree(void);

/** @brief Costruisce (e restituisce) un nuovo albero avente come radice un nuovo 
nodo a cui viene associato il valore e, e come sottoalberi sinistro e destro i due
alberi l e r, rispettivamente.

@param e Elemento da associare alla radice del nuovo albero.
@param l Sottoalbero di sinistra, puo' essere un albero vuoto (NULL).
@param r Sottoalbero di destra, puo' essere un albero vuoto (NULL).

@returns Albero risultante.
*/
tree ConsTree(const element *e, tree l, tree r);

/** @brief Controlla se l'albero e' vuoto.

@param t Albero da controllare.

@returns true se l'albero e' vuoto, false altrimenti.
*/
bool IsEmpty(tree t);

/** @brief Restituisce il puntatore all'elemento memorizzato nel nodo radice dell'albero.

@param t Albero di cui ottenere l'elemento radice.

@returns Puntatore all'elemento memorizzato nel nodo radice.
*/
element* GetRoot(tree t);

/** @brief Restituisce il sottoalbero sinistro di un albero.

@param t Albero da cui ottenere il sottoalbero sinistro. Non puo' essere un albero vuoto.

@returns Aottoalbero sinistro di t.
*/
tree Left(tree t);

/** @brief Restituisce il sottoalbero destro di un albero.

@param t Albero da cui ottenere il sottoalbero destro.

@returns Aottoalbero destro di t.
*/
tree Right(tree t);

/** @brief Restituisce true se l'albero (il nodo) e' una foglia, false altrimenti.

@param t Albero (nodo) da controllare.

@returns true se l'albero (il nodo) e' una foglia, false altrimenti.
*/
bool IsLeaf(tree t);

#endif //!TREE_EXPR_H_