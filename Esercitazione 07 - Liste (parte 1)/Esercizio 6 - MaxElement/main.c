#include "list_int.h"

extern Item* LoadList(const char *filename);
extern ElemType MaxElement(const Item* i);

int main()
{
	Item *i1 = LoadList("data_00.txt");
	WriteStdoutList(i1);

	ElemType max = MaxElement(i1);
	WriteStdoutElem(&max);

	return 0;
}