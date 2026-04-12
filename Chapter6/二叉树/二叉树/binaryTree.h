#pragma once
#include <iostream>
using namespace std;
template <class T>
class binaryTree : public bTree<T>
{
	friend void printTree(const binaryTree& T, T flag);
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
public:
	binaryTree() :root(NULL) {};
	binaryTree(T x):data(x) {root=new Node(x) };
	~binaryTree();
	void clear();
	bool isEmpty() const { return root == NULL; };
	T Root(T flag) const {
		if (root == nullptr) return flag;
		else return root->data;
	};
	T parent(T x, T flag)const;
	T lchild(T x, T flag)const;
	T rchild(T x, T flag)const;
	void delLeft(T x, T flag);
	void delRight(T x, T flag);
	void preOrder()const;
	void midOrder()const;
	void postOrder()const;
	void levelOrder()const;
	void createTree(T flag);
private:
	Node* find(T x, Node* t) const;
	void clear(Node*& t);
	void preOrder(Node* t)const;
	void midOrder(Node* t)const;
	void postOrder(Node* t)const;
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