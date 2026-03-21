#pragma once
#include "stack.h"
template <class elemType>
class linkStack :public Stack<elemType>
{
private:
	struct node {
		elemType data;
		node* next;
		node() :next(NULL){}
		node(const elemType& x, node* p = NULL){
			data = x;
			next = p;
		}
		~node() {}
	};
	node* top_p;
public:
	linkStack();
	~linkStack();
	bool isEmpty() const;
	void push(const elemType& x);
	elemType pop();
	elemType top()const;
};
template <class elemType>
linkStack<elemType>::linkStack()
{
	top_p = NULL;
}
template <class elemType>
linkStack<elemType>::~linkStack()
{
	node* temp;
	while (top_p != NULL)
	{
		temp = top_p;
		top_p = top_p->next;
		delete temp;
	}
	//p is already a nullptr,so the any operation about delete is redundant
}
template <class elemType>
bool linkStack<elemType>::isEmpty() const
{
	if (top_p == NULL)
		return 1;
	return 0;
}
template <class elemType>
void linkStack<elemType>::push(const elemType& x)
{
	top_p = new node(x, top_p);
}
template <class elemType>
elemType linkStack<elemType>::pop()
{ 
	node* temp = top_p;
	top_p = top_p->next;
	elemType x = temp->data;
	delete temp;
	return x;
}
template <class elemType>
elemType linkStack<elemType>::top()const
{
	return top_p->data;
}