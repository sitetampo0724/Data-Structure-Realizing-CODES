#pragma once
#include <iostream>
using namespace std;
class OUT_OF_BOUND {
	const char* p;
public:
	OUT_OF_BOUND() :p("out of range!") {}
	void what() { cout << p << endl; }

};
template <class elemType>
class queue {
public:
	virtual bool isEmpty() const= 0;
	virtual void enQueue(const elemType& x) = 0;
	virtual elemType deQueue() = 0;
	virtual elemType getHead() const= 0;
	virtual ~queue() {};
};