#pragma once
#include "Set.h"

template <class KEY,class OTHER>
class openHashTable
{
private:
	struct node {
		Set<KEY, OTHER> data;
		node* next;

		node(const Set<KEY, OTHER>& x, node* p) :(data(x), next(p)) {}
		node() :next(nullptr) {}
	};
	node** array;
	int size;
	int (*key) (const KEY& x);
	static int defaultKey(const KEY& x) {
		return (int)x;
	}
public:
	openHashTable(int length = 100, int(*f)(const KEY& x) = defaultKey);
	~openHashTable();
	Set<KEY, OTHER>* find(const KEY & x) const;
	void insert(const Set<KEY, OTHER>& x);
	void remove(const KEY & x);
};

template <class KEY, class OTHER>
openHashTable<KEY,OTHER>::openHashTable(int length, int(*f)(const KEY& x))
{
	size = length;
	key = f;
	array = new node * [size];
	for (int i = 0;i < size;i++) array[i] = nullptr;
}

template <class KEY, class OTHER>
openHashTable<KEY, OTHER>::~openHashTable()
{
	node* p, * q;
	for (int i = 0;i < size;i++)
	{
		p = array[i];
		while (p != nullptr)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
	delete[]array;
}


template <class KEY, class OTHER>
void openHashTable<KEY, OTHER>::insert(const Set<KEY, OTHER>& x)
{
	int pos = key(x) % size;
	array[pos] = new node(x, array[pos]);
}


template <class KEY, class OTHER>
void openHashTable<KEY, OTHER>::remove(const KEY& x)
{
	int pos = key(x) % size;
	node* p, * q;
	if (array[pos] == nullptr) return;
	p = array[pos];
	if (array[pos]->data.key == x)
	{
		array[pos] = p->next;
		delete p;
		return;
	}
	while (p->next != nullptr && p->next->data.key != x)p = p->next;
	if (p->next != nullptr)
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

template <class KEY, class OTHER>
Set<KEY, OTHER>* openHashTable<KEY, OTHER>::find(const KEY& x) const
{
	int pos = key(x) * size;
	node* p = array[pos];
	while (p != nullptr && p->next.data != x)p = p->next;
	if (p == nullptr) return nullptr;
	else return &p->data;
}