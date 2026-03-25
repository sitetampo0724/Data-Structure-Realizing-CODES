#include "stack.h"
#include <iostream>
using namespace std;
int main()
{
	Stack stack;
	int row, col;
	cout << "plz input row & column" << endl;
	cin >> row >> col;
	int** map;
	map = new int* [row];
	for (int i = 0;i < row;i++) map[i] = new int[col];
	Point location;
	while (location.x != row || location.y != col)
	{
		if (location.x < row) 
		{
			location.x++;
			stack.push(location);
			if (stack.top() == 1)
			{
				stack.pop();
				location.y++;
				stack.push(location);
			}
		}
		else
		{
			location.y++;
			stack.push(location);
			if (stack.top() == 1)
			{
				stack.pop();
				location.y++;
				stack.push(location);
			}
		}
		
		cout << location.x << "," << location.y << endl;
	}
	for (int i = 0;i < row;i++) delete[] map[i];
	delete[] map;
	return 0;
}