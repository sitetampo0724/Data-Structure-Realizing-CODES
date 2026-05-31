#pragma once
#include "Set.h"

template <class KEY, class OTHER>
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
	int activeNum;      
	int deletedNum;    
	int delLimit;
	int (*key)(const KEY& x);
	static int defaultKey(const KEY& x) {
		return (int)x;
	}
	bool isPrime(int n) {
		if (n < 2) return false;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0) return false;
		return true;
	}

	int nextPrime(int n) {
		while (!isPrime(n)) n++;
		return n;
	}
	void rehash(int newSize) {
		node* old = array;
		int oldSize = size;
		size = nextPrime(newSize);
		array = new node[size];
		activeNum = deletedNum = 0;
		for (int i = 0; i < oldSize; i++)
			if (old[i].state == active) insert(old[i].data);
		delete[] old;
	}
public:
	hashSearchTable(int length = 100, int limit = 50, int (*f)(const KEY& x) = defaultKey)
		: size(nextPrime(length)), activeNum(0), deletedNum(0), delLimit(limit), key(f) {
		array = new node[size];
	}
	~hashSearchTable() { delete[] array; }
	Set<KEY, OTHER>* find(const KEY& x) const;
	int insert(const Set<KEY, OTHER>& x);
	void remove(const KEY& x);
};

template <class KEY, class OTHER>
int hashSearchTable<KEY, OTHER>::insert(const Set<KEY, OTHER>& x)
{
	if (activeNum > size / 2) rehash(size * 2);
	else if (deletedNum >= delLimit) rehash(size);

	int count = 1; 
	int initPos, pos;
	initPos = pos = key(x.key) % size;  
	do {
		if (array[pos].state != active)
		{
			array[pos].data = x;
			array[pos].state = active;
			return count;  
		}
		pos = (pos + 1) % size;
		count++;
	} while (pos != initPos);
	rehash(size * 2);
	return insert(x);  
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