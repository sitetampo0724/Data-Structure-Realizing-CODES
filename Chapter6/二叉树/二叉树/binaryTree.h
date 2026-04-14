#pragma once
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
template <class T>
class binaryTree : public bTree<T>
{
	friend void printTree(const binaryTree& t, T flag); //levelorder recursion
private:
	struct Node
	{
		T data;
		Node* left, * right;
		Node() :left(NULL), right(NULL) {}
		Node(T temp, Node* q=NULL, Node* p=NULL) :data(temp), left(q), right(p) {}
		~Node() {};
	};
	Node* root;
    struct StNode
	{
		Node* node;
		int TimesPop;
		StNode(Node* N = NULL) :node(N), TimesPop(0) {}
		~StNode() {};
	};
public:
    binaryTree() :root(NULL) {}
	binaryTree(T x) : root(new Node(x)) {}
	~binaryTree();
	void clear();
	bool isEmpty() const { return root == NULL; };
	T Root(T flag) const {
		if (root == nullptr) return flag;
		else return root->data;
	};
	T lchild(T x, T flag)const;
	T rchild(T x, T flag)const;
	void delLeft(T x);
	void delRight(T x);
	void preOrder()const;
	void midOrder()const;
	void postOrder()const;
	void levelOrder()const;
	void createTree(T flag);
	void preOrder_nonRecursion()const;
	void midOrder_nonRecursion()const;
	void postOrder_nonRecursion()const;
	int size()const;
	int height()const;
private:
	Node* find(T x, Node* t) const;
	void clear(Node*& t);
	void preOrder(Node* t)const;
	void midOrder(Node* t)const;
	void postOrder(Node* t)const;
	int size(Node* t)const;
	int height(Node* t)const;
};

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node*& t)
{
	if (t == NULL) return;
	clear(t->left);
	clear(t->right);
	delete t;
	t = nullptr;
}

template <class T>
void binaryTree<T>::clear()
{
	clear(root);
}

template <class T>
binaryTree<T>::~binaryTree()
{
	clear(root);
}

template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node* t)const
{
	if (t == nullptr) return;
	cout << t->data << endl;
	preOrder(t->left);
	preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder()const
{
	preOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node* t)const
{
	if (t == nullptr) return;
	midOrder(t->left);
	cout << t->data << endl;
	midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder()const
{
	midOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node* t)const
{
	if (t == nullptr) return;
	postOrder(t->left);
	postOrder(t->right);
	cout << t->data << endl;
}

template <class T>
void binaryTree<T>::postOrder()const
{
	postOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder()const
{
	queue<Node*> q;
	if (root != nullptr) q.push(root);
	else return;
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		cout << temp->data << endl;
        if (temp->left != nullptr) q.push(temp->left);
		if (temp->right != nullptr) q.push(temp->right);
	}
}

template <class T>
binaryTree<T>::Node* binaryTree<T>::find(T x, binaryTree<T>::Node* t) const
{
	Node* temp;
	if (t == NULL) return NULL;
	if (t->data == x) return t;
	if (temp = find(x, t->left)) return temp;
	else return find(x, t->right);
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
	Node* temp = find(x, root);
	if (temp == NULL) return;
	else clear(temp->left);
}

template <class T>
void binaryTree<T>::delRight(T x)
{
	Node* temp = find(x, root);
	if (temp == NULL) return;
	else clear(temp->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag)const
{
	Node* temp = find(x, root);
    if (temp == NULL || temp->left == NULL) return flag;
	else return temp->left->data;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag)const
{
	Node* temp = find(x, root);
    if (temp == NULL || temp->right == NULL) return flag;
	else return temp->right->data;
}

template <class T>
void binaryTree<T>::createTree(T flag)
{
	queue<Node*> q;
	Node* temp;
	T x;
	cout << "Please input the root node: " << endl;
	cin >> x;
	root = new Node(x);
	q.push(root);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << "Please input the left child of " << temp->data << ": ";
		cin >> x;
        if (x != flag) {
			temp->left = new Node(x);
			q.push(temp->left);
		}
		cout << "Please input the right child of " << temp->data << ": ";
		cin >> x;
        if (x != flag) {
			temp->right = new Node(x);
			q.push(temp->right);
		}
	}
}

template <class T>
void printTree(const binaryTree<T> & t, T flag)
{
	queue<T> q;
	if (t.root != nullptr) q.push(t.root->data);
	else return;
	while (!q.empty())
	{
		T p, l, r;
		p = q.front();
		q.pop();
        l = t.lchild(p, flag);
		r = t.rchild(p, flag);
		cout << p << " " << l << " " << r << endl;
        if (l != flag) q.push(l);
		if (r != flag) q.push(r);
	}
}

template <class T>
int binaryTree<T>::size(binaryTree<T>::Node* t)const
{
	if (t == NULL) return 0;
	else return size(t->left) + size(t->right) + 1;
}

template <class T>
int binaryTree<T>::size()const
{
	return size(root);
}

template <class T>
int binaryTree<T>::height(binaryTree<T>::Node* t)const
{
	if (t == NULL) return 0;
	else
	{
		int lt = height(t->left);
		int rt = height(t->right);
		return 1 + (lt > rt ? lt : rt);
	}
}

template <class T>
int binaryTree<T>::height()const
{
	return height(root);
}

template <class T>
void binaryTree<T>::preOrder_nonRecursion()const
{
	stack<Node*> s;
	Node* temp;
	if (root == NULL)return;
	else s.push(root);
	while (!s.empty())
	{
		temp = s.top();
		s.pop();
		cout << temp->data << endl;
		if (temp->right != NULL) s.push(temp->right);
		if (temp->left != NULL) s.push(temp->left);
	}
}

template <class T>
void binaryTree<T>::midOrder_nonRecursion()const
{
    stack<StNode> s;
	StNode temp;
	if (root == NULL)return;
	else s.push(StNode(root));
    while (!s.empty())
	{
		temp = s.top();
		s.pop();
		if (++temp.TimesPop == 2) 
		{
			cout << temp.node->data << endl;
			if(temp.node->right!=NULL)
				s.push(StNode(temp.node->right));
		}
		else
		{
			s.push(temp);
			if (temp.node->left!=NULL)
				s.push(StNode(temp.node->left));
		}
	}
}

template <class T>
void binaryTree<T>::postOrder_nonRecursion()const
{
    stack<StNode> s;
	StNode temp;
	if (root == NULL)return;
	else s.push(StNode(root));
    while (!s.empty())
	{
		temp = s.top();
		s.pop();
		if (++temp.TimesPop == 3)
		{
			cout << temp.node->data << endl;
			continue;
		}
		else if(temp.TimesPop == 2)
		{
			s.push(temp);
			if (temp.node->right != NULL)
				s.push(StNode(temp.node->right));
		}
		else
		{
			s.push(temp);
			if (temp.node->left != NULL)
				s.push(StNode(temp.node->left));
		}
	}
}