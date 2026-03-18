#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	cout << "the initial size of v is: " << v.size() << endl;
	cout << "the initial capacity of v is: " << v.capacity() << endl;
	v.push_back(2);
	cout << "after push 2, capacity of v is: " << v.capacity() << endl;
	v.push_back(3);
	cout << "after push 3, capacity of v is: " << v.capacity() << endl;
	v.push_back(4);
	cout << "after push 4, capacity of v is: " << v.capacity() << endl;
	cout << "the size of v is: " << v.size() << endl;

	cout << "contents of v using []: ";
	for (int i = 0; i < v.size(); i++)    
		cout << v[i] << " ";
	cout << endl;

	cout << "contents of v using iterator notation: ";
	vector<int>::const_iterator p;
	for (p = v.begin(); p != v.end(); p++)    
		cout << *p << " ";
	cout << endl;
	return 0;
}