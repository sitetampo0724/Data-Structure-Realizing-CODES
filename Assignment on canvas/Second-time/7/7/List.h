#pragma once
template <class object>
class List
{
	object* p;
	int currentLength, capacity;
public:
	List(int x) {
		p = new object[x];
		capacity = x;
		currentLength = 0;
	}
	~List() {delete []p}
	List operator+(const List& r1)const;
	List& operator=(const List& r1);
};
template <class object>
List<object> List<object>::operator + (const List& r1)const
{
	object* temp;
	List res(capacity + r1.capacity);
	int k(0);
	for (int i = 0;i < currentLength;i++,k++)
	{
		res.p[k] = p[i];
	}
	for (int i = 0;i < r1.currentLength;k++, i++)
	{
		res.p[k] = r1.p[i];
	}
	return res;
}
template <class object>
List<object>& List<object>::operator=(const List& r1)
{
	if (this == &r1) return *this;
	else
	{
		delete[]p;
		capacity = r1.capacity;
		currentLength = r1.currentLength;
		p = new object[capacity];
		for (int i = 0;i < currentLength;i++)
		{
			p[i] = r1.p[i];
		}
	}
	return *this;
}