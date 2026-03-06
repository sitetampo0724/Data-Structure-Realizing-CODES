#include "algorithm_.h"
#include <iostream>
using namespace std;
int Algorithm_::MAX_1(int a[], int size, int& start, int& end)
{
	int max_sum=0,max = 0;
	for(int i=0;i<size;i++)
		for (int j = i;j < size;j++)
		{
			max_sum = 0;
			for (int k = i;k <= j;k++)
				max_sum += a[k];
			if (max_sum > max)
			{
				max = max_sum;
				start = i;
				end = j;
			}
		}
	cout << "this is an O(n^3) algorithm,the biggest sum in sub-arrange is " << max << " ,which starts from " << start << " to " << end << endl;
	return max;
}
int Algorithm_::MAX_2(int a[], int size, int& start, int& end)
{
	int max_sum=0, max = 0;
	for (int i = 0;i < size;i++)
	{
		max_sum = 0;
		for (int j = i;j < size;j++)
		{
			max_sum += a[j];
			if (max_sum > max)
			{
				max = max_sum;
				start = i;
				end = j;
			}
		}
	}
		
	cout << "this is an O(n^2) algorithm,the biggest sum in sub-arrange is " << max << " ,which starts from " << start << " to " << end << endl;
	return max;
}
int Algorithm_::MAX_3(int a[], int size, int& start, int& end)
{
	int max_sum=0, max=0 ,start_temp= 0;
	for (int i = 0;i < size;i++)
	{
		max_sum +=a[i];
		if (max_sum < 0)
		{
			start_temp = i + 1;
			max_sum = 0;
		}
		else if (max_sum > max)
		{
			max = max_sum;
			start = start_temp;
			end = i;
		}
	}
	cout << "this is an O(n) algorithm,the biggest sum in sub-arrange is " << max << " ,which starts from " << start << " to " << end << endl;
	return max;
}