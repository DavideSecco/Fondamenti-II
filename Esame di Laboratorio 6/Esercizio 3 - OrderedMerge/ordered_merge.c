#define _CRT_SECURE_NO_WARNINGS

#include "list_int.h"
#include <stdio.h>

list OrderedMerge(list la, list lb)
{
	if (IsEmpty(la))
		return lb;

	if (IsEmpty(lb))
		return la;

	list head = NULL;
	list tmp1 = la;
	list tmp2 = lb;

	if (la->value <= lb->value) {
		head = la;
		tmp1 = tmp1->next;
	}
	else {
		head = lb;
		tmp2 = tmp2->next;
	}

	list l3 = head;

	while (1)
	{
		if (tmp1 == NULL) {
			l3 = tmp2;
			break;
		}
		if (tmp2 == NULL) {
			l3 = tmp1;
			break;
		}

		if (tmp1->value <= tmp2->value) {
			l3->next = tmp1;
			l3 = l3->next;
			tmp1 = tmp1->next;
			if (tmp1 == NULL) {
				l3->next = tmp2;
				break;
			}
		}
		else {
			l3->next = tmp2;
			l3 = l3->next;
			tmp2 = tmp2->next;
			if (tmp2 == NULL) {
				l3->next = tmp1;
				break;
			}
		}
	}
	return head;
}

list LoadList(const char *filename) {

	FILE *f;
	f = fopen(filename, "r");

	if (!f) {
		return NULL;
	}

	list l = EmptyList();
	while (1) {
		element tmp;
		if (1 != fscanf(f, "%d", &tmp)) {
			break;
		}
		l = Cons(tmp, l);
	}

	return l;
}

int main()
{
	list la = LoadList("file1.txt");
	list lb = LoadList("file2.txt");

	list lc = OrderedMerge(la, lb);
	return 0;
}