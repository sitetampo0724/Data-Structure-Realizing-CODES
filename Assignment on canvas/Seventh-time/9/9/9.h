// 9_9.h
#pragma once		
#include "KeyValue.h"
#include <iostream>
#include <stack>	
using namespace std;


template <class KEY, class OTHER>
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
	BinaryNode * deleteLess(BinaryNode* t, const KEY& x);
	BinaryNode* deleteGreater(BinaryNode* t, const KEY& x);
	BinaryNode* Delete(BinaryNode* t, const KEY& x,const KEY& y);
	SET<KEY, OTHER> findKthLargest(int i) const;

private:
	void insert(const SET<KEY, OTHER>& x, BinaryNode*& t);
	void remove(const KEY& x, BinaryNode*& t);
	SET<KEY, OTHER>* find(const KEY& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode* t);

};

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY& x) const
{
	return find(x, root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY& x, BinaryNode* t) const
{
	if (t == nullptr || t->data.key == x)
		return &t->data;
	if (x > t->data.key)
		return find(x, t->right);
	return find(x, t->left);
}


template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x)
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


template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinaryNode* BinarySearchTree<KEY, OTHER>::deleteLess(BinaryNode* t, const KEY& x)
{
	if (t == nullptr)return;
	if (t->data.key < x)
	{
		BinaryNode* temp = deleteLess(t->right, x);
		delete t; 
		return temp;
	}
	else
	{
		t->left = deleteLess(t->left, x);
	}
}



template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinaryNode* BinarySearchTree<KEY, OTHER>::deleteGreater(BinaryNode* t, const KEY& x)
{

	if (t == nullptr)return;
	if (t->data.key > x)
	{
		BinaryNode* temp = deleteGreater(t->left, x);
		delete t;
		return temp;
	}
	else
	{
		t->right = deleteGreater(t->right, x);
	}
}


template <class KEY, class OTHER>
typename BinarySearchTree<KEY, OTHER>::BinaryNode*
BinarySearchTree<KEY, OTHER>::Delete(BinaryNode* t, const KEY& x, const KEY& y)
{
	if (t == nullptr) return nullptr;

	if (t->data.key >= x && t->data.key <= y)
	{
		BinaryNode* leftResult = Delete(t->left, x, y);
		BinaryNode* rightResult = Delete(t->right, x, y);

		delete t;
		if (leftResult == nullptr) return rightResult;
		if (rightResult == nullptr) return leftResult;

		BinaryNode* temp = leftResult;
		while (temp->right != nullptr) temp = temp->right;
		temp->right = rightResult;
		return leftResult;
	}
	else
	{
		t->left = Delete(t->left, x, y);
		t->right = Delete(t->right, x, y);
		return t;
	}
}


// 公开接口：返回第 i 大的元素（i 从 1 开始，1 表示最大值）
template <class KEY, class OTHER>
SET<KEY, OTHER> BinarySearchTree<KEY, OTHER>::findKthLargest(int i) const
{
	if (root == nullptr || i <= 0)
		throw out_of_range("Tree is empty or invalid i");

	int count = 0;
	SET<KEY, OTHER> result;
	if (findKthLargest(root, i, count, result))
		return result;
	else
		throw out_of_range("i is larger than tree size");
}


template <class KEY, class OTHER>
SET<KEY, OTHER> BinarySearchTree<KEY, OTHER>::findKthLargest(int i) const
{
	int cnt = 0;
	stack<BinaryNode*> s;
	BinaryNode* t = root;
	while (t || !s.empty()) {
		while (t) { s.push(t); t = t->right; }
		t = s.top(); s.pop();
		if (++cnt == i) return t->data;
		t = t->left;
	}

}
// TODO: Reference additional headers your program requires here.



