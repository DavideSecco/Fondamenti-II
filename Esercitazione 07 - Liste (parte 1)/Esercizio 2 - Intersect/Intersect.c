#include "list_int.h"

Item* Intersect(const Item* i1, const Item* i2)
{
	Item *i = CreateEmptyList();

	while (1)
	{
		if (IsEmptyList(i1))
			break;

		const ElemType *e = GetHeadValueList(i1);

		const Item *sup= i2;

		while (!IsEmptyList(sup))
		{
			const ElemType *n = GetHeadValueList(sup);
			int ris = ElemCompare(e, n);
			if ( ris == 0)			{
				i = InsertBackList(i, e);
			}
			sup = GetTailList(sup);
		}

		i1 = GetTailList(i1);
	}
	return i;
}