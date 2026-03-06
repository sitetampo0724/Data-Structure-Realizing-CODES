#include "algorithm_.h"
#include <iostream>

int main()
{
	int a[] = { -2,11,-4,13,-5,2 };
	Algorithm_ algorithm;
	int start, end;
	algorithm.MAX_1(a, 6, start, end);
	algorithm.MAX_2(a, 6, start, end);
	algorithm.MAX_3(a, 6, start, end);
	return 0;
}
