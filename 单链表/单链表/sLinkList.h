#pragma once
#include "Link.h"
#include <iostream>
template <class elemType>
class sLinkList :public List<elemType>
{
private:
	struct node {
		elemType data;
		node* next;
		node(const elemType &x,node* p) :data(x),next(p){}
		node() :next(NULL) {}
		~node() {}
	};
	int currentLength;
	node* head;
	node* move(int i)const;
public:
	sLinkList();
	~sLinkList() {}
	void clear();
	int length() const;
	void insert(int i, const elemType& x);
	void remove(int i);
	int search(const elemType& x) const;
	elemType visit(int i)const;
	void traverse()const;
	void erase(int i);
};
template <class elemType>
sLinkList<elemType>::node* sLinkList<elemType>::move(int i) const
{
	node* temp=head;
	while (i-- >= 0)
	{
		temp = temp-> next;
	}
	return temp;
}
template <class elemType>
sLinkList<elemType>::sLinkList() 
{
	head = new node;
	currentLength = 0;
}
template <class elemType>
void sLinkList<elemType>::clear()
{
	node* p, *q;
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->next = NULL;
	currentLength = 0;
}
template <class elemType>
int sLinkList<elemType>::length() const
{
	return currentLength;
}
template <class elemType>
void sLinkList<elemType>::insert(int i, const elemType& x)
{
	node* pos;
	pos = move(i - 1);
	pos->next = new node(x, pos->next);
	currentLength++;
}
template <class elemType>
void sLinkList<elemType>::remove(int i)
{
	node* temp,*pos;
	pos = move(i - 1);
	temp = pos->next;
	pos->next = temp->next;
	delete temp;
	currentLength--;
}
template <class elemType>
int sLinkList<elemType>::search(const elemType& x) const
{
	node* p = head->next;
	int i = 0;
	while (p != NULL)
	{
		if (p->data == x)
			return i;
		i++;
		p = p->next;
	}
	return -1;
}
template <class elemType>
elemType sLinkList<elemType>:: visit(int i)const
{
	std::cout << "number you want to find is "<<move(i)->data << std::endl;
	return move(i)->data;
}
template <class elemType>
void sLinkList<elemType>::traverse()const
{
	node* p = head->next;
	while (p != NULL)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
}
template <class elemType>
void sLinkList<elemType>::erase(int i)
{
	elemType val = visit(i);
	int find = search(val);
	while (find >= 0)
	{
		remove(find);
		find = search(val);
	}
}