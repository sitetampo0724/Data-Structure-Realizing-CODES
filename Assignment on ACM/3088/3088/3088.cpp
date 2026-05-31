// 3088.cpp : Defines the entry point for the application.
//

#include<iostream>
using namespace std;

int search(int* grades, int size, int target,int low,int high)
{
	int minimum;
	int mid = (low + high) / 2;
	if (low > high) { return low; }
	if(grades[mid]>=target) return search(grades, size, target, low, mid-1);
	else return search(grades, size, target, mid + 1, high);
}

int main()
{
	int n, q;
	cin >> n >> q;
	int* grades = new int[n];
	for(int i = 0; i < n; i++)
		cin >> grades[i];
	int  target;
	for (int i = 0;i < q;i++)
	{
		cin >> target;
		int temp = search(grades, n, target, 0, n - 1) + 1;
		if (temp > n) cout << 0 << endl;
		else cout << temp << endl;
	}
	return 0;
}
