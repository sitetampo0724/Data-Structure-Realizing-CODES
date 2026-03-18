#include <iostream>
template <class elemType>
class dLinkList
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
public:
	dLinkList();
	~dLinkList() {}
	int length() const;
	void pushback(const elemType& x);
	void reverse();
};
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
void dLinkList<elemType>::pushback(const elemType& x)
{
	node* temp;
	temp = new node(x, tail->prev, tail);
	tail->prev->next = temp;
	tail->prev= temp;
	currentLength++;
}
template <class elemType>
void dLinkList<elemType>::reverse()
{
	node* p = tail->prev;
	while (p != head)
	{
		std::cout << p->data <<" ";
		p = p->prev;
	}
}

int main()
{
	dLinkList<int> L;
	int a;
	std::cin >> a;
	for (int i = 0;i < a;i++)
	{
		int temp;
		std::cin >> temp;
		L.pushback(temp);
	}
	L.reverse();
	return 0;
}