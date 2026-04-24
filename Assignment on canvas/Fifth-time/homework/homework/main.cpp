#include "binaryTree.h"

int main(int argc,char * arcv[])
{
	int* a = new int[10] {1,2,3,4,5,6,7,8,9,10};
	binaryTree<int> tree(a,10);
	tree.preorder();
	cout << '\n';
	tree.midorder();
	cout << '\n';
	tree.downorder();
	cout << '\n';
	return 0;
}