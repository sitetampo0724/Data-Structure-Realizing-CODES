#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void printInt(int num)
{
	if (num < 10)
	{
		cout.put(num + '0');
	}
	else
	{
		printInt(num / 10);
		cout.put(num % 10 + '0');
	}

}
void PrintNum(int num)
{
	stack<int,vector<int>> s;
	int temp;
	s.push(num);
	while (!s.empty())
	{
		temp = s.top();
		s.pop();
		if (temp > 9)
		{
			s.push(temp % 10);
			s.push(temp / 10);
		}
		else cout.put(temp + '0');
	}

}
int main()
{
	PrintNum(1234567788);
	cout<<endl;
	printInt(1234567788);
	return 0;
}