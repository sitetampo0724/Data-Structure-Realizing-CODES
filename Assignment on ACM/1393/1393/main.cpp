#include <iostream>
using namespace std;
class Link
{
public:
	struct node {
		int data;
		node* next;
		node* prev;
		node() : prev(nullptr), next(nullptr) {}
		node(int a, node* q, node* p) : data(a), prev(q), next(p) {}
		~node() {}
	};
private:
	node* head;
	node* tail;
	int currentLength;
public:
	Link();
	node* getTail() { return tail; }
	node* getHead() { return head; }
	void pushback(int x);
	void pushfront(int x);
	void display();
};
Link::Link()
{
	head = new node;
	tail = new node;
	head->next = tail;
	tail->prev = head;
	currentLength = 0;
}
void Link::pushback(int x)
{
	node* temp;
	temp = new node(x, tail->prev, tail);
	tail->prev->next = temp;
	tail->prev = temp;
	currentLength++;
}
void Link::pushfront(int x)
{
	node* temp;
	temp = new node(x, head, head->next);
	head->next->prev = temp;
	head->next = temp;
	currentLength++;
}
Link* add(Link* num1, Link* num2)
{
	Link* res = new Link;
	Link::node* p = num1->getTail()->prev;
	Link::node* q = num2->getTail()->prev;
	Link::node* head1 = num1->getHead();
	Link::node* head2 = num2->getHead();
	int carry = 0;
	while (p != head1 && q != head2)
	{
		int temp = p->data + q->data+carry;
		carry =temp/10;
		res->pushfront(temp%10);
		p = p->prev;
		q = q->prev;
	}
	if (p == head1 && q == head2 && carry == 1)
	{
		res->pushfront(carry);
		carry = 0;
	}
	while (p != head1)
	{
		int temp = p->data + carry;
		carry = temp / 10;
		res->pushfront(temp % 10);
		p = p->prev;
	}
	while (q != head2)
	{
		int temp = q->data + carry;
		carry = temp/10;
		res->pushfront(temp%10);
		q = q->prev;
	}
	if (carry == 1)
	{
		res->pushfront(carry);
		carry = 0;
	}
	return res;
}
void Link::display()
{
	node* p=head->next;
	while (p != tail)
	{
		cout << p->data << " ";
		p=p->next;
	}
}
int main()
{
	Link *num1, *num2, *num3;
	num1 = new Link;
	num2 = new Link;
	int a, b;
	cin >> a >> b;
	for (int i = 0;i < a;i++)
	{
		int temp;
		cin >> temp;
		num1->pushback(temp);
	}
	for (int i = 0;i < b;i++)
	{
		int temp;
		cin >> temp;
		num2->pushback(temp);
	}
	num3 = add(num1,num2);
	num3->display();
}
