#include "queue.h"
#pragma once
template <class elemType>
class seqQueue:public queue<elemType> {
private:
	elemType* elem;
	int maxSize;
	int front, rear;
	void doubleSpace();
public:
	seqQueue(int size=10);
	~seqQueue();
	bool isEmpty()const;
	void enQueue(const elemType& x);
	elemType deQueue();
	elemType getHead()const;
};
template <class elemType>
seqQueue<elemType>::seqQueue(int size) {
	elem = new elemType[size];
	maxSize = size;
	front = rear = 0;
}
template <class elemType>
seqQueue<elemType>::~seqQueue()
{
	delete[]elem;
}
template <class elemType>
bool seqQueue<elemType>::isEmpty() const
{
	if (rear == front)
		return true;
	return false;
}
template <class elemType>
void seqQueue<elemType>::enQueue(const elemType& x)
{
	if ((rear + 1) % maxSize == front)
		doubleSpace();
	elem[rear=(rear + 1) % maxSize] = x;
}
template <class elemType>
elemType seqQueue<elemType>::deQueue()
{
	if (!isEmpty())
	{
		front = (front + 1) % maxSize;
		return elem[front];
	}
	throw OUT_OF_BOUND();
}
template <class elemType>
elemType seqQueue<elemType>::getHead()const
{
	if (!isEmpty())
	{
		return elem[front];
	}
	throw OUT_OF_BOUND();
}
template <class elemType>
void seqQueue<elemType>::doubleSpace()
{
	elemType* temp=elem;
	elem = new elemType[2 * maxSize];
	for (int i = 1;i < maxSize;i++)
	{
		temp[i] = elem[front+i];
	}
	max *= 2;
	front = 0;
	rear = maxSize - 1;
	delete temp;
}