#pragma once
#include <iostream>
class Node
{
public:
	int cof, exp;
	Node* next;
	Node() :next(NULL) {}
	Node(int a, int b, Node* p) :cof(a), exp(b), next(p) {}
	~Node() {}
};
Node* add(Node* exp1, Node* exp2)
{
	Node* res, * p;
	res = p = new Node;
	exp1 = exp1->next;
	exp2 = exp2->next;
	while (exp1 != NULL && exp2 != NULL)
	{
		if (exp1->exp < exp2->exp)
		{
			p->next = new Node(exp1->cof, exp1->exp, NULL);
			exp1 = exp1->next;
		}
		else if (exp1->exp > exp2->exp)
		{
			p->next = new Node(exp2->cof, exp2->exp, NULL);
			exp2 = exp2->next;
		}
		else if (exp1->cof + exp2->cof != 0)
		{
			p->next = new Node(exp1->cof + exp2->cof, exp2->exp, NULL);
			exp2 = exp2->next;
			exp1 = exp1->next;
		}
		p = p->next;
	}
	if (exp1 != NULL)
	{
		while (exp1 != NULL)
		{
			p->next = new Node(exp1->cof, exp1->exp, NULL);
			exp1 = exp1->next;
			p = p->next;
		}
	}
	if (exp2 != NULL)
	{
		while (exp2 != NULL)
		{
			p->next = new Node(exp2->cof, exp2->exp, NULL);
			exp2 = exp2->next;
			p = p->next;
		}
	}
	return res;
}