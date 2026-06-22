#pragma once
#include "Set.h"

template <class KEY,class OTHER>
class SORT
{
public:
	void simpleInsertSort(SET<KEY, OTHER> a[], int size);

	void shellSort(SET<KEY, OTHER> a[], int size);

	void simpleSelectSort(SET<KEY, OTHER> a[], int size);

	void heapSort(SET<KEY, OTHER> a[], int size);
	void perlocateDown(SET<KEY, OTHER>a[], int hole, int size);

	void bubbleSort(SET<KEY, OTHER> a[], int size);

	void quickSort(SET<KEY, OTHER> a[], int size);
	void quickSort(SET<KEY, OTHER> a[], int low,int high);
	int divide(SET<KEY, OTHER> a[], int low, int high);

	void mergeSort(SET<KEY, OTHER> a[], int size);
	void mergeSort(SET<KEY, OTHER> a[], int low, int high);
	void merge(SET<KEY, OTHER> a[], int low, int mid, int high);

	struct node {
		SET<int, OTHER> data;
		node* next;

		node() { next = nullptr; }
		node(SET<int, OTHER> d) :data(d) { next = nullptr; }
	};
	void bucketSort(node* &p);
};


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::simpleInsertSort(SET<KEY, OTHER> a[], int size)
{
	int j;
	SET<KEY, OTHER> temp;
	for (int i = 1;i < size;i++)
	{
		temp = a[i];
		for (j = i - 1;j >= 0 && a[j].key > temp.key;j--)
		{
			a[j+1] = a[j];
		}
		a[j+1] = temp;
	}
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::shellSort(SET<KEY, OTHER> a[], int size)
{
	int step, i, j;
	SET<KEY, OTHER> temp;
	for (step = size / 2;step > 0;step /= 2)
	{
		for (i = step;i < size;i++)
		{
			temp = a[i];
			for (j = i - step;j >= 0 && a[j].key > temp.key;j -= step)
			{
				a[j + step] = a[j];
			}
			a[j + step] = temp;
		}
	}
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::simpleSelectSort(SET<KEY, OTHER> a[], int size)
{
	int i, j, min;
	SET<KEY, OTHER> temp;
	for (i = 0;i < size - 1;i++)
	{
		min = i;
		for (j = i + 1;j < size;j++)
			if (a[j].key < a[min].key) min = j;
		temp = a[min];
		a[min] = a[i];
		a[min] = temp;
	}
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::heapSort(SET<KEY, OTHER> a[], int size)
{
	int i;
	SET<KEY, OTHER> temp;

	for (i = size / 2 - 1;i >= 0;i--)
		perlocateDown(a, i, size);

	for (i = size - 1;i > 0;i--) {
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		perlocateDown(a, 0, i);
	}
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::perlocateDown(SET<KEY, OTHER>a[], int hole, int size)
{
	int child;
	SET<KEY, OTHER> temp = a[hole];

	for (;hole * 2 + 1 < size;hole = child)
	{
		child = hole * 2 + 1;
		if (child != size - 1 && a[child + 1].key > a[child].key)
			child++;
		if (a[child].key > temp.key) a[hole] = a[child];
		else break;
	}

	a[hole] = temp;
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::bubbleSort(SET<KEY, OTHER> a[], int size)
{
	int i, j;
	SET<KEY, OTHER> temp;
	bool flag = true;

	for (int i = 0;i < size && flag;i++)
	{
		flag = false;
		for(int j=0;j<size-i;++j)
			if (a[j + 1].key < a[j].key)
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j + 1] = temp;
				flag = true;
			}
	}
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::quickSort(SET<KEY, OTHER> a[], int low, int high)
{ 

	int mid;
	if (low >= high) return;

	mid = divide(a, low, high);
	quickSort(a, low, mid - 1);
	quickSort(a, mid, high);

}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::quickSort(SET<KEY, OTHER> a[], int size)
{
	quickSort(a, 0, size - 1);
}


template <class KEY, class OTHER>
int SORT<KEY, OTHER>::divide(SET<KEY, OTHER> a[], int low, int high)
{
	SET<KEY, OTHER> temp = a[low];
	do {
		while (low<high && a[high].key>temp.key)high--;
		if (low < high) {
			a[low] = a[high];
			low++;
		}
		while (low < high && a[low].key < temp.key)low++;
		if (low < high) {
			a[high] = a[low];
			high--;
		}
	} while (high != low);
	a[low] = temp;
	return low;
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::mergeSort(SET<KEY, OTHER> a[], int size)
{
	mergeSort(a, 0, size - 1);
}

template <class KEY, class OTHER>
void SORT<KEY, OTHER>::mergeSort(SET<KEY, OTHER> a[], int low, int high)
{
	if (low >= high) return;

	int mid = (low + high) / 2;
	mergeSort(a, low, mid);
	mergeSort(a, mid + 1, high);
	merge(a, low, mid, high);
}

template <class KEY, class OTHER>
void SORT<KEY, OTHER>::merge(SET<KEY, OTHER> a[], int low, int mid, int high)
{
	SET<KEY, OTHER>* temp = new SET<KEY, OTHER>[high - low + 1];

	int i = low, j = mid+1,k = 0;

	while (i < mid && j <= high)
		if (a[i].key < a[j].key) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	while (i < mid) temp[k++] = a[i++];
	while (j <=high)temp[k++] = a[j++];

	for (int i = 0, k = low;k <= high;)
		a[k++] = temp[i++];

	delete[]temp;
}


template <class KEY, class OTHER>
void SORT<KEY, OTHER>::bucketSort(node*& p)
{
	node* buckets[10], last* [10], *tail;
	int i, j, k, base = 1, max = 0, len = 0;

	for (tail = p;tail != nullptr;tail = tail->next)
		if (tail->data.key > max)
			max = tail->data.key;

	if (max == 0) len = 0;
	else while (max > 0) { ++len;max /= 10;}

	for (i = 0;i < len;i++){
		for (j = 0;j < 10;j++) bucket[j] = last[j] = nullptr;// it is extremely critical
		while (p != nullptr) {
			k = p->data.key / base % 10;
			if (bucket[k] == nullptr) bucket[k] = last[k] = p;
			else last[k] = last[k]->next = p;
			p = p->next;
		}

		p = nullptr;

		for (j = 0;j < 10;j++) {
			if (bucket[j] == nullptr) continue;
			if (p == nullptr) p = bucket[j];
			else tail->next = bucket[j];
			tail = last[j];
		}
		tail->next = nullptr;
		base *= 10;
	}

}

