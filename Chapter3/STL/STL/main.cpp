#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;
int main()
{
	stack<int, vector<int>>s1;
	stack<int, list<int>> s2;
	for (int i = 0;i < 10;i++)
		s1.push(i);
	while (!s1.empty())
	{
		cout << s1.top() << " " << endl;
		s1.pop();
	}

	for (int i = 0;i < 10;i++)
		s2.push(i);
	while (!s2.empty())
	{
		cout << s2.top() << " " << endl;
		s2.pop();
	}

}