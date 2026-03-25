#include <list>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* box = new int[n];
	for (int i = 0;i < n;i++) cin >> box[i];
	struct node {
		int height;
		int index;
		node(int a, int b) :height(a),index(b){}
	};
	stack<node, list<node>> num;
	num.push(node(box[0],0));
	for (int i = 1;i < n;i++)
	{
		while (!num.empty() && num.top().height < box[i])
		{
			box[num.top().index]= i+1;
			num.pop();
		}
		num.push(node(box[i], i));
	}
	while (!num.empty())
	{
		
		box[num.top().index] = 0;
		num.pop();
	}
	for (int i = 0;i < n;i++)
	{
		cout << box[i] << " ";
	}
	delete[] box;
	return 0;
}