#pragma once
#include "keyValue.h"


template <class KEY,class OTHER>
class BinarySearchTree 
{
private:
	struct BinaryNode
	{
		SET<KEY, OTHER> data;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(const SET<KEY, OTHER>& x, BinaryNode* p, BinaryNode* q) :data(x), left(p), right(q) {}
	};
	BinaryNode* root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	SET<KEY, OTHER>* find(const KEY& x) const;
	void insert(const SET<KEY, OTHER>& x);
	void remove(const KEY& x);

private:
	void insert(const SET<KEY, OTHER>& x, BinaryNode* & t);
	void remove(const KEY& x, BinaryNode* & t);
	SET<KEY, OTHER>* find(const KEY& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode* t);

};

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY,OTHER>::find(const KEY& x) const
{
	return find(x, root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY& x, BinaryNode* t) const
{
	if (t == nullptr || t->data.key == x)
		return & t->data;
	if (x > t->data.key)
		return find(x, t->right);
	return find(x, t->left);
}


template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>:: insert(const SET<KEY, OTHER>& x)
{
	insert(x, root);
}


template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x, BinarySearchTree<KEY, OTHER>::BinaryNode*& t)
{
	if (t == nullptr)
		t = new BinaryNode(x, nullptr, nullptr);
	else if (x.key < t->data.key)
		insert(x, t->left);
	else if (x.key > t->data.key)
		insert(x, t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY& x)
{
	remove(x, root);
}


template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY& x, BinarySearchTree<KEY, OTHER>::BinaryNode*& t)
{
	if (t == nullptr)
		return;
	else if (x < t->data.key) remove(x, t->left);
	else if (x > t->data.key) remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr)
	{
		BinaryNode* temp = t->right;
		while (temp->left != nullptr)temp = temp->left;
		t->data = temp->data;
		remove(t->data.key, t->right);
	}
	else
	{
		BinaryNode* oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}


template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinarySearchTree()
{
	root = nullptr;
}


template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree()
{
	makeEmpty(root);
}


template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode* t)
{
	if (t == nullptr) return;
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
}