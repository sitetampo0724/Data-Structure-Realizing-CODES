#pragma once
#include "kv_pair.h"
template <class KEY, class OTHER>
int unsorted_search(const SET<KEY, OTHER> data[], int size, const KEY& x)
{
	data[0].key = x;
	int i = size;
	for (;data[i].key != x;i--);
	return i;
}
//O(N) algorithm.