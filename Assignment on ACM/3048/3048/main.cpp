#include <iostream>
using namespace std;
struct Node {
	int data;
	int left, right;
	Node() {};
	~Node() {};
};

void cal(Node* root,int flag,int currentsum,int & sum)
{
	if (flag == 0) {
		return;
	}
	currentsum = currentsum * 10 + root[flag].data;
	if (root[flag].left == 0 && root[flag].right == 0) {
		sum += currentsum;
		return;
	}
	cal(root, root[flag].left,currentsum,sum);
	cal(root, root[flag].right,currentsum,sum);
}
int main()
{
	int level;
	cin >> level;
	Node* root = new Node[level + 1];
	for (int i = 1;i <= level;i++)
	{
		cin >> root[i].data >> root[i].left >> root[i].right;
	}
	int sum = 0;
	cal(root, 1,0,sum);
	cout << sum<< endl;
	return 0;
}