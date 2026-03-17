#pragma once
#include "Link.h"
#include <iostream>
template <class elemType>
class dLinkList :public List<elemType>
{
private:
	struct node {
		elemType data;
		node* next, * prev;
		node(const elemType& x, node* p, node* q) :data(x), prev(p), next(q) {}
		node() :next(NULL), prev(NULL) {}
		~node() {}
	};
	int currentLength;
	node* head, * tail;
	node* move(int i)const;
public:
	dLinkList();
	~dLinkList() {}
	void clear();
	int length() const;
	void insert(int i, const elemType& x);
	void remove(int i);
	int search(const elemType& x) const;
	elemType visit(int i)const;
	void traverse()const;
	void erase(int i);
	void reverse();
};
template <class elemType>
dLinkList<elemType>::node* dLinkList<elemType>::move(int i) const
{
	node* temp = head;
	while (i-- >= 0)
	{
		temp = temp->next;
	}
	return temp;
}
template <class elemType>
dLinkList<elemType>::dLinkList()
{
	head = new node;
	tail = new node;
	head->next = tail;
	tail->prev = head;
	currentLength = 0;
}
template <class elemType>
void dLinkList<elemType>::clear()
{
	node* p, * q;
	p = head->next;
	while (p != tail)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->next = tail;
	currentLength = 0;
}
template <class elemType>
int dLinkList<elemType>::length() const
{
	return currentLength;
}
template <class elemType>
void dLinkList<elemType>::insert(int i, const elemType& x)
{
	node* pos, *temp;
	pos = move(i);
	temp = new node(x, pos->prev, pos);
	pos->prev->next = temp;
	pos->prev = temp;
	currentLength++;
}
template <class elemType>
void dLinkList<elemType>::remove(int i)
{
	node* pos;
	pos = move(i);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	currentLength--;
}
template <class elemType>
int dLinkList<elemType>::search(const elemType& x) const
{
	node* p = head->next;
	int i = 0;
	while (p != tail)
	{
		if (p->data == x)
			return i;
		i++;
		p = p->next;
	}
	return -1;
}
template <class elemType>
elemType dLinkList<elemType>::visit(int i)const
{
	std::cout << "number you want to find is " << move(i)->data << std::endl;
	return move(i)->data;
}
template <class elemType>
void dLinkList<elemType>::traverse()const
{
	node* p = head->next;
	while (p != tail)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
}
template <class elemType>
void dLinkList<elemType>::reverse()
{
	node* p=tail->prev;
	while (p != head)
	{
		std::cout << p->data << std::endl;
		p = p->prev;
	}
}