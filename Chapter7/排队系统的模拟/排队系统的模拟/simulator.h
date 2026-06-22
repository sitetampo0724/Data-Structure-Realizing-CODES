#pragma once
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;


class simulator {
	int noOfServer;
	int arrivalLow;
	int arrivalHigh;
	int serviceTimeLow;
	int serviceTimeHigh;
	int customNum;
	struct eventT {
		int time;
		int type; // 0 for arrival, 1 for departure
		bool operator > (const eventT& e) const
		{
			return time > e.time;
		}
		eventT() :time(0), type(0) {}
	};
public:
	simulator();
	int avgWaitTime();
};

simulator::simulator()
{
	srand(time(NULL));
	cout<<"Simulator initialized."<<endl;
	cout << "Enter the number of servers: ";
	cin >> noOfServer;
	cout << "Enter the arrival time range (low high): ";
	cin >> arrivalLow >> arrivalHigh;
	cout << "Enter the service time range (low high): ";
	cin >> serviceTimeLow >> serviceTimeHigh;
	cout << "Enter the number of customers: ";
	cin >> customNum;
}

int simulator::avgWaitTime()
{
	int serverBusy = 0;
	priority_queue<eventT,vector<eventT>,greater<eventT>> eventQueue;
	queue<eventT> waitQueue;
	int currentTime = 0;
	eventT currentEvent;
	int totalWaitTime = 0;
	for (int i = 0;i < customNum;i++)
	{
		currentEvent.time += arrivalLow + rand() % (arrivalHigh - arrivalLow + 1);
		eventQueue.push(currentEvent);
	}
	while (!eventQueue.empty())
	{
		currentEvent = eventQueue.top();
		eventQueue.pop();
		currentTime = currentEvent.time;
		switch (currentEvent.type)
		{
		case 0:
		{
			if (serverBusy != noOfServer) {
				serverBusy++;
				currentEvent.type = 1;
				currentEvent.time += serviceTimeLow + rand() % (serviceTimeHigh - serviceTimeLow + 1);
				eventQueue.push(currentEvent);
			}
			else waitQueue.push(currentEvent);
			break;
		}
		case 1:/*what is 1 referring to actually ?
			it means the customer has finished being 
			served and is leaving the system, so we 
			need to check if there are any customers waiting 
			in the queue to be served next.*/
		{
			if (!waitQueue.empty())
			{
				currentEvent = waitQueue.front();
				waitQueue.pop();
				totalWaitTime += currentTime - currentEvent.time;
				/*why currentTime - currentEvent.time ?
				beacause currentEvent.time is the arrival time
				of the customer, and currentTime is the time
				when the customer starts being served.
				The difference between these two times gives us
				the waiting time for that customer.*/
				currentEvent.type = 1;
				currentEvent.time += serviceTimeLow + rand() % (serviceTimeHigh - serviceTimeLow + 1);
				eventQueue.push(currentEvent);
			}
			else serverBusy--;
			break;
		}
		default: break;
		}
	}
	return totalWaitTime / customNum;
}