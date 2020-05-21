#include "list_int.h"

extern ElemType MaxElement(const Item* i)
{
	const ElemType *max = GetHeadValueList(i);

	i = GetTailList(i);

	while (!IsEmptyList(i))
	{
		const ElemType *e = GetHeadValueList(i);

		if (ElemCompare(max, e) == -1)
			max = e;

		i = GetTailList(i);
	}
	return *max;
}