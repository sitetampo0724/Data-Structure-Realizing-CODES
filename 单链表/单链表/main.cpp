#include "sLinkList.h"
int main()
{
	//examples in page 38.
	sLinkList<int> L;
	L.insert(0, 1);
	L.insert(1, 3);
	L.insert(2, 5);
	L.insert(3, 7);
	L.insert(4, 2);
	L.insert(5, 4);
	L.insert(6, 3);

	L.erase(1);
	L.traverse();
	return 0;
}