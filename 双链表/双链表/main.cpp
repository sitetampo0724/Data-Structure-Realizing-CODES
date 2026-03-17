#include "dLinkList.h"
int main()
{
	//examples in page 44	
	dLinkList<int> L;
	L.insert(0, 1);
	L.insert(1, 2);
	L.insert(2, 5);
	L.insert(3, 7);
	L.insert(4, 8);
	L.insert(5, 10);
	L.insert(6, 17);

	L.reverse();
	return 0;
}