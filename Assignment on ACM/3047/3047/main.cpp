#include <iostream>
using namespace std;
struct Node {
	int data;
	int left;
	int right;
	int next;
	Node() : data(0), left(0), right(0), next(0) {};
};
void setup(Node* root,int index)
{
	if (index == 0)return;
    if (root[index].left != 0)
		root[root[index].left].next = root[index].right;
	if (root[index].right != 0 && root[index].next != 0)
		root[root[index].right].next = root[root[index].next].left;
	setup(root, root[index].left);
	setup(root, root[index].right);
}
void level(Node* root,int index)
{
    int current, levelstart = index;
	while (levelstart != 0)
	{
		current = levelstart;
		while (current != 0)
		{
			cout << root[current].next << " "<< endl;
			current = root[current].next;
		}
		levelstart = root[levelstart].left;
	}
}
int main()
{
	int nodecount;
	cin >> nodecount;
	Node* root;
	root = new Node[nodecount + 1];
	for (int i = 1;i <= nodecount;i++)
	{
		cin >> root[i].data >> root[i].left >> root[i].right;
	}
	setup(root, 1);
	level(root, 1);



	return 0;
}