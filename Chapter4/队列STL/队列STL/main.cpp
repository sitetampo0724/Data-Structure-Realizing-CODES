#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	queue<int, list<int>>q1;
	queue<int>q2;
	for (int i = 0;i < 10;i++)
		q1.push(i);
	while (!q1.empty())
	{
		cout << q1.front() << endl;
		q1.pop();
	}
	for (int i = 0;i < 10;i++)
		q2.push(i);
	while (!q2.empty())
	{
		cout << q2.front() << endl;
		q2.pop();
	}
	return 0;
}