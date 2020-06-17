#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#include <stdlib.h>

typedef int element;

typedef struct list_element {
    element value;
    struct list_element *next;
} item;

typedef item* list;

/** @brief La funzione Emptylist ritorna una lista vuota.
 
@returns lista vuota

*/
list EmptyList();


/** @brief La funzione Cons aggiunge un nuovo elemento in testa ad una list.

@param e elemento da aggiugnere
@param l lista da aggiornare con il nuovo elemento, puo' essere una lista vuota (NULL)

@returns lista aggiornata
*/
list Cons(const element e, list l);

/** @brief Controlla se la una lista e' vuota

@param l lista da controllare

@returns true se la lista e' vuota, false altrimenti
*/
bool IsEmpty(list l);

/** @brief Ritorna l'elemento in testa ad una lista senza eliminarlo.

@param l lista da cui estrarre l'elemento in testa. Non puo' essere una lista vuota.

@returns elemento in testa alla lista
*/
element Head(list l);

/** @brief Ritorna una lista privata dell'elemento in testa. N.B. la funzione non dealloca la memoria occupata dall'elemento head della lista.

@param l lista da cui eliminare l'elemento in testa. Non puo' essere una lista vuota.

@return lista ottenuta dopo l'eliminazione dell'elemento in testa. Puo' essere una lista vuota.
*/
list Tail(list l);

/** @brief Ritorna una copia di un elemento e. N.B. questa funzione ha scopo puramente didattico.

@param e elemento da copiare

@returns copia dell'elemento.
*/
element Copy(const element e);


#endif // !LISTE_H_

