#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
class simulator {
	int arriveLow;
	int arriveHigh;
	int serviceTimeLow;
	int serviceTimeHigh;
	int customNum;
public:
	simulator();
	int avgWaitTime()const;
};
simulator::simulator()
{
	cout << "input arriving time from low to high" << endl;
	cin >> arriveLow >> arriveHigh;
	cout << "input service time from low to high" << endl;
	cin >> serviceTimeLow >> serviceTimeHigh;
	cout << "input how many customers" << endl;
	cin >> customNum;
	srand(time(NULL));
}
int simulator::avgWaitTime()const
{
	queue<int> customQueue;
	int currentTime = 0;
	for (int i = 0;i < customNum;i++){
		currentTime += arriveLow + rand() % (arriveHigh - arriveLow+1);
		customQueue.push(currentTime);
	}
	currentTime = 0;
	int eventTime;
	int totalWaitTime=0;
	while(!customQueue.empty())
	{
		eventTime = customQueue.front();
		customQueue.pop();
		if (currentTime < eventTime) currentTime = eventTime;
		else totalWaitTime += currentTime - eventTime;
		currentTime += serviceTimeLow + rand() % (serviceTimeHigh - serviceTimeLow+1);
	}
	return totalWaitTime / customNum;
}