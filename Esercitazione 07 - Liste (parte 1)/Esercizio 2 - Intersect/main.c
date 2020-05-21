#include "list_int.h"

extern Item* Intersect(const Item* i1, const Item* i2);
extern Item* LoadList(const char *filename);

int main()
{
	Item *l1 = LoadList("data_00.txt");
	WriteStdoutList(l1);
	
	Item *l2 = LoadList("data_01.txt");
	WriteStdoutList(l2);

	Item *l3 = Intersect(l1, l2);
	WriteStdoutList(l3);
	return 0;
}