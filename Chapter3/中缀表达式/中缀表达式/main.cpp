#include "calc.h"
int main()
{
	string p;
	cin >> p;
	char* a;
	a = new char[p.length() + 1];
	for (int i = 0;i < p.length();i++)
	{
		a[i] = p[i];
	}
	a[p.length()] = 0;
	calc result(a);
	cout << result.result() << endl;
	delete[] a;
	return 0;
}
