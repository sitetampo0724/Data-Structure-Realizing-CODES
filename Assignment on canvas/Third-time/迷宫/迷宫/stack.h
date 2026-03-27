#pragma once
#include <iostream>
using namespace std;
struct Point {
	int x;
	int y;
	Point(int m=0, int n=0) :x(m), y(n) {}
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
    Stack() : head(nullptr) {}
	void push(const Point& i) {
		head = new node(i, head);
	}
	void pop() {
		if (head) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	Point top() {
		if (head) return head->point;
		return Point();
	}
	bool empty() const { return head == nullptr; }
	void traverse() {
		node* index = head;
		while (index != nullptr)
		{
			cout << "(" << index->point.x << "," << index->point.y << ") ";
			index = index->next;
		}

	}
};