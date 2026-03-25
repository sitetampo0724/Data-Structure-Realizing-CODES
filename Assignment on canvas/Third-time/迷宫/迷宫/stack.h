#pragma once
struct Point {
	int num;
	int x;
	int y;
	Point(int j=0,int m=1, int n=1) :num(j),x(m), y(n) {}
};
class Stack {
	struct node{
		Point point;
		node* next;
		node() :next(nullptr) {}
		node(const Point & i, node* q) :point(i), next(q) {}
	};
	node* head;
public:
	Stack() {
		head = nullptr;
	}
	void push(const Point& i) {
		head = new node(i, head);
	}
	int pop() {
		node* temp = head;
		int i = temp->point.num;
		head = head->next;
		delete temp;
		return i;
	}
	int top()
	{
		return head->point.num;
	}
};