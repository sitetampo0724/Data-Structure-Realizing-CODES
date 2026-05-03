#include "unsorted_search.h"
#include "sorted_search.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a[] = { 0,1,2,3,4,5,6,7,8 };
	vector<int> v;
	vector<int>::iterator itr;
	for(int i=0;i<9;i++)
		v.push_back(a[i]);
	cout << binary_search(v.begin(), v.end(), 5) << endl;
	itr = find(v.begin(), v.end(), 5);
	cout << *itr << endl;
}