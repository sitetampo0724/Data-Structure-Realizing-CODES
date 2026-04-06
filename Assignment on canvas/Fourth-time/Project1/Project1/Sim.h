#pragma once
#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

class Sim {
	int CarNum, TruckNum;
	int CarLow;
	int CarHigh;
	int TrucksLow;
	int TrucksHigh;
public:
	Sim();
	~Sim() {};
	void Cal(int& carWait, int& truckWait);
};

Sim::Sim()
{
	cout << "Enter the number of cars and trucks: ";
	cin >> CarNum >> TruckNum;
	cout << "Enter the low and high values for cars and trucks: ";
	cin >> CarLow >> CarHigh >> TrucksLow >> TrucksHigh;
	srand(time(NULL));
}

void Sim::Cal(int& carWait, int& truckWait)
{
	queue<int> Car;
	queue<int> Truck;
	queue<int> Car_Waiting;
	queue<int> Truck_Waiting;
	int currenttime = 0;
	int eventtime;
	for (int i = 0;i < CarNum;i++)
	{
		currenttime += CarLow + rand() % (CarHigh - CarLow + 1);
		Car.push(currenttime);
	}
	currenttime = 0;
	for (int i = 0;i < TruckNum;i++)
	{
		currenttime += TrucksLow + rand() % (TrucksHigh - TrucksLow + 1);
		Truck.push(currenttime);
	}
	currenttime = 0;
	int boardtime = 10;
	while (!Car.empty() || !Truck.empty())
	{

		while (!Car.empty() && Car.front() <= currenttime)
		{
			Car_Waiting.push(Car.front());
			Car.pop();
		}
		while (!Truck.empty() && Truck.front() <= currenttime)
		{
			Truck_Waiting.push(Truck.front());
			Truck.pop();
		}
		if(currenttime>=boardtime)//boat is ready to board
		{
			int boarded = 0;
			int carboat = 0;
			while (boarded < 10)
			{
				if (!Car_Waiting.empty())
				{
					boarded += 1;
					carboat += 1;
					carWait += currenttime - Car_Waiting.front();
					Car_Waiting.pop();
					if (carboat % 4 == 0 && boarded < 10 && !Truck_Waiting.empty())
					{
						boarded += 1;
						truckWait += currenttime - Truck_Waiting.front();
						Truck_Waiting.pop();
					}
				}
				else if (!Truck_Waiting.empty())
				{
					boarded += 1;
					truckWait += currenttime - Truck_Waiting.front();
					Truck_Waiting.pop();
				}
				else break;
			}
			boardtime += 10;
		}
		int nextEvent = boardtime;
		if (!Car.empty())
			nextEvent = min(nextEvent, Car.front());
		if (!Truck.empty())
			nextEvent = min(nextEvent, Truck.front());
		currenttime = nextEvent;

	}
	carWait /= CarNum;
	truckWait /= TruckNum;
}