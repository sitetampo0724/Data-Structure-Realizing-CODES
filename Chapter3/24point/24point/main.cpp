#include "calc.h"
#include <cstdlib>
#include <ctime>
void getFourDigits(int digits[4]) {
	static bool init = false;
	if (!init) {
		srand(time(NULL));
		init = true;
	}
	for (int i = 0; i < 4; i++) {
		digits[i] = rand() % 9+1;
	}
}
void point(int num,int &count)
{
	if (num == 24)
	{
		cout << "Good Job!" << endl;
		count++;
		cout << "current credit is " << count << endl;
	}
	else
		cout << "Noob" << endl;
}
int main()
{
	int digits[4];
	int count = 0;
	cout << "you can input \"quit\" to quit the game" << endl;
	string p;
	while (p != "quit")
	{
	getFourDigits(digits);
	for (int i = 0;i < 4;i++)
	{
		cout << digits[i] << " ";
		
	}
	cout << endl;
	getline(cin, p);
	char* a;
	a = new char[p.length() + 1];
	for (int i = 0;i < p.length();i++)
	{
		a[i] = p[i];
	}
	a[p.length()] = 0;
	calc result(a);
	point(result.result(), count);
	delete[] a;
	}
	
	
	
	return 0;
}
