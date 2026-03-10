#include <iostream>
int cal(int k)
{
	int sum = 0;
	int currentNum = 1;
	for (int i = 1;i <= k;i++)
	{
		currentNum *= i;
		sum += currentNum;
	}
	return sum;
}
int main()
{
	int k;
	std::cout << "Enter a number: ";
	std::cin >> k;
	std::cout << cal(k);
	return 0;
}