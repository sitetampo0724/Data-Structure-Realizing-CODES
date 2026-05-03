#pragma once
#include "kv_pair.h"
template<class KEY, class OTHER>
int sorted_search_1(const SET<KEY, OTHER> data[], int size, const KEY& x)
{
	data[0].key = x;
	int i = size;
	for (;data[i].key < x;i--);
	if (x == data[i].key)
		return i;
	else
		return 0;
}

template<class KEY, class OTHER>
int sorted_search_2(const SET<KEY, OTHER> data[], int size, const KEY& x)
{
	int Low = 1;
	int High = size;
	while (Low <= High)
	{
		int Mid = (Low + High) / 2;
		if (x < data[Mid].key)
			High = Mid - 1;
		else if (x > data[Mid].key)
			Low = Mid + 1;
		else
			return Mid;
	}
}
//O(logN) algorithm.

