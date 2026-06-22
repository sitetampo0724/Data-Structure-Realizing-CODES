#pragma once
#include "queue.h"
#pragma once
template <class elemType>
class linkQueue :public queue<elemType> {
private:
	struct node {
		node* next;
		elemType x;
		node():next(nullptr) {}
		node(node* p,const elemType& data):next(p),x(data){}
	};
	node* front, * rear;
public:
	linkQueue();
	~linkQueue();
	bool isEmpty()const;
	void enQueue(const elemType& x);
	elemType deQueue();
	elemType getHead()const;
};
template <class elemType>
linkQueue<elemType>::linkQueue()
{
	rear = front = nullptr;
}
template <class elemType>
linkQueue<elemType>::~linkQueue()
{
	while (front != NULL)
	{
		node* temp;
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
}
template <class elemType>
bool linkQueue<elemType>::isEmpty()const
{
	if (rear == nullptr)
		return true;
	return false;
}
template <class elemType>
void linkQueue<elemType>::enQueue(const elemType& x)
{
	if (!isEmpty())
	{
		rear=rear->next = new node(nullptr, x);
	}
	rear = front = new node(nullptr, x);
	
}
template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
	if (isEmpty())
	{
		OUT_OF_BOUND();
	}
	elemType value = front->data;
	node* temp = front;
	front = front->next;
	if (front == nullptr)rear = nullptr;
	delete temp;
	return value;
}
template <class elemType>
elemType linkQueue<elemType>::getHead()const
{
	if (isEmpty())
	{
		throw OUT_OF_BOUND();
	}
	return front->data;
}