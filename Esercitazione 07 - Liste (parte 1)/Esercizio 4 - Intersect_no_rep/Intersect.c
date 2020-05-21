#include "list_int.h"

bool controllo(Item *i, const ElemType *e)
{
	while (!IsEmptyList(i))
	{
		const ElemType *n = GetHeadValueList(i);
		if (*e == *n)
			return false;

		i=GetTailList(i);
	}
	return true;
}

Item* Intersect_no_rep(const Item* i1, const Item* i2)
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
			if ( ris == 0)
			{
				bool c = controllo(i, e);

				if (c == true)
				{
					i = InsertBackList(i, e);
				}
			}
			sup = GetTailList(sup);
		}

		i1 = GetTailList(i1);
	}
	return i;
}

