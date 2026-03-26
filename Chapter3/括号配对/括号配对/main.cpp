#include <iostream>
#include "Balance.h"
using namespace std;
int main()
{
	/*string file;*/
	cout << "input path of the file" << endl;
	/*cin >> file;*/
	try {
		balance* f=new balance("test.txt");//relative path way of opening a file
		int result = f->CheckBalance();
		cout << result << " errors in total" << endl;
		delete f;
	}
	catch (const noFile& e) { e.Error(); }
	return 0;
}
