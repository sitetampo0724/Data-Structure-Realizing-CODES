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
int Algorithm_::MAX_3(int a[], int size, int& start, int& end)//it is called 包裹函数
{
	int max = max_sum(a, 0, size - 1, start, end);
	cout << "this is an O(n^logn) algorithm,the biggest sum in sub-arrange is " << max << " ,which starts from " << start << " to " << end << endl;
	return max;
}
int Algorithm_::max_sum(int a[], int left, int right, int& start, int& end)
{
	int MaxLeft, MaxRight, center;
	int StartL, StartR, EndL, EndR;
	int left_sum = 0, right_sum = 0;//to describe cross-array
	int Maxlefttemp(0), Maxrighttemp(0);//
	if (left == right)
	{
		start = end = left;
		return a[left]>0 ? a[left]:0;
	}
	center = (left + right) / 2;
	MaxLeft = max_sum(a,left,center,StartL,EndL);
	MaxRight = max_sum(a,center+1,right, StartR, EndR);
	for (int i = center;i >= left;i--)
	{
		left_sum += a[i];
		if (left_sum > Maxlefttemp)
		{
			StartL = i;
			EndL = center;
			Maxlefttemp = left_sum;
		}
	}
	for (int i = center + 1;i <= right;i++)
	{
		right_sum += a[i];
		if (right_sum > Maxrighttemp)
		{
			StartR = center+1;
			EndR = i;
			Maxrighttemp = right_sum;
		}
	}
	if (MaxLeft >= MaxRight && MaxLeft >= Maxrighttemp + Maxlefttemp)
	{
		start = StartL;
		end = EndL;
		return MaxLeft;
	}
	else if (MaxRight >= MaxLeft && MaxRight >= Maxrighttemp + Maxlefttemp)
	{
		start = StartR;
		end = EndR;
		return MaxRight;
	}
	else
	{
		start = StartL;
		end = EndR;
		return Maxrighttemp + Maxlefttemp;
	}


}
int Algorithm_::MAX_4(int a[], int size, int& start, int& end)
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