#pragma once
#include <stack>
#include <iostream>
using namespace std;

template <typename T>
class binaryTree {
private:
	int size;
	int currentSize;
	T* data;
	struct Node {
		int index;
		int time;
		Node(const int v): index(v), time(0) {}
	};
public:
	binaryTree(int t=10):size(t), currentSize(0){
		data = new T[size + 1];
	}
	binaryTree(T* a, int s) :size(s), currentSize(s) {
		data = new T[size+1];
		for (int i = 0; i < size; i++)
		{
			data[i + 1] = a[i];
		}
	}
	~binaryTree() { delete[]data; }
	void downorder();
	void midorder();
	void preorder();
	
};

template <typename T>
void binaryTree<T>::preorder()
{
	if (currentSize == 0) return;
	stack<int> s;
	s.push(1);
	int index;
	while (!s.empty())
	{
		index = s.top();
		s.pop();
		cout << data[index] << endl;
		// push right first so left is processed before right
		if (index * 2 + 1 <= currentSize)
			s.push(index * 2 + 1);
		if (index * 2 <= currentSize)
			s.push(index * 2);
	}
}

template <typename T>
void binaryTree<T>::midorder()
{
	if (currentSize == 0) return;
	stack<Node> s;
	s.push(Node(1));
	Node current(0);
	while (!s.empty())
	{
		current = s.top();
		s.pop();
		current.time++;
		if (current.time == 2)
		{
			cout << data[current.index] << endl;
			if (current.index * 2 + 1 <= currentSize)
			{
				s.push(Node(current.index * 2 + 1));
			}
		}
		else if (current.time == 1)
		{
			s.push(current);
			if (current.index * 2 <= currentSize)
			{
				s.push(Node(current.index * 2));
			}
		}
	}

}

template <typename T>
void binaryTree<T>::downorder()
{
	if (currentSize == 0) return;
	stack<Node> s;
	Node current(1);
	s.push(current);
	while (!s.empty())
	{
		current = s.top();
		s.pop();
		current.time++;
		if (current.time == 3)
		{
			cout << data[current.index] << endl;
			continue;
		}
		s.push(current);
		if (current.time == 2)
		{
			if (current.index * 2 + 1 <= currentSize)
				s.push(Node(current.index * 2 + 1));
		}
		else
		{
			if (current.index * 2 <= currentSize)
				s.push(Node(current.index * 2));
		}
	}
}

