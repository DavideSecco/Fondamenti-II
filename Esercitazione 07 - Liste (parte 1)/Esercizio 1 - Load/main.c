#include "list_int.h"
 
extern Item* LoadList(const char *filename);

main()
{
	Item *p1 = LoadList("data_00.txt");
	WriteStdoutList(p1);

	Item *p2 = LoadList("data_01.txt");
	WriteStdoutList(p2);

	Item *p3 = LoadList("data_02.txt");
	WriteStdoutList(p3);
	return 0;
}