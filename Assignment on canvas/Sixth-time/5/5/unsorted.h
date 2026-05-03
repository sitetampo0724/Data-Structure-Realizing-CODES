#pragma once

template <class KEY, class OTHER>
struct SET {
	KEY key;
	OTHER other;
	SET() {};
};

template <class KEY, class OTHER>
int unsorted_search(const SET<KEY, OTHER> data[], int size, const KEY& x)
{
	data[0].key = x;
	int i = size;
	for (;data[i].key != x;i--);
	if (i != 0 && i != size)
	{
		KEY temp = data[i].key;
		data[i].key = data[i + 1].key;
		data[i + 1].key = temp;
	}
	return i;
}