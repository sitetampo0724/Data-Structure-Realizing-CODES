#include<iostream>
#include<stack>
#include<list>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int* in=new int[num], * out=new int[num];
	for (int i = 0;i < num;i++)
	{
		cin >> in[i];
	}
	for (int i = 0;i < num;i++)
	{
		cin >> out[i];
	}
	stack<int, list<int>> death;
	death.push(in[0]);
	int irreator_in=0, irreator_out=0;
	while(irreator_out<num)
	{
		if (!death.empty() && out[irreator_out] == death.top())
		{
			death.pop();
			irreator_out++;
		}
		else if(irreator_in < num)
		{
			irreator_in++;
			death.push(in[irreator_in]);
		}
		else
		{
			cout << "NO";
			delete[]in;
			delete[]out;
			return 0;
		}	
	}
	cout << "YES";
	delete[]in;
	delete[]out;
	return 0;
}