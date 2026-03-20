#pragma once
template <class object>
class List
{
private:
	struct node {
	    object data;
		node* next;
		node() :next(NULL) {}
		node(const object& x, node* q) :data(x), next(q) {}
		~node() {}
	};
	node* head;
	int currentLength;
public:
	List() {
		head = new node;
		currentLength = 0;
	}
	void erase(int x, int y);
	~List() {}
};
template <class object>
void List<object>::erase(int x, int y)
{
	node* p;
	p = head->next;
	while (p != NULL)
	{
		if (p->data >= x && p->data <= y)
		{
			node* temp=p->next;
			p->next = temp->next;
			delete temp;
			currentLength--;
		}
		p = p->next;
	}
}