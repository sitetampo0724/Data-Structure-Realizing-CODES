#pragma once
#include "List.h"
#include <iostream>
template <class elemType>
class seqList:public List<elemType>
{
private:
	elemType* data;
	int currentLength;
	int maxSize;
public:
	seqList(int initial = 10);
	~seqList() { delete[] data; }
	void clear() { currentLength = 0; }
	int length() const;
	void insert(int i, const elemType& x);
	void remove(int i);
	int search(const elemType& x) const;
	elemType visit(int i)const;
	void traverse()const;
	void doubleSpace();//课上补充
	void erase(int i);//problem in page 31
};

template <class elemType>
seqList<elemType>::seqList(int initial)
{
	data = new elemType[initial];
	maxSize = initial;
	currentLength = 0;
}

template <class elemType>
int seqList<elemType>::length() const
{
	std::cout << "length is " << currentLength << std::endl;
	return currentLength;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType& x)
{
	if (i < 0 || i > currentLength)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	if (currentLength >= maxSize)
	{
		doubleSpace();
	}
	for (int j = currentLength; j > i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i] = x;
	currentLength++;
}

template <class elemType>
void seqList<elemType>::remove(int i)
{
	if (i < 0 || i >= currentLength)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	for (int j = i; j < currentLength - 1; j++)
	{
		data[j] = data[j + 1];
	}
	currentLength--;
}

template <class elemType>
int seqList<elemType>::search(const elemType& x) const
{
	for (int i = 0; i < currentLength; i++)
	{
		if (data[i] == x)
		{
			std::cout << "the number is at " << i << std::endl;
			return i;
		}
	}
	std::cout << "Not found" << std::endl;
	return -1;
}

template <class elemType>
elemType seqList<elemType>::visit(int i)const
{
	if (i < 0 || i >= currentLength)
	{
		std::cout << "Index out of range" << std::endl;
		return elemType();
	}
	std::cout << data[i] << std::endl;
	return data[i];
}

template <class elemType>
void seqList<elemType>::traverse()const
{
	for (int i = 0; i < currentLength; i++)
	{
		std::cout << data[i] << std::endl;
	}
}

template <class elemType>
void seqList<elemType>::doubleSpace()
{
	elemType* temp = data;
	maxSize *= 2;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; i++)
	{
		data[i] = temp[i];
	}
	delete[] temp;
}

template <class elemType>
void seqList<elemType>::erase(int i)
{
	elemType flag = data[i];
	while (search(flag) != -1)
	{
		remove(search(flag));
	}
}