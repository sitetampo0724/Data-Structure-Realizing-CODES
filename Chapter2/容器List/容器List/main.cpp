#include <iostream>
#include <list>
using namespace std;

template<class object>
void printall(const list<object>& v);

int main()
{
	list<int> v1;
	v1.push_front(1);v1.push_front(2);
	v1.push_back(3);v1.push_back(4);
	printall(v1);

	list<int>::const_iterator itr = v1.begin(), itre = v1.end();
	for (int i = 5;itr != itre;++itr, ++i)
		v1.insert(itr, i);
	printall(v1);
	return 0;
}

template<class object>
void printall(const list<object>& v)
{
	if (v.empty())
		cout << "list is empty " << endl;
	else {
		typename list<object>::const_iterator itr,itre;
		itr = v.begin();
		itre = v.end();
		do {
			cout << *itr << ' ';
			++itr;
		} while (itr != itre);
	}
	cout << endl;
}