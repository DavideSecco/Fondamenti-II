#include "list_int.h"

 bool AnyLoop(list l) {	 if (l == NULL)		 return false;	 for (int i = 0; i < 1000; i++)	 {		 if (l == NULL)			 return false;		 l = Tail(l);	 }	 return true; }