#include <iostream>
using namespace std;
struct Node {
	int data;
	int left;
    int right;
	Node() {};
	Node(int x, int p, int q) :data(x), left(p), right(q) {};
};
void preorder(int index,Node* root)
{
	if (index == 0) return;
	cout<<root[index].data<<" ";
	preorder(root[index].left, root);
	preorder(root[index].right, root);
}
int main()
{
	int nodecount;
	cin >> nodecount;
	Node* root;
	root = new Node[nodecount+1];
	for (int i = 1;i <= nodecount;i++)
	{
		cin>>root[i].data>>root[i].left>>root[i].right;
	}
	preorder(1, root);




	return 0;
}