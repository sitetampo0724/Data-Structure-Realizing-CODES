#pragma once
#include "Set.h"

template <class KEY,class OTHER>
class hashSearchTable
{
private:
	enum State { empty, active, deleted };
	struct node {
		Set<KEY, OTHER> data;
		State state;
		node() :state(empty) {}
	};
	node* array;
	int size;
	int (*key)(const KEY & x);
	static int defaultKey(const KEY& x){
		return (int)x;
	}
public:
	hashSearchTable(int length = 100, int (*f)(const KEY& x)=defaultKey){
		size = length;
		array = new node[size];
		key = f;
	}//lazy...
	~hashSearchTable() { delete[] array; }
	Set<KEY, OTHER>* find(const KEY& x) const;
	void insert(const Set<KEY, OTHER>& x);
	void remove(const KEY& x);
};

template <class KEY, class OTHER>
void hashSearchTable<KEY, OTHER>::insert(const Set<KEY, OTHER>& x)
{
	int initPos, pos;
	initPos = pos = key(x.key);
	do {
		if (array[pos].state != active)
		{
			array[pos].data = x;
			array[pos].state = active;
			return;
		}
		pos = (pos + 1) % size;
	} while (pos != initPos);
}


template <class KEY, class OTHER>
void hashSearchTable<KEY, OTHER>::remove(const KEY& x)
{
	int initPos, pos;
	initPos = pos = key(x.key);
	do {
		if (array[pos].state == empty)return;
		if (array[pos].state == active && array[pos].data == x)
		{
			array[pos].state = deleted;
			return;
		}
		pos = (pos + 1) % size;
	} while (pos != initPos);
}


template <class KEY, class OTHER>
Set<KEY, OTHER>* hashSearchTable<KEY, OTHER>::find(const KEY& x) const
{
	int initPos, pos;
	initPos = pos = key(x.key);
	do {
		if (array[pos].state == empty)return nullptr;
		if (array[pos].state == active && array[pos].data == x)
		{
			return &array[pos].data;
		}
		pos = (pos + 1) % size;

	} while (pos != initPos);
	return nullptr;
}