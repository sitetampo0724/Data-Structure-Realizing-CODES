#pragma once
template <class elemType>
class linkQueue {
private:
	struct node {
		elemType data;
		node* next;
		node() :next(NULL) {}
		node(const elemType& x, node* q) :data(x), next(q = NULL) {}
	};
	node* rear;
public:
	linkQueue() { rear = NULL; }
	~linkQueue() {
		node* temp;
		node* delp;
		if (rear == NULL)return;
		temp = rear->next;
		rear->next = NULL;
		while (temp != NULL)
		{
			delp = temp;
			temp = temp->next;
			delete delp;
		}
	}
	bool isEmpty()const {return rear==NULL}
	void enQueue(const elemType & x)
	{
		if (rear == NULL)
		{
			rear = new node(x);
			rear->next = rear;
		}
		rear=rear->next = new node(x, rear->next);
	}
	elemType deQueue()
	{
		if (!isEmpty())
		{
			node* temp = temp = rear->next;
			elemType value = temp->data;
			if (rear == temp) rear = NULL;
			else rear = temp->next;
			delete temp;
			return value;
		}
	}
};