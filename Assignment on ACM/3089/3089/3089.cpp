// 3089.cpp : Defines the entry point for the application.
//

#include<iostream>
using namespace std;

int search(int* grades, int size, int target, int low, int high)
{
	int minimum;
	int mid = (low + high) / 2;
	if (low > high) { return low; }
	if (grades[mid] >= target) return search(grades, size, target, low, mid - 1);
	else return search(grades, size, target, mid + 1, high);
}

int main()
{
	int n, m, q;
	cin >> n >> m >> q;
	int* grades_a = new int[n];
	int* grades_b = new int[m];
	for (int i = 0; i < n; i++)
		cin >> grades_a[i];
	for (int i = 0; i < m; i++)
		cin >> grades_b[i];
	int  target;
	int final_a,final_b;
	for (int i = 0;i < q;i++)
	{
		cin >> target;
		final_a = search(grades_a, n, target, 0, n - 1) + 1;
		if (final_a > n) final_a = 0;
		final_b = search(grades_b, m, target, 0, m - 1) + 1;
		if (final_b > m) final_b = 0;
		cout << (final_a + final_b)  << endl;
	}
	return 0;
}