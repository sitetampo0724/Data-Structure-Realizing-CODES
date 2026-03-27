#include "stack.h"
enum direction { left_point, right_point, up_point, down_point };
void walk(enum direction type, Point& location, int a[][5]);
bool check(int x, int y, int map[][5], int visited[][5]);
int main()
{
	Stack stack;
    stack.push(Point(0, 0));
	int row=5, col=5;
	int map[5][5] = {
	{0, 0, 0, 0, 0 },
	{ 1, 1, 1, 1, 0 },
	{ 1, 0, 0, 0, 0 },
	{ 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 0, 0 } };
	int visited[5][5] = {
	{1, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0 } };
    Point location;
	Point temp;
	bool beacon = 1;
	bool isPath = 1;
    while (location.x != row-1 || location.y != col-1)
	{
		beacon = 1;
		if (check(location.x, location.y-1, map, visited)) {
			walk(left_point, location, visited);
			stack.push(location);
			beacon = 0;
			location = stack.top();
			continue;
		}
		if (check(location.x, location.y+1, map, visited)) {
			walk(right_point, location, visited);
			stack.push(location);
			beacon = 0;
			location = stack.top();
			continue;
		}
		if (check(location.x-1, location.y, map, visited)) {
			walk(up_point, location, visited);
			stack.push(location);
			beacon = 0;
			location = stack.top();
			continue;
		}
		if (check(location.x+1, location.y, map, visited)) {
			walk(down_point, location, visited);
			stack.push(location);
			beacon = 0;
			location = stack.top();
			continue;
		}

		if (beacon == 1) {
			stack.pop();
			if (stack.empty())
			{
				isPath = 0;
				break;
			}
			location = stack.top();
		}
	}
	if (isPath) stack.traverse();
	else cout << "No Path" << endl;
	return 0;
}
void walk(enum direction type,Point &location,int a[][5])
{
	switch (type) {
    case left_point: {
		location.y--;
		a[location.x][location.y] = 1;
		break;
	}
	case right_point: {
		location.y++;
		a[location.x][location.y] = 1;
		break;
	}
	case up_point: {
		location.x--;
		a[location.x][location.y] = 1;
		break;
	}
	case down_point: {
		location.x++;
		a[location.x][location.y] = 1;
		break;
	}
	}
}
bool check(int x,int y, int map[][5], int visited[][5])
{
	if (x < 0 || x >= 5 || y < 0 || y >= 5)
		return false;
	if (map[x][y] == 1)
		return false;
	if (visited[x][y] == 1)
		return false;
	return true;
}