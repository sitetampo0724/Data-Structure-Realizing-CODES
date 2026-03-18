#include <iostream>
using namespace std;
int main()
{
	int* A, * B, * C;
	int a, b;
	cin >> a >> b;
	A = new int[a];
	B = new int[b];
	C = new int[a + b];
	for (int temp1 = 0;temp1 < a;temp1++)
	{
		cin >> A[temp1];
	}
	for (int temp2 = 0;temp2 < b;temp2++)
	{
		cin >> B[temp2];
	}
	int i = 0;
	int j = 0;
	int k = 0;
	int lastvalue;
	while (i < a && j < b)
	{
		if (A[i] < B[j])
		{
			if (k==0||lastvalue != A[i])
			{
				lastvalue = A[i];
				C[k] = lastvalue;
				k++;
			}
			i++;
			
		}
		else if (A[i] > B[j])
		{
			if (k == 0 || lastvalue != B[j])
			{
				lastvalue = B[j];
				C[k] = lastvalue;
				k++;
			}
			j++;
		}
		else
		{
			int current = A[i];
			while (i < a && A[i] == current)i++;
			while (j < b && B[j] == current)j++;
		}
	}
	while (i < a)
	{
		if (k == 0 || lastvalue != A[i])
		{
			lastvalue = A[i];
			C[k] = lastvalue;
			k++;
		}
		i++;
	}
	while (j < b)
	{
		if (k == 0 || lastvalue != B[j])
		{
			lastvalue = B[j];
			C[k] = lastvalue;
			k++;
		}
		j++;
	}
	if (k == 0)
	{
		cout << "Empty";
	}
	for (int i = 0;i < k;i++)
	{
		cout << C[i] << " ";
	}
	delete[] A;
	delete[] B;
	delete[] C;


	return 0;
}