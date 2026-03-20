#pragma once
template <class object>
class List
{
	struct node
	{
		object data;
		node* next;
		node() :next(NULL){}
		node(const onject& x, node* q) :data(x), next(q) {}
		~node() {}
	};
	int currentLength;
	node* head;
public:
	List() {
		head = new node;
		currentLength = 0;
	}
	void Invert();
	~List() {}
};
template <class object>
void List<object>::Invert()
{
	node* current(head->next), * next, * prev(nullptr);
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head->next = prev;
}