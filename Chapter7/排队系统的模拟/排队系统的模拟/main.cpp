#include "simulator.h"

int main(int argc,char * argv[])
{
	cout << argc << endl;
	for (int i = 0;i < argc;i++)
	{
		cout << argv[i] << endl;
	}
	simulator sim;
	cout << "Average waiting time: " << sim.avgWaitTime() << endl;
	return 0;
}