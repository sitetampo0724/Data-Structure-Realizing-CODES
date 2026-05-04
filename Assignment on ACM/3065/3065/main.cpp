#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0;i < n;i++)
	{	
		int Num;
		cin >> Num;
		switch (Num) {
		case 1: {
			int temp;
			cin >> temp;
			pq.push(temp);
			break;
		}
		case 2: {
			cout << pq.top() << endl;
			pq.pop();
			break;
		}
		default: break;
		}
			
	}
	return 0;
}