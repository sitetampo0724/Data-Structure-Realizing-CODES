#pragma once
#include "SET.h"
template <class KEY,class OTHER>
class AvlTree
{
	struct AvlNode
	{
		SET<KEY, OTHER> data;
		AvlNode* left;
		AvlNode* right;
		int height;
		AvlNode(const SET<KEY, OTHER>& x, AvlNode* lt, AvlNode* rt, int h = 1) :
			data(x), left(lf), right(rt), height(h) {}
	};


	AvlNode* root;
public:
	AvlTree() { root = nullptr; }
	~AvlTree() { makeEmpty(root); }
	SET<KEY, OTHER>* find(const KEY& x) const;
	void insert(const SET<KEY, OTHER>& x);
	void remove(const KEY& x);
private:
	void insert(const SET<KEY, OTHER>& x, AvlNode* &t);
	bool remove(const KEY& x, AvlNode*& t);
	void makeEmpty(AvlNode*& t);
	int height(AvlNode* t)const {
		return t == nullptr ? 0 : t->height;
	}
	void LL(AvlNode*& t);
	void LR(AvlNode*& t);
	void RL(AvlNode*& t);
	void RR(AvlNode*& t);
	int max(int a, int b) { return a > b ? a : b; }
	bool adjust(AvlNode*& t, int subTree);
};

template <class KEY, class OTHER>
SET<KEY, OTHER>* AvlTree<KEY, OTHER>::find(const KEY& x) const
{
	AvlNode* current = root;
	while (current != nullptr && current->data.key != x)
	{
		if (current->data.key > x)
			current = current->left;
		else
			current = current->right;
	}
	if (current == nullptr)return nullptr;
	else return (&current->data);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LL(AvlNode*& t)
{
	AvlNode* t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	t1->height = max(height(t1->left), height(t1->right)) + 1;
	t = t1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RR(AvlNode*& t)
{
	AvlNode* t2 = t->right;
	t->right = t2->left;
	t2->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	t2->height = max(height(t2->left), height(t2->right)) + 1;
	t = t2;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LR(AvlNode*& t)
{
	RR(t->left);
	LL(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RL(AvlNode*& t)
{
	LL(t->right);
	RR(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x)
{
	insert(x, root);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x, AvlNode*& t)
{

	if (t == nullptr)
		t = new AvlNode(x, nullptr, nullptr);
	else if (x.key < t->data.key)
	{
		insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (x.key > t->left->data.key) LR(t);
			else LL(t);
		}
	}
	else if (x.key > t->data.key)
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (x.key > t->right->data.key) RR(t);
			else RL(t);
		}
	}

	t->height = max(height(t->left), height(t->right)) + 1;//it is critical
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::makeEmpty(AvlNode*& t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::remove(const KEY& x)
{
	remove(x, root);
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY& x,AvlNode* & t)
{
	if (t == nullptr) return true;
	if (x == t->data.key) {
		if (t->left == nullptr || t->right == nullptr) {
			AvlNode* old = t;
			t = (t->left == nullptr) ? t->right : t->right;
			delete old;
			return false;
		}
		else {
			AvlNode* temp = t->right;
			while (temp->left != nullptr)
			{
				temp = temp->left;
			}
			t->data = temp->data;
			if (remove(temp->data.key, t->right)) return true;
			else return adjust(t, 1);
		}
	}
	if (x < t->data.key)
	{
		if(remove(x, t->left)) return true;
		return adjust(t, 0);
	}
	else
	{
		if(remove(x, t->right)) return true;
		return adjust(t, 1);
	}
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::adjust(AvlNode*& t, int subTree)
{
	if (subTree == 1) {
		if (height(t->left) - height(t->right) == 1)return true;
		if (height(t->right) == height(t->left)) { (t->height)--;return false; }
		if (height(t->left->right) > height(t->left->left))
		{
			LR(t);
			return false;
		}
		LL(t);
		if (height(t->right) == height(t->left)) return false;
		else return true;
	}
	else{
		if (height(t->right) - height(t->left) == 1)return true;
		if (height(t->right) == height(t->left)) { (t->height)--;return false; }
		if (height(t->right->left) > height(t->right->right))
		{
			RL(t);
			return false;
		}
		RR(t);
		if (height(t->right) == height(t->left)) return false;
		else return true;
	}
}