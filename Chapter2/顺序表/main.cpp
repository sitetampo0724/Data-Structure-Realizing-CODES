#include <iostream>
#include "seqList.h"
int main()
{
	
	seqList<int> L(7);
	L.insert(0, 1);
	L.insert(1, 3);
	L.insert(2, 5);
	L.insert(3, 7);
	L.insert(4, 2);
	L.insert(5, 4);
	L.insert(6, 3);

	/*L.visit(5);
	L.length();
	L.insert(5, 10);
	L.search(5);*/ //example in page 30

	L.erase(1);
	L.traverse();
	return 0; //example in page 31
}