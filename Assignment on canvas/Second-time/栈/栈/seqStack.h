#pragma once
#include "stack.h"
#include <iostream>
template <class elemType>
class seqStack :public Stack<elemType>
{
private:
	elemType* elem;
	int maxSize,top_p;
	void doubleSpace();
public:
	seqStack(int initialsize=10);
	~seqStack() {
		delete[]elem;
	}
	void push(const elemType& x);
	elemType pop();
	elemType top() const;
	bool isEmpty() const;
};
template <class elemType>
seqStack<elemType>::seqStack(int initialsize)
{
	elem = new elemType[initialsize];
	maxSize = initialsize;
	top_p = -1;
}
template <class elemType>
void seqStack<elemType>::doubleSpace()
{
	elemType* temp = elem;
	temp = new elemType[maxSize*2];
	for (int i = 0;i < maxSize;i++)
		temp[i] = elem[i];
	maxSize *= 2;
}
template <class elemType>
void seqStack<elemType>::push(const elemType& x)
{
	if (top_p == maxSize - 1)
	{
		doubleSpace();
	}
	elem[++top_p] = x;
}
template <class elemType>
elemType seqStack<elemType>::pop()
{
	//if (isEmpty)
	//{
	//	throw OUT_OF_BOUND;  this class I haven't realized
	//}
	return elem[top_p--];
}
template <class elemType>
elemType seqStack<elemType>::top() const
{
	return elem[top_p];
}
template <class elemType>
bool seqStack<elemType>::isEmpty() const
{
	if (top_p == -1)
	{
		return 1;
	}
	return 0;
}