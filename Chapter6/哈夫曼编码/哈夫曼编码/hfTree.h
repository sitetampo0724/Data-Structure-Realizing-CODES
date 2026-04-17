#pragma once
#include <string>
using namespace std;
template <class T>
class hfTree {
private:
	struct Node {
		T data;
		int left, right;
		int parent;
		int weight;
	};
	int currentLength;
	Node* elem;
public:
	hfTree(const T* v,const int* w,int size);
	~hfTree() { delete[]elem; }
	struct hfCode {
		T data;
		string code;
	};
	void getCode(hfCode result[]);
};

template <class T>
hfTree<T>::hfTree(const T* v, const int* w, int size)
{
	const int MAX_INT = 32767;
	currentLength = size*2;
	elem = new Node[2 * size];
	for (int i = 0; i < currentLength; i++) {
		elem[i].parent = elem[i].left = elem[i].right = 0;
		elem[i].weight = 0;
	}

	for (int i = size; i < currentLength; i++)
	{
		elem[i].data = v[i - size];
		elem[i].weight = w[i - size];
		elem[i].parent = elem[i].left = elem[i].right = 0;
	}

	for (int i = size - 1; i > 0; i--)
	{
		int min1(MAX_INT), min2(MAX_INT);
		int index1(-1), index2(-1);
		
		for (int j = i + 1; j < currentLength; j++)
		{
			if (elem[j].parent==0&&min1 > elem[j].weight)
			{
				min2 = min1;
				min1 = elem[j].weight;
				index2 = index1;
				index1 = j;
			}
			else if (elem[j].parent == 0 && min2 > elem[j].weight)
			{
				min2 = elem[j].weight;
				index2 = j;
			}
		}
		elem[i].weight = min1 + min2;
		elem[i].left = index1;
		elem[i].right = index2;
		elem[index1].parent = i;
		elem[index2].parent = i;
	}
}

template <class T>
void hfTree<T>::getCode(hfTree<T>::hfCode result[])
{
	int size = currentLength / 2;
	
	for (int i = size;i < currentLength;i++)
	{
		int p, c;
		result[i - size].data = elem[i].data;
		result[i - size].code = "";
		p = elem[i].parent;
		c = i;
		while (p != 0)
		{
			if (elem[p].left == c)
				result[i - size].code = "0" + result[i - size].code;
			else
				result[i - size].code = "1" + result[i - size].code;
			c = p;
			p = elem[p].parent;
		}

	}
}