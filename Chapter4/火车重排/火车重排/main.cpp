#include <iostream>
#include <queue>
using namespace std;
bool putBuffer(queue<int>* q, int size, int in);
void checkBuffer(queue<int>* buffer, int size, int& last);
void arrange(int in[], int n, int k);
void arrange(int in[], int n, int k)
{
	static int last = 0;
	queue<int>* buffer = new queue<int>[k];
	for (int i = 0;i < n;i++)
	{
		if (!putBuffer(buffer, k, in[i]))
		{
			cout << "buffer is not big enough!" << endl;
			return;
		}
		checkBuffer(buffer, k, last);
	}
}
bool putBuffer(queue<int>* q, int size, int in)
{
	int avail = -1, max = 0;
	for (int i = 0;i < size;i++)
	{
		if (q[i].empty())
			avail = i;
		else if (in > q[i].back() && q[i].back() > max)
		{
			avail = i;
			max = q[i].back();
		}
	}
	if (avail == -1)
	{
		return false;
	}
	else
	{
		q[avail].push(in);
		return true;
	}
}
void checkBuffer(queue<int>* buffer, int size, int & last)
{
    for (int i = 0; i < size; i++)
	{
		while (!buffer[i].empty() && buffer[i].front() == last + 1)
		{
			cout << "pop " << buffer[i].front() << " from buffer " << i << endl;
			buffer[i].pop();
			last++;
		}
	}
}
int main()
{
	int in1[] = { 3,5,2,1,6,7,8,9,4,10 };
	arrange(in1,10,6);
	int in2[] = { 10,9,8,7,6,5,4,3,2,1 };
	arrange(in2, 10, 6);
	return 0;
}
